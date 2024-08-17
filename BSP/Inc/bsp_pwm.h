/*
 * bsp_pwm.h
 *
 *  Created on: Jul 2, 2024
 *      Author: João Bortolace
 */

#ifndef INC_BSP_PWM_H_
#define INC_BSP_PWM_H_

#ifdef __cplusplus
extern "C"
{
#endif

/* Includes -------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"
#include "stm32f4xx_ll_tim.h"

/* TypeDef -------------------------------------------------------------------*/
typedef enum
{
	PWM_1 = 1,
	PWM_2,
	PWM_3,
	PWM_4
} PWM_CHANNEL;

typedef struct
{
	__IO GPIO_TypeDef *GPIOx;
	uint32_t Pin;
	uint16_t Prescaler;
	uint16_t Counter;
} PWM_Config;

typedef struct
{
	__IO TIM_TypeDef *TIMx;
	PWM_CHANNEL channel;
} PWM;

/* Protótipos de funções exportadas ------------------------------------------*/
void BSP_PWM_Init(PWM *pwm, PWM_Config *pwmConfig);

void BSP_PWM_SetDuty(PWM *pwm, uint8_t dutyPorcentagem);

#ifdef __cplusplus
}
#endif

#endif /* INC_BSP_PWM_H_ */
