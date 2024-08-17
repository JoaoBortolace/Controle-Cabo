/*
 * bsp_dac.c
 *
 *  Created on: Jul 5, 2024
 *      Author: João Bortolace
 */

/* Includes ------------------------------------------------------------------*/
#include "bsp_dac.h"
#include "bsp.h"

void BSP_DAC_Init(const DAC_Config *dacConfig, uint32_t Canal)
{
	DACx_CLK_ENABLE;

	GPIO_Config pinConfig = {0};
	pinConfig.modo = ANALOGICO;

	if (Canal == DAC_CANAL_1)
	{
		BSP_GPIO_Init(DAC_CHANNEL_1_Port, DAC_CHANNEL_1_Pin, &pinConfig);

		if (dacConfig->trigger > 0x7)
		{
			dacConfig->DACx->CR |= 0x7 << DAC_CR_TSEL1_Pos;
		}
		else
		{
			dacConfig->DACx->CR |= dacConfig->trigger << DAC_CR_TSEL1_Pos;
		}

		dacConfig->DACx->CR |= DAC_CR_EN1 | (dacConfig->bufferEnable << DAC_CR_BOFF1_Pos)
							| (dacConfig->dmaEnable << DAC_CR_DMAEN1_Pos)
							| (dacConfig->triggerEnable << DAC_CR_TEN1_Pos);
	}
	else if (Canal == DAC_CANAL_2)
	{
		BSP_GPIO_Init(DAC_CHANNEL_2_Port, DAC_CHANNEL_2_Pin, &pinConfig);

		if (dacConfig->trigger > 0x7)
		{
			dacConfig->DACx->CR |= 0x7 << DAC_CR_TSEL2_Pos;
		}
		else
		{
			dacConfig->DACx->CR |= dacConfig->trigger << DAC_CR_TSEL2_Pos;
		}

		dacConfig->DACx->CR |= DAC_CR_EN2 | (dacConfig->bufferEnable << DAC_CR_BOFF2_Pos)
							| (dacConfig->dmaEnable << DAC_CR_DMAEN2_Pos)
							| (dacConfig->triggerEnable << DAC_CR_TEN2_Pos);
	}
	else
	{
		BSP_Error_Handler();
	}
}

void BSP_DAC_SetValue(DAC_TypeDef *DACx, DAC_Mode Mode, uint32_t Canal, uint16_t Value)
{
	switch (Mode)
	{
		case bit12_Esquerda:
			LL_DAC_ConvertData12LeftAligned(DACx, Canal, Value);
			break;
		case bit12_Direita:
			LL_DAC_ConvertData12RightAligned(DACx, Canal, Value);
			break;
		case bit8:
			LL_DAC_ConvertData8RightAligned(DACx, Canal, Value);
			break;
		default:
			BSP_Error_Handler();
			break;
	}
}

void BSP_DAC_SetValueDualChannel(DAC_TypeDef *DACx, DAC_Mode Mode, uint16_t Value_1, uint16_t Value_2)
{
	switch (Mode)
	{
		case bit12_Esquerda:
			LL_DAC_ConvertDualData12LeftAligned(DACx, Value_1, Value_2);
			break;
		case bit12_Direita:
			LL_DAC_ConvertDualData12RightAligned(DACx, Value_1, Value_2);
			break;
		case bit8:
			LL_DAC_ConvertDualData8RightAligned(DACx, Value_1, Value_2);
			break;
		default:
			BSP_Error_Handler();
			break;
	}
}

void BSP_DAC_PutValue(DAC_TypeDef *DACx, uint32_t Canal)
{
	LL_DAC_TrigSWConversion(DACx, Canal);
}


uint16_t BSP_DAC_GetValue(__IO DAC_TypeDef *DACx, uint32_t Canal)
{
	if (Canal == DAC_CANAL_1)
	{
		return DACx->DOR1;
	}
	else if (Canal == DAC_CANAL_2)
	{
		return DACx->DOR2;
	}

	return 0;
}
