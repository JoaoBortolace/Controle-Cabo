/*
 * bsp_adc.c
 *
 *  Created on: Jul 3, 2024
 *      Author: borto
 */

/* Includes ------------------------------------------------------------------*/
#include "bsp_adc.h"
#include "bsp.h"

#if defined(ADC1_Interrupt) || defined(ADC2_Interrupt) || defined(ADC3_Interrupt)
static void (*interruptions[3])(__I uint16_t) = {NULL};
#endif


void BSP_ADC_Init(const ADC_Config *adcConfig)
{
	if (adcConfig->ADCx != ADC1 && adcConfig->ADCx != ADC2 && adcConfig->ADCx != ADC3)
	{
		BSP_Error_Handler();
	}

	ADCx_CLK_ENABLE(adcConfig->ADCx);

	/* Configura a Resolução */
	if (adcConfig->resolucao > Bits_6 || adcConfig->resolucao < Bits_12)
	{
		BSP_Error_Handler();
	}

	adcConfig->ADCx->CR1 &= ~(3U << ADC_CR1_RES_Pos);
	adcConfig->ADCx->CR1 |= ((uint8_t) adcConfig->resolucao << ADC_CR1_RES_Pos);


	/* Configura a Interrupção */
	if (adcConfig->interrupcaoEnable)
	{
		adcConfig->ADCx->CR1 |= ADC_CR1_EOCIE;
		NVIC_EnableIRQ(ADC_IRQn);

#if defined(ADC1_Interrupt) || defined(ADC2_Interrupt) || defined(ADC3_Interrupt)
		if (adcConfig->ADCx == ADC1)
		{
			interruptions[0] = adcConfig->FuncaoInterrupcao;
		}
		else if (adcConfig->ADCx == ADC2)
		{
			interruptions[1] = adcConfig->FuncaoInterrupcao;
		}
		else
		{
			interruptions[2] = adcConfig->FuncaoInterrupcao;
		}
#endif
	}

	/* Configura a se há trigger externo */
	adcConfig->ADCx->CR2 &= ~(3U << ADC_CR2_EXTEN_Pos);
	adcConfig->ADCx->CR2 |= ((uint8_t) adcConfig->triggerExterno << ADC_CR2_EXTEN_Pos);

	/* Configura a fonte do triggerExterno */
	if (adcConfig->fonteTrigger == 0xD || adcConfig->fonteTrigger == 0xE)
	{
		BSP_Error_Handler();
	}

	adcConfig->ADCx->CR2 &= ~(0xF << ADC_CR2_EXTSEL_Pos);
	adcConfig->ADCx->CR2 |= ((uint8_t) adcConfig->fonteTrigger << ADC_CR2_EXTSEL_Pos);

	/* Configura o alinhamento */
	adcConfig->ADCx->CR2 &= ~(1 << ADC_CR2_ALIGN_Pos);
	adcConfig->ADCx->CR2 |= ((uint8_t) adcConfig->alinhamento << ADC_CR2_ALIGN_Pos);

	/* Configura o modo */
	switch (adcConfig->modo)
	{
		case Discontinuo:
			adcConfig->ADCx->CR1 &= ~(0x7 << ADC_CR1_DISCNUM_Pos) & ~ADC_CR2_CONT;
			adcConfig->ADCx->CR1 |= ((adcConfig->numDisc -1) << ADC_CR1_DISCNUM_Pos) | ADC_CR1_DISCEN;
			break;

		case Continuo:
			adcConfig->ADCx->CR1 &= ~ADC_CR1_DISCEN;
			adcConfig->ADCx->CR2 |= ADC_CR2_CONT;
			break;

		default: /* Discontinuo */
			adcConfig->ADCx->CR1 &= ~(0x7 << ADC_CR1_DISCNUM_Pos) & ~ADC_CR2_CONT;
			adcConfig->ADCx->CR1 |= ((adcConfig->numCanais -1) << ADC_CR1_DISCNUM_Pos) | ADC_CR1_DISCEN;
			break;
	}

	/* Configura o modo Scan */
	if (adcConfig->ScanEnable)
	{
		adcConfig->ADCx->CR1 |= ADC_CR1_SCAN;
		adcConfig->ADCx->CR2 |= ADC_CR2_EOCS;
	}
	else
	{
		adcConfig->ADCx->CR1 &= ~ADC_CR1_SCAN;
		adcConfig->ADCx->CR2 &= ~ADC_CR2_EOCS;
	}


	/* Configurações dos canais */
	if (adcConfig->numCanais > 16)
	{
		BSP_Error_Handler();
	}

	GPIO_Config pinConfig = {0};
	pinConfig.modo = ANALOGICO;
	pinConfig.velocidade = ALTO;
	/* Configura o número de canais */
	adcConfig->ADCx->SQR1 &= ~(1111 << ADC_SQR1_L_Pos);
	adcConfig->ADCx->SQR1 |= ((uint8_t) adcConfig->numCanais << ADC_SQR1_L_Pos);

	for (uint8_t i = 0; i < adcConfig->numCanais; i++)
	{
		/* Configura o Pino como analógico */
		BSP_GPIO_Init(adcConfig->GPIOx[i], adcConfig->Pin[i], &pinConfig);

		/* Configura o tempo de amostragem do canal */
		if (adcConfig->Canal[i] < 9)
		{
			adcConfig->ADCx->SMPR2 &= ~(111 << adcConfig->Canal[i]*3U);
			adcConfig->ADCx->SMPR2 |=  ((uint8_t) adcConfig->tempoAmostragem[i] << adcConfig->Canal[i]*3U);
		}
		else if (adcConfig->Canal[i] > 9 && adcConfig->Canal[i] <= 18)
		{
			adcConfig->ADCx->SMPR1 &= ~(111 << (adcConfig->Canal[i] - 10)*3U);
			adcConfig->ADCx->SMPR1 |=  ((uint8_t) adcConfig->tempoAmostragem[i] << (adcConfig->Canal[i] - 10)*3U);
		}
		else
		{
			BSP_Error_Handler();
		}

		/* Configura a ordem de amostragem */
		if (i < 6)
		{
			adcConfig->ADCx->SQR3 |= ((uint8_t) adcConfig->Canal[i] << i*5U);
		}
		else if (i >= 6 && i < 12)
		{
			adcConfig->ADCx->SQR2 |= ((uint8_t) adcConfig->Canal[i] << (i - 6)*5U);
		}
		else
		{
			adcConfig->ADCx->SQR1 |= ((uint8_t) adcConfig->Canal[i] << (i - 12)*5U);
		}
	}

	/* Configura o prescaler */
	ADC->CCR |= ((uint8_t) adcConfig->prescaler << ADC_CCR_ADCPRE_Pos);

	/* Habilita o ADC */
	adcConfig->ADCx->CR2 |= ADC_CR2_ADON;
}

void BSP_ADC_Start(__IO ADC_TypeDef *ADCx)
{
	ADCx->CR2 |= ADC_CR2_SWSTART;
}

void BSP_ADC_Read(__IO ADC_TypeDef *ADCx, uint16_t *adcRead)
{
	while (!(ADCx->SR &  ADC_SR_EOC)) /* Enquanto a flag de fim de conversão não estiver setada */
	{
		if (!(ADCx->SR & ADC_SR_STRT)) /* Caso não haja conversão em andamento */
		{
			return;
		}
	}

	ADCx->SR &= ~ADC_SR_STRT;
	*adcRead = ADCx->DR;
}

#if defined(ADC1_Interrupt) || defined(ADC2_Interrupt) || defined(ADC3_Interrupt)
void ADC_IRQHandler(void)
{
#ifdef ADC1_Interrupt
	if (ADC1->SR & ADC_SR_EOC && interruptions[0] != NULL)
	{
		(*interruptions[0])(ADC1->DR);
	}
#endif
#ifdef ADC2_Interrupt
	if (ADC2->SR & ADC_SR_EOC && interruptions[1] != NULL)
	{
		(*interruptions[1])(ADC2->DR);
	}
#endif
#ifdef ADC3_Interrupt
	if (ADC3->SR & ADC_SR_EOC && interruptions[2] != NULL)
	{
		(*interruptions[2])(ADC3->DR);
	}
#endif
}
#endif
