/*
 * motor_bobina.c
 *
 *  Created on: Jul 16, 2024
 *      Author: João Bortolace
 *
 */

/* Includes ----------------------------------------------------------------------*/
#include "motor_bobina.h"

/* Defines -----------------------------------------------------------------------*/
#define KP_STD			(15U)
#define ERRO_DEATHZONE	(50U)

#define ADC_REF_ADDR	(0)
#define ADC_REF_STD		(2048U)
#define ADC_RES			(12)
#define ADC_MAX			((1 << ADC_RES) - 1)

#define DAC_RES			(12)
#define DAC_MAX			((1 << DAC_RES) - 1)

/* Variaveis ---------------------------------------------------------------------*/
static int32_t adc_ref = ADC_REF_STD;
static const int32_t kp = KP_STD;

/* Telemetria --------------------------------------------------------------------*/
#ifdef DEBUG
uint16_t adc_val;
uint16_t vel_val;
int32_t controle_val;
bool motor_bobina_enable;
bool motor_bobina_direcao;
#endif

/* Interrupções ------------------------------------------------------------------*/

/*
 *  Interrupção que ocorre para cada amostragem do ADC2
 *  Nela é determinado a direção e a velocidade do Motor da bobina
 */
static void Potenciometro_Tensao_Interruption(__I uint16_t adc_read)
{
	int32_t erro = adc_ref - (int32_t) adc_read;

	/* Desliga o motor caso pressionado o switch e também aplica uma zona morta */
	if ((BSP_GPIO_ReadPin(MOTOR_BOBINA_TURN_OFF_BUT_Port, MOTOR_BOBINA_TURN_OFF_BUT_Pin) == SW_ACTIVE) || (abs(erro) <= ERRO_DEATHZONE))
	{
		BSP_GPIO_ResetPin(MOTOR_BOBINA_ENABLE_Port, MOTOR_BOBINA_ENABLE_Pin);
		erro = 0;
	}
	else
	{
		BSP_GPIO_SetPin(MOTOR_BOBINA_ENABLE_Port, MOTOR_BOBINA_ENABLE_Pin);
		erro = (erro >= 0 ? erro - ERRO_DEATHZONE : erro + ERRO_DEATHZONE); /* Retira o degrau devido a zona morta */
	}

	/* Controle P */
	int32_t controle = kp * erro;
	int32_t vel_dac = abs(controle);

	/* Limita o valor para o máximo do DAC */
	BSP_DAC_SetValue(DAC, MOTOR_BOBINA_DAC_ALIGN, MOTOR_BOBINA_DAC_CHANNEL, vel_dac > DAC_MAX ? DAC_MAX : vel_dac);
	/* Caso o valor seja positivo, seta a direção CLOCK_WISE */
	controle >= 0 ? MOTOR_BOBINA_DIR_SET_CLOCKWISE : MOTOR_BOBINA_DIR_SET_COUNTER_CLOCKWISE;

	/* Ajuste do ponto de referência */
	if (BSP_GPIO_ReadPin(MOTOR_BOBINA_SET_REF_Port, MOTOR_BOBINA_SET_REF_Pin) == SW_ACTIVE)
	{
		adc_ref = adc_read;
	}

#ifdef DEBUG
	adc_val = adc_read;
	controle_val = controle;
	vel_val = vel_dac;
	motor_bobina_direcao = BSP_GPIO_ReadOutputPin(MOTOR_BOBINA_DIR_Port, MOTOR_BOBINA_DIR_Pin);
	motor_bobina_enable = BSP_GPIO_ReadOutputPin(MOTOR_BOBINA_ENABLE_Port, MOTOR_BOBINA_ENABLE_Pin);
#endif
}

/*
 *  Interrupção que ocorre na borda de subida do botão de setar o valor de referência
 *  O valor é armazenado na memória para que na próxima execução seja recarregado
 *  Esta interrupção é demorada, não se deve utiliza-la com frequência, nem com OS
 */
static void MOTOR_BOBINA_SET_REF_Interruption(void)
{
	if (BSP_Write_Flash_Word(ADC_REF_ADDR, adc_ref) != HAL_OK)
	{
		BSP_Error_Handler();
	}
}

void Motor_Bobina_Init(void)
{
  	/* Configura o pino de direção do motor da bobina */
	GPIO_Config pinConfig = {0};
	pinConfig.velocidade = ALTO;
  	pinConfig.modo = SAIDA_PP;
  	BSP_GPIO_Init(MOTOR_BOBINA_DIR_Port, MOTOR_BOBINA_DIR_Pin, &pinConfig);
  	BSP_GPIO_Init(MOTOR_BOBINA_ENABLE_Port, MOTOR_BOBINA_ENABLE_Pin, &pinConfig);

  	pinConfig.modo = ENTRADA_NoPull;
  	BSP_GPIO_Init(MOTOR_BOBINA_TURN_OFF_BUT_Port, MOTOR_BOBINA_TURN_OFF_BUT_Pin, &pinConfig);

  	/* Configura o TIMER de disparo do conversor A/D */
  	TIM_Config timConfig = {0};
  	timConfig.TIMx = TIM3;
  	/*
  	 * A placa possuí um filtro passa-baixas de primeira ordem com frequência de corte de 1.6kHz nas entradas do A/D
  	 * Definido uma frequência de 4.8kHz de amostragem para evitar rebatimento devido as frequência que não são totalmente eliminadas pelo filtro
  	 * ADC_CLK = TIM3_CLK = 90MHz / (3750*5*1) =  4.8kHz
  	 */
  	timConfig.ClkDiv = Div_1;
  	timConfig.Prescaler = 3750-1;
  	timConfig.Counter = 5;
  	timConfig.DownCounter = false;
  	timConfig.preload = true;
  	timConfig.onePulseMode = false;
  	timConfig.triggerGeneration = true;
  	timConfig.interrupcaoEnable = false;
  	BSP_TIM_Init(3, &timConfig);

  	/* Carrega o valor de referência salvo na memória */
  	const int32_t adc_ref_flash = (int32_t) BSP_Read_Flash_Word(ADC_REF_ADDR);

  	if (adc_ref_flash < 0 || adc_ref_flash > ADC_MAX) /* Caso a leitura seja falha */
  	{
  		adc_ref = ADC_REF_STD;
  	}
  	else
  	{
  		adc_ref = adc_ref_flash;
  	}

  	/* Configura o A/D para amostragem da tensão do cabo */
  	__IO GPIO_TypeDef *GPIOs[1] = {POT_TENSAO_MOTOR_Port};
  	uint8_t Pinos[1] = {POT_TENSAO_MOTOR_Pin};
  	uint8_t Canais[1] = {POT_TENSAO_MOTOR_CANAL};
  	uint8_t tempoAmostragem[1] = {POT_TENSAO_MOTOR_AMOSTRAGEM};

  	ADC_Config adcConfig = {0};
  	adcConfig.ADCx = POT_TENSAO_MOTOR_ADC;
  	adcConfig.numCanais = 1;
  	adcConfig.Canal = Canais;
  	adcConfig.GPIOx = GPIOs;
  	adcConfig.Pin = Pinos;
  	adcConfig.tempoAmostragem = tempoAmostragem;
  	adcConfig.interrupcaoEnable = true;
  	adcConfig.FuncaoInterrupcao = &Potenciometro_Tensao_Interruption;
  	adcConfig.resolucao = Bits_12;
  	adcConfig.alinhamento = ALINHADO_DIREITA;
  	adcConfig.modo = Discontinuo;
  	adcConfig.numDisc = 1;
  	adcConfig.prescaler = DIV_4;
  	adcConfig.ScanEnable = false;
  	adcConfig.triggerExterno = Rising_Edge;
  	adcConfig.fonteTrigger = TIMER3_TRGO_Event;
  	BSP_ADC_Init(&adcConfig);

  	/* Configura o DAC para controle de velocidade */
  	DAC_Config dacConfig = {0};
  	dacConfig.DACx = DAC;
  	dacConfig.triggerEnable = false;
  	dacConfig.bufferEnable = false;
  	dacConfig.dmaEnable = false;
  	BSP_DAC_Init(&dacConfig, DAC_CANAL_1);

  	/* Configura a interrupção do armazenamento do valor de referência */
  	EXTI_Config extiConfig = {0};
  	extiConfig.Trigger = RisingEdge;
  	extiConfig.ExtiLine = MOTOR_BOBINA_SET_REF_EXTI;
  	extiConfig.GPIOx = MOTOR_BOBINA_SET_REF_Port;
  	extiConfig.Pin = MOTOR_BOBINA_SET_REF_Pin;
  	extiConfig.Pull = No_Pull;
  	extiConfig.FuncaoInterrupcao = &MOTOR_BOBINA_SET_REF_Interruption;
  	BSP_EXTI_Init(&extiConfig);
}
