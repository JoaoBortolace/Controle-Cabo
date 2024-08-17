/*
 * bsp_pwm.c
 *
 *  Created on: Jul 2, 2024
 *      Author: João Bortolace
 */

/* Includes ------------------------------------------------------------------*/
#include "bsp_pwm.h"
#include "bsp.h"


void BSP_PWM_Init(PWM *pwm, PWM_Config *pwmConfig)
{
	TIMx_CLK_ENABLE(pwm->TIMx);

	/* Pare os timers quando estiver em DEBUG */
#ifdef DEBUG
	DBGMCU->APB1FZ |= DBGMCU_APB1_FZ_DBG_TIM2_STOP | DBGMCU_APB1_FZ_DBG_TIM3_STOP | DBGMCU_APB1_FZ_DBG_TIM4_STOP | DBGMCU_APB1_FZ_DBG_TIM5_STOP | DBGMCU_APB1_FZ_DBG_TIM6_STOP
					| DBGMCU_APB1_FZ_DBG_TIM7_STOP | DBGMCU_APB1_FZ_DBG_TIM12_STOP | DBGMCU_APB1_FZ_DBG_TIM13_STOP | DBGMCU_APB1_FZ_DBG_TIM14_STOP;

	DBGMCU->APB2FZ |= DBGMCU_APB2_FZ_DBG_TIM1_STOP | DBGMCU_APB2_FZ_DBG_TIM8_STOP | DBGMCU_APB2_FZ_DBG_TIM9_STOP | DBGMCU_APB2_FZ_DBG_TIM10_STOP | DBGMCU_APB2_FZ_DBG_TIM11_STOP;
#endif

	GPIO_Config pinConfig = {0};
	pinConfig.modo = ALTERNATIVO_PP;
	pinConfig.velocidade = MUITO_ALTO;

	if(pwm->TIMx == TIM1 || pwm->TIMx == TIM2)
	{
		pinConfig.alternativo = 1U;
	}
	else if (pwm->TIMx == TIM3 || pwm->TIMx == TIM4 || pwm->TIMx == TIM5)
	{
		pinConfig.alternativo = 2U;
	}
	else if (pwm->TIMx == TIM8 || pwm->TIMx == TIM9 || pwm->TIMx == TIM10 || pwm->TIMx == TIM11)
	{
		pinConfig.alternativo = 3U;
	}
	else
	{
		BSP_Error_Handler();
	}

	BSP_GPIO_Init(pwmConfig->GPIOx, pwmConfig->Pin, &pinConfig);

	pwm->TIMx->ARR = pwmConfig->Counter;
	pwm->TIMx->PSC = pwmConfig->Prescaler;
	pwm->TIMx->CR1 |= TIM_CR1_CEN | TIM_CR1_ARPE;

	switch (pwm->channel)
	{
		case PWM_1:
			pwm->TIMx->CCMR1 |= (110 << TIM_CCMR1_OC1M_Pos);
			pwm->TIMx->CCMR1 &= ~(11 << TIM_CCMR1_CC1S_Pos) & ~TIM_CCMR1_OC1PE;
			pwm->TIMx->CCR1 = 0;
			pwm->TIMx->CCER |= TIM_CCER_CC1E;
			break;
		case PWM_2:
			pwm->TIMx->CCMR1 |= (110 << TIM_CCMR1_OC2M_Pos);
			pwm->TIMx->CCMR1 &= ~(11 << TIM_CCMR1_CC2S_Pos) & ~TIM_CCMR1_OC2PE;
			pwm->TIMx->CCR2 = 0;
			pwm->TIMx->CCER |= TIM_CCER_CC2E;
			break;
		case PWM_3:
			pwm->TIMx->CCMR2 |= (110 << TIM_CCMR2_OC3M_Pos);
			pwm->TIMx->CCMR2 &= ~(11 << TIM_CCMR2_CC3S_Pos) & ~TIM_CCMR2_OC3PE;
			pwm->TIMx->CCR3 = 0;
			pwm->TIMx->CCER |= TIM_CCER_CC3E;
			break;
		case PWM_4:
			pwm->TIMx->CCMR2 |= (110 << TIM_CCMR2_OC4M_Pos);
			pwm->TIMx->CCMR2 &= ~(11 << TIM_CCMR2_CC4S_Pos) & ~TIM_CCMR2_OC4PE;
			pwm->TIMx->CCR4 = 0;
			pwm->TIMx->CCER |= TIM_CCER_CC4E;
			break;
		default:
			BSP_Error_Handler();
			break;
	}

	if (pwm->TIMx == TIM1 || pwm->TIMx == TIM8)
	{
		pwm->TIMx->BDTR |= TIM_BDTR_MOE;
	}
}

void BSP_PWM_SetDuty(PWM *pwm, uint8_t dutyPorcentagem)
{
	if (dutyPorcentagem <= 100)
	{
		uint16_t ccrx_value = ((uint32_t) pwm->TIMx->ARR * dutyPorcentagem) / 100;

		switch (pwm->channel)
		{
			case PWM_1:
				pwm->TIMx->CCR1 = ccrx_value;
				break;
			case PWM_2:
				pwm->TIMx->CCR2 = ccrx_value;
				break;
			case PWM_3:
				pwm->TIMx->CCR3 = ccrx_value;
				break;
			case PWM_4:
				pwm->TIMx->CCR4 = ccrx_value;
				break;
			default:
				BSP_Error_Handler();
				break;
		}
	}
}
