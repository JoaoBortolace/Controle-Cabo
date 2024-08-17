/*
 * bsp_extInt.h
 *
 *  Created on: Jun 27, 2024
 *      Author: borto
 */

#ifndef INC_BSP_EXTINT_H_
#define INC_BSP_EXTINT_H_

#ifdef __cplusplus
extern "C"
{
#endif

/* Includes -------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"
#include "stm32f4xx_ll_exti.h"

/* Typedef --------------------------------------------------------------------*/
typedef enum
{
	RisingEdge = 0,
	FallingEdge,
	BothEdge
} EXTI_Trigger;

typedef enum
{
	No_Pull = 0,
	Pull_UP,
	Pull_Down,
} GPIO_Pull;

typedef struct
{
	uint32_t ExtiLine;
	__IO GPIO_TypeDef *GPIOx;
	GPIO_Pull Pull;
	uint32_t Pin;
	EXTI_Trigger Trigger;
	void *FuncaoInterrupcao;
} EXTI_Config;

/* Protótipos de funções exportadas ------------------------------------------*/
void BSP_EXTI_Init(const EXTI_Config *extiConfig);


#ifdef __cplusplus
}
#endif

#endif /* INC_BSP_EXTINT_H_ */
