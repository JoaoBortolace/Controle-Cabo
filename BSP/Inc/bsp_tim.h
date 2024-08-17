/*
 * bsp_tim.h
 *
 *  Created on: Jul 3, 2024
 *      Author: borto
 */

#ifndef INC_BSP_TIM_H_
#define INC_BSP_TIM_H_

#ifdef __cplusplus
extern "C"
{
#endif

/* Includes -------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"
#include "stm32f4xx_ll_tim.h"

#include <stdbool.h>

/* Defines -------------------------------------------------------------------*/
#define TIMx_CLK_ENABLE(__INDEX__)     	do{if((__INDEX__) == TIM1) __HAL_RCC_TIM1_CLK_ENABLE(); else \
                                           if((__INDEX__) == TIM2) __HAL_RCC_TIM2_CLK_ENABLE(); else \
                                           if((__INDEX__) == TIM3) __HAL_RCC_TIM3_CLK_ENABLE(); else \
                                           if((__INDEX__) == TIM4) __HAL_RCC_TIM4_CLK_ENABLE(); else \
                                           if((__INDEX__) == TIM5) __HAL_RCC_TIM5_CLK_ENABLE(); else \
                                           if((__INDEX__) == TIM6) __HAL_RCC_TIM6_CLK_ENABLE(); else \
                                           if((__INDEX__) == TIM7) __HAL_RCC_TIM7_CLK_ENABLE(); else \
                                           if((__INDEX__) == TIM8) __HAL_RCC_TIM8_CLK_ENABLE(); else \
                                           if((__INDEX__) == TIM9) __HAL_RCC_TIM9_CLK_ENABLE(); else \
                                           if((__INDEX__) == TIM10) __HAL_RCC_TIM10_CLK_ENABLE(); else \
                                           if((__INDEX__) == TIM11) __HAL_RCC_TIM11_CLK_ENABLE(); else \
                                           if((__INDEX__) == TIM12) __HAL_RCC_TIM12_CLK_ENABLE(); else \
                                           if((__INDEX__) == TIM13) __HAL_RCC_TIM13_CLK_ENABLE(); else \
                                           if((__INDEX__) == TIM14) __HAL_RCC_TIM14_CLK_ENABLE(); \
                                           }while(0)

#define NUMBER_TIMERS 14

/* TypeDef -------------------------------------------------------------------*/
typedef enum
{
	Div_1 = 0,
	Div_2,
	Div_4
} TIM_ClkDiv;

typedef struct
{
	__IO TIM_TypeDef *TIMx;
	TIM_ClkDiv ClkDiv;
	uint16_t Prescaler;
	uint16_t Counter;

	bool DownCounter;
	bool preload;
	bool onePulseMode;
	bool UpRequest;
	bool UpDisable;
	bool triggerGeneration;
	bool interrupcaoEnable;
	void *FuncaoInterrupcao;
} TIM_Config;


/* Protótipos de funções exportadas ------------------------------------------*/
void BSP_TIM_Init(uint8_t timer, const TIM_Config *timConfig);


#ifdef __cplusplus
}
#endif

#endif /* INC_BSP_TIM_H_ */
