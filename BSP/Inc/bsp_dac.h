/*
 * bsp_dac.h
 *
 *  Created on: Jul 5, 2024
 *      Author: João Bortolace
 */

#ifndef INC_BSP_DAC_H_
#define INC_BSP_DAC_H_

#ifdef __cplusplus
extern "C"
{
#endif


/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"
#include "stm32f4xx_ll_dac.h"

#include <stdbool.h>

#include "bsp_adc.h"

/* Defines -------------------------------------------------------------------*/
#define DACx_CLK_ENABLE      	__HAL_RCC_DAC_CLK_ENABLE()

#define DAC_TIMER6_TRGO_Event 	(0x0)
#define DAC_TIMER8_TRGO_Event	(0x1)
#define DAC_TIMER7_TRGO_Event 	(0x2)
#define DAC_TIMER5_TRGO_Event	(0x3)
#define DAC_TIMER2_TRGO_Event 	(0x4)
#define DAC_TIMER4_TRGO_Event	(0x5)
#define DAC_EXTI9_Event			(0x6)
#define DAC_SWTRIG				(0x7)

#define DAC_CHANNEL_1_Port		GPIOA
#define DAC_CHANNEL_1_Pin		4
#define DAC_CHANNEL_2_Port		GPIOA
#define DAC_CHANNEL_2_Pin		5

#define DAC_CANAL_1				LL_DAC_CHANNEL_1
#define DAC_CANAL_2				LL_DAC_CHANNEL_2

/* TypeDef -------------------------------------------------------------------*/
typedef enum
{
	bit12_Esquerda = 0,
	bit12_Direita,
	bit8
} DAC_Mode;

typedef struct
{
	__IO DAC_TypeDef *DACx;

	bool triggerEnable;
	uint32_t trigger;
	bool bufferEnable;
	bool dmaEnable;
} DAC_Config;

/* Protótipos de funções exportadas ------------------------------------------*/
void BSP_DAC_Init(const DAC_Config *dacConfig, uint32_t Canal);

void BSP_DAC_SetValue(DAC_TypeDef *DACx, DAC_Mode Mode, uint32_t Canal, uint16_t Value);
void BSP_DAC_PutValue(DAC_TypeDef *DACx, uint32_t Canal);
uint16_t BSP_DAC_GetValue(__IO DAC_TypeDef *DACx, uint32_t Canal);

#ifdef __cplusplus
}
#endif /* extern "c" */

#endif /* INC_BSP_DAC_H_ */
