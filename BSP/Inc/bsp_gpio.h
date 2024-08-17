/*
 * bsp_gpio.h
 *
 *  Created on: Jun 27, 2024
 *      Author: borto
 */

#ifndef INC_BSP_GPIO_H_
#define INC_BSP_GPIO_H_

#ifdef __cplusplus
extern "C"
{
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"
#include "stm32f4xx_ll_gpio.h"

#include <stdbool.h>

/* Defines -------------------------------------------------------------------*/
#define GPIOx_CLK_ENABLE(__INDEX__)     do{if((__INDEX__) == GPIOA) __HAL_RCC_GPIOA_CLK_ENABLE(); else \
                                           if((__INDEX__) == GPIOB) __HAL_RCC_GPIOB_CLK_ENABLE(); else \
                                           if((__INDEX__) == GPIOC) __HAL_RCC_GPIOC_CLK_ENABLE(); else \
                                           if((__INDEX__) == GPIOD) __HAL_RCC_GPIOD_CLK_ENABLE(); else \
                                           if((__INDEX__) == GPIOE) __HAL_RCC_GPIOE_CLK_ENABLE(); else \
                                           if((__INDEX__) == GPIOF) __HAL_RCC_GPIOF_CLK_ENABLE(); else \
                                           if((__INDEX__) == GPIOG) __HAL_RCC_GPIOG_CLK_ENABLE(); else \
                                           if((__INDEX__) == GPIOH) __HAL_RCC_GPIOH_CLK_ENABLE(); else \
                                           if((__INDEX__) == GPIOI) __HAL_RCC_GPIOI_CLK_ENABLE(); else \
                                           if((__INDEX__) == GPIOJ) __HAL_RCC_GPIOJ_CLK_ENABLE(); else \
                                           if((__INDEX__) == GPIOK) __HAL_RCC_GPIOK_CLK_ENABLE(); \
                                           }while(0)

#define LED0_Port	GPIOF
#define LED0_Pin	13
#define LED1_Port	GPIOF
#define LED1_Pin	14
#define LED2_Port	GPIOF
#define LED2_Pin	15
#define LED3_Port	GPIOG
#define LED3_Pin	0
#define LED4_Port	GPIOG
#define LED4_Pin	1

#define ENAOUT03_Port	GPIOE
#define ENAOUT03_Pin	10
#define ENAOUT04_Port	GPIOE
#define ENAOUT04_Pin	12

#define DIGOUT0_Port	GPIOE
#define DIGOUT0_Pin		9
#define DIGOUT0_TIMER 	TIM1
#define DIGOUT0_TIMER_CANAL 1
#define DIGOUT1_Port	GPIOE
#define DIGOUT1_Pin		11
#define DIGOUT1_TIMER 	TIM1
#define DIGOUT1_TIMER_CANAL 2
#define DIGOUT2_Port	GPIOE
#define DIGOUT2_Pin		13
#define DIGOUT2_TIMER 	TIM1
#define DIGOUT2_TIMER_CANAL 3
#define DIGOUT3_Port	GPIOE
#define DIGOUT3_Pin		14
#define DIGOUT3_TIMER 	TIM1
#define DIGOUT3_TIMER_CANAL 4
#define DIGOUT4_Port	GPIOE
#define DIGOUT4_Pin		5
#define DIGOUT4_TIMER 	TIM9
#define DIGOUT4_TIMER_CANAL 1
#define DIGOUT5_Port	GPIOE
#define DIGOUT5_Pin		6
#define DIGOUT5_TIMER 	TIM9
#define DIGOUT5_TIMER_CANAL 2
#define DIGOUT6_Port	GPIOF
#define DIGOUT6_Pin		8
#define DIGOUT6_TIMER 	TIM13
#define DIGOUT6_TIMER_CANAL 1
#define DIGOUT7_Port	GPIOF
#define DIGOUT7_Pin		9
#define DIGOUT7_TIMER 	TIM14
#define DIGOUT7_TIMER_CANAL 1

#define DIGIN_ACTIVE	false
#define DIGIN_INACTIVE  true

#define DIGIN1_Port		GPIOE
#define DIGIN1_Pin		7
#define DIGIN1_EXTI		LL_EXTI_LINE_7
#define DIGIN2_Port		GPIOE
#define DIGIN2_Pin		15
#define DIGIN2_EXTI		LL_EXTI_LINE_15
#define DIGIN3_Port		GPIOA
#define DIGIN3_Pin		15
#define DIGIN3_EXTI		LL_EXTI_LINE_15
#define DIGIN4_Port		GPIOB
#define DIGIN4_Pin		3
#define DIGIN4_EXTI		LL_EXTI_LINE_3

#define SW_ACTIVE		false
#define SW_INACTIVE		true

#define SW0_Port		GPIOD
#define SW0_Pin			10
#define SW0_EXTI		LL_EXTI_LINE_10
#define EXTI10_LINE

#define SW1_Port		GPIOD
#define SW1_Pin			11
#define SW1_EXTI		LL_EXTI_LINE_11
#define SW2_Port		GPIOD
#define SW2_Pin			12
#define SW2_EXTI		LL_EXTI_LINE_12
#define SW3_Port		GPIOD
#define SW3_Pin			13
#define SW3_EXTI		LL_EXTI_LINE_13

/* Typedef -------------------------------------------------------------------*/
typedef enum
{
	ENTRADA_NoPull = 0,
	ENTRADA_PullDown,
	ENTRADA_PullUp,
	SAIDA_OD,
	SAIDA_PP,
	ANALOGICO,
	ALTERNATIVO_OD,
	ALTERNATIVO_PP
} GPIO_Mode;

typedef enum
{
	BAIXO = 0,
	MEDIO,
	ALTO,
	MUITO_ALTO
} GPIO_Speed;


typedef struct
{
	GPIO_Mode modo;
	GPIO_Speed velocidade;
	uint8_t alternativo;
} GPIO_Config;


/* Protótipos de funções exportadas ------------------------------------------*/
void BSP_GPIO_Init(__IO GPIO_TypeDef *GPIOx, uint32_t Pin, const GPIO_Config *pinConfig);

void BSP_GPIO_WritePin(__IO GPIO_TypeDef *GPIOx, uint32_t Pin, bool Value);
void BSP_GPIO_WritePort(__IO GPIO_TypeDef *GPIOx, uint32_t Value);
void BSP_GPIO_SetPin(__IO GPIO_TypeDef *GPIOx, uint32_t Pin);
void BSP_GPIO_ResetPin(__IO GPIO_TypeDef *GPIOx, uint32_t Pin);
void BSP_GPIO_TogglePin(__IO GPIO_TypeDef *GPIOx, uint32_t Pin);

bool BSP_GPIO_ReadPin(__IO GPIO_TypeDef *GPIOx, uint32_t Pin);
uint32_t BSP_GPIO_ReadPort(__IO GPIO_TypeDef *GPIOx);

bool BSP_GPIO_ReadOutputPin(__IO GPIO_TypeDef *GPIOx, uint32_t Pin);
uint32_t BSP_GPIO_ReadOutputPort(__IO GPIO_TypeDef *GPIOx);


#ifdef __cplusplus
}
#endif

#endif /* INC_BSP_GPIO_H_ */
