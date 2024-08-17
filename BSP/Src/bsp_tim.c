/*
 * bsp_tim.c
 *
 *  Created on: Jul 3, 2024
 *      Author: borto
 */

/* Includes -------------------------------------------------------------------*/
#include "bsp_tim.h"
#include "bsp.h"


#ifdef TIM1_Interrupt
static volatile void (*interruption_TIM1)(void) = NULL;
#endif

#ifdef TIM2_Interrupt
static volatile void (*interruption_TIM2)(void) = NULL;
#endif

#ifdef TIM3_Interrupt
static volatile void (*interruption_TIM3)(void) = NULL;
#endif

#ifdef TIM4_Interrupt
static volatile void (*interruption_TIM4)(void) = NULL;
#endif

#ifdef TIM5_Interrupt
static volatile void (*interruption_TIM5)(void) = NULL;
#endif

#ifdef TIM6_Interrupt
static volatile void (*interruption_TIM6)(void) = NULL;
#endif

#ifdef TIM7_Interrupt
static volatile void (*interruption_TIM7)(void) = NULL;
#endif

#ifdef TIM8_Interrupt
static volatile void (*interruption_TIM8)(void) = NULL;
#endif

#ifdef TIM9_Interrupt
static volatile void (*interruption_TIM9)(void) = NULL;
#endif

#ifdef TIM10_Interrupt
static volatile void (*interruption_TIM10)(void) = NULL;
#endif

#ifdef TIM11_Interrupt
static volatile void (*interruption_TIM11)(void) = NULL;
#endif

#ifdef TIM12_Interrupt
static volatile void (*interruption_TIM12)(void) = NULL;
#endif

#ifdef TIM13_Interrupt
static volatile void (*interruption_TIM13)(void) = NULL;
#endif

#ifdef TIM14_Interrupt
static volatile void (*interruption_TIM14)(void) = NULL;
#endif

void BSP_TIM_Init(uint8_t timer, const TIM_Config *timConfig)
{
	TIMx_CLK_ENABLE(timConfig->TIMx);

#ifdef DEBUG
	DBGMCU->APB1FZ |= DBGMCU_APB1_FZ_DBG_TIM2_STOP | DBGMCU_APB1_FZ_DBG_TIM3_STOP | DBGMCU_APB1_FZ_DBG_TIM4_STOP | DBGMCU_APB1_FZ_DBG_TIM5_STOP | DBGMCU_APB1_FZ_DBG_TIM6_STOP
					| DBGMCU_APB1_FZ_DBG_TIM7_STOP | DBGMCU_APB1_FZ_DBG_TIM12_STOP | DBGMCU_APB1_FZ_DBG_TIM13_STOP | DBGMCU_APB1_FZ_DBG_TIM14_STOP;

	DBGMCU->APB2FZ |= DBGMCU_APB2_FZ_DBG_TIM1_STOP | DBGMCU_APB2_FZ_DBG_TIM8_STOP | DBGMCU_APB2_FZ_DBG_TIM9_STOP | DBGMCU_APB2_FZ_DBG_TIM10_STOP | DBGMCU_APB2_FZ_DBG_TIM11_STOP;
#endif

	timConfig->TIMx->PSC = timConfig->Prescaler;
	timConfig->TIMx->ARR = timConfig->Counter;

	timConfig->TIMx->CR1 |= ((uint8_t) timConfig->ClkDiv << TIM_CR1_CKD_Pos)
							| (timConfig->preload << TIM_CR1_ARPE_Pos)
							| (timConfig->DownCounter << TIM_CR1_DIR_Pos)
							| (timConfig->onePulseMode << TIM_CR1_OPM_Pos)
							| (timConfig->UpRequest << TIM_CR1_URS_Pos)
							| (timConfig->UpDisable << TIM_CR1_UDIS_Pos);

	if (timConfig->triggerGeneration)
	{
		timConfig->TIMx->CR2 |= TIM_CR2_MMS_1;
		timConfig->TIMx->EGR |= TIM_EGR_TG | TIM_EGR_UG;
	}

	if (timConfig->interrupcaoEnable)
	{
		timConfig->TIMx->DIER |= TIM_DIER_UIE;

		switch (timer)
		{
			case 1:
#ifdef TIM1_Interrupt
				interruption_TIM1 = timConfig->FuncaoInterrupcao;
#endif
				if(!NVIC_GetEnableIRQ(TIM1_BRK_TIM9_IRQn))
				{
					NVIC_EnableIRQ(TIM1_BRK_TIM9_IRQn);
				}
				break;
			case 2:
#ifdef TIM2_Interrupt
				interruption_TIM2 = timConfig->FuncaoInterrupcao;
#endif
				NVIC_EnableIRQ(TIM2_IRQn);
				break;
			case 3:
#ifdef TIM3_Interrupt
				interruption_TIM3 = timConfig->FuncaoInterrupcao;
#endif
				NVIC_EnableIRQ(TIM3_IRQn);
				break;
			case 4:
#ifdef TIM4_Interrupt
				interruption_TIM4 = timConfig->FuncaoInterrupcao;
#endif
				NVIC_EnableIRQ(TIM4_IRQn);
				break;
			case 5:
#ifdef TIM5_Interrupt
				interruption_TIM5 = timConfig->FuncaoInterrupcao;
#endif
				NVIC_EnableIRQ(TIM5_IRQn);
				break;
			case 6:
#ifdef TIM6_Interrupt
				interruption_TIM6 = timConfig->FuncaoInterrupcao;
#endif
				NVIC_EnableIRQ(TIM6_DAC_IRQn);
				break;
			case 7:
#ifdef TIM7_Interrupt
				interruption_TIM7 = timConfig->FuncaoInterrupcao;
#endif
				NVIC_EnableIRQ(TIM7_IRQn);
				break;
			case 8:
#ifdef TIM8_Interrupt
				interruption_TIM8 = timConfig->FuncaoInterrupcao;
#endif
				if(!NVIC_GetEnableIRQ(TIM8_BRK_TIM12_IRQn))
				{
					NVIC_EnableIRQ(TIM8_BRK_TIM12_IRQn);
				}
				break;
			case 9:
#ifdef TIM9_Interrupt
				interruption_TIM9 = timConfig->FuncaoInterrupcao;
#endif
				if(!NVIC_GetEnableIRQ(TIM1_BRK_TIM9_IRQn))
				{
					NVIC_EnableIRQ(TIM1_BRK_TIM9_IRQn);
				}
				break;
			case 10:
#ifdef TIM10_Interrupt
				interruption_TIM10 = timConfig->FuncaoInterrupcao;
#endif
				if(!NVIC_GetEnableIRQ(TIM1_UP_TIM10_IRQn))
				{
					NVIC_EnableIRQ(TIM1_UP_TIM10_IRQn);
				}
				break;
			case 11:
#ifdef TIM11_Interrupt
				interruption_TIM11 = timConfig->FuncaoInterrupcao;
#endif
				if(!NVIC_GetEnableIRQ(TIM1_TRG_COM_TIM11_IRQn))
				{
					NVIC_EnableIRQ(TIM1_TRG_COM_TIM11_IRQn);
				}
				break;
			case 12:
#ifdef TIM12_Interrupt
				interruption_TIM12 = timConfig->FuncaoInterrupcao;
#endif
				{
					NVIC_EnableIRQ(TIM8_BRK_TIM12_IRQn);
				}
				break;
			case 13:
#ifdef TIM13_Interrupt
				interruption_TIM13 = timConfig->FuncaoInterrupcao;
#endif
				if(!NVIC_GetEnableIRQ(TIM8_UP_TIM13_IRQn))
				{
					NVIC_EnableIRQ(TIM8_UP_TIM13_IRQn);
				}
				break;
			case 14:
#ifdef TIM14_Interrupt
				interruption_TIM14 = timConfig->FuncaoInterrupcao;
#endif
				if(!NVIC_GetEnableIRQ(TIM8_TRG_COM_TIM14_IRQn))
				{
					NVIC_EnableIRQ(TIM8_TRG_COM_TIM14_IRQn);
				}
				break;
			default:
				BSP_Error_Handler();
				break;
		}
	}

	timConfig->TIMx->CR1 |= TIM_CR1_CEN;
}

#if defined(TIM1_Interrupt) || defined(TIM9_Interrupt)
void TIM1_BRK_TIM9_IRQHandler(void)
{

}
#endif

#ifdef TIM2_Interrupt
void TIM2_IRQHandler(void)
{
	if (TIM2->SR & TIM_SR_UIF && interruption_TIM2 != NULL)
	{
		TIM2->SR &= ~TIM_SR_UIF;

		(*interruption_TIM2)();
	}
}
#endif

#ifdef TIM3_Interrupt
void TIM3_IRQHandler(void)
{
	if (TIM3->SR & TIM_SR_UIF && interruption_TIM3 != NULL)
	{
		TIM3->SR &= ~TIM_SR_UIF;

		(*interruption_TIM3)();
	}
}
#endif

#ifdef TIM4_Interrupt
void TIM4_IRQHandler(void)
{
	if (TIM4->SR & TIM_SR_UIF && interruption_TIM4 != NULL)
	{
		TIM4->SR &= ~TIM_SR_UIF;

		(*interruption_TIM4)();
	}
}
#endif

#ifdef TIM5_Interrupt
void TIM5_IRQHandler(void)
{
	if (TIM5->SR & TIM_SR_UIF && interruption_TIM5 != NULL)
	{
		TIM5->SR &= ~TIM_SR_UIF;

		(*interruption_TIM5)();
	}
}
#endif

#ifdef TIM6_Interrupt
void TIM6_DAC_IRQHandler(void)
{
	if (TIM6->SR & TIM_SR_UIF && interruption_TIM6 != NULL)
	{
		TIM6->SR &= ~TIM_SR_UIF;

		(*interruption_TIM6)();
	}
}
#endif

#ifdef TIM7_Interrupt
void TIM7_IRQHandler(void)
{
	if (TIM7->SR & TIM_SR_UIF && interruption_TIM7 != NULL)
	{
		TIM7->SR &= ~TIM_SR_UIF;

		(*interruption_TIM7)();
	}
}
#endif
