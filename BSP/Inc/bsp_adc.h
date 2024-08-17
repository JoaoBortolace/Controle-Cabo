/*
 * bsp_adc.h
 *
 *  Created on: Jul 3, 2024
 *      Author: borto
 */

#ifndef INC_BSP_ADC_H_
#define INC_BSP_ADC_H_

#ifdef __cplusplus
extern "C"
{
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"
#include "stm32f4xx_ll_adc.h"

#include <stdbool.h>

/* Defines -------------------------------------------------------------------*/
#define ADCx_CLK_ENABLE(__INDEX__)      do{if((__INDEX__) == ADC1) __HAL_RCC_ADC1_CLK_ENABLE(); else \
                                           if((__INDEX__) == ADC2) __HAL_RCC_ADC2_CLK_ENABLE(); else \
                                           if((__INDEX__) == ADC3) __HAL_RCC_ADC3_CLK_ENABLE(); \
                                           }while(0)

#define TIMER1_CC1_Event 	(0x0)
#define TIMER1_CC2_Event 	(0x1)
#define TIMER1_CC3_Event 	(0x2)
#define TIMER2_CC2_Event 	(0x3)
#define TIMER2_CC3_Event 	(0x4)
#define TIMER2_CC4_Event 	(0x5)
#define TIMER2_TRGO_Event 	(0x6)
#define TIMER3_CC1_Event 	(0x7)
#define TIMER3_TRGO_Event	(0x8)
#define TIMER4_CC4_Event 	(0x9)
#define TIMER5_CC1_Event	(0xA)
#define TIMER5_CC2_Event	(0xB)
#define TIMER5_CC3_Event	(0xC)
#define EXTI11_Event		(0xF)

#define ADC2_IN6_CHANNEL	6
#define ADC2_IN6_Port 		GPIOA
#define ADC2_IN6_Pin  		6

#define ADC2_IN10_CHANNEL	10
#define ADC2_IN10_Port 		GPIOC
#define ADC2_IN10_Pin  		0

#define ADC3_IN4_CHANNEL	4
#define ADC3_IN4_Port 		GPIOF
#define ADC3_IN4_Pin  		GPIO_PIN_6

#define ADC3_IN5_CHANNEL	5
#define ADC3_IN5_Port 		GPIOF
#define ADC3_IN5_Pin  		7

#define ADC3_IN8_CHANNEL	8
#define ADC3_IN8_Port 		GPIOF
#define ADC3_IN8_Pin  		10

#define ADC3_IN9_CHANNEL	9
#define ADC3_IN9_Port 		GPIOF
#define ADC3_IN9_Pin  		3

#define ADC3_IN14_CHANNEL	14
#define ADC3_IN14_Port 		GPIOF
#define ADC3_IN14_Pin  		4


/* TypeDef -------------------------------------------------------------------*/
typedef enum
{
	Bits_12 = 0,
	Bits_10,
	Bits_8,
	Bits_6
} ADC_Resolution;

typedef enum
{
	ALINHADO_DIREITA = 0,
	ALINHADO_ESQUERDA
} ADC_Align;

typedef enum
{
	Disabilitado = 0,
	Rising_Edge,
	Falling_Edge,
	Both_Edge
} ADC_ExtTrigger;

typedef enum
{
	DIV_2 = 0,
	DIV_4,
	DIV_6,
	DIV_8
} ADC_Prescaler;

typedef enum
{
	Cycles_3 = 0,
	Cycles_15,
	Cycles_28,
	Cycles_56,
	Cycles_84,
	Cycles_112,
	Cycles_144,
	Cycles_480
} ADC_SampleTime;

typedef enum
{
	Discontinuo = 0,
	Continuo,
	Scan
} ADC_Mode;

typedef struct
{
	__IO ADC_TypeDef *ADCx;
	ADC_Resolution resolucao;
	ADC_Align alinhamento;
	ADC_Mode modo;
	uint8_t numDisc;
	bool ScanEnable;
	ADC_Prescaler prescaler;

	ADC_ExtTrigger triggerExterno;
	uint8_t fonteTrigger;

	bool interrupcaoEnable;
	void *FuncaoInterrupcao;

	uint8_t numCanais;
	__IO GPIO_TypeDef **GPIOx;
	uint8_t	*Pin;
	uint8_t *Canal;
	ADC_SampleTime *tempoAmostragem;
} ADC_Config;

/* Protótipos de funções exportadas ------------------------------------------*/
void BSP_ADC_Init(const ADC_Config *adcConfig);

void BSP_ADC_Start(__IO ADC_TypeDef *ADCx);
void BSP_ADC_Read(__IO ADC_TypeDef *ADCx, uint16_t *adcRead);

#ifdef __cplusplus
}
#endif

#endif /* INC_BSP_ADC_H_ */
