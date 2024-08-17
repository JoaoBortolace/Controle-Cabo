/*
 * bsp_extInt.c
 *
 *  Created on: Jun 27, 2024
 *      Author: borto
 */


/* Includes ------------------------------------------------------------------*/
#include "bsp_extInt.h"
#include "bsp.h"


#ifdef EXTI0_LINE
static volatile void (*interruption_EXTI0)(void) = NULL;
#endif

#ifdef EXTI1_LINE
static volatile void (*interruption_EXTI1)(void) = NULL;
#endif

#ifdef EXTI2_LINE
static volatile void (*interruption_EXTI2)(void) = NULL;
#endif

#ifdef EXTI3_LINE
static volatile void (*interruption_EXTI3)(void) = NULL;
#endif

#ifdef EXTI4_LINE
static volatile void (*interruption_EXTI4)(void) = NULL;
#endif

#ifdef EXTI5_LINE
static volatile void (*interruption_EXTI5)(void) = NULL;
#endif

#ifdef EXTI6_LINE
static volatile void (*interruption_EXTI6)(void) = NULL;
#endif

#ifdef EXTI7_LINE
static volatile void (*interruption_EXTI7)(void) = NULL;
#endif

#ifdef EXTI8_LINE
static volatile void (*interruption_EXTI8)(void) = NULL;
#endif

#ifdef EXTI9_LINE
static volatile void (*interruption_EXTI9)(void) = NULL;
#endif

#ifdef EXTI10_LINE
static volatile void (*interruption_EXTI10)(void) = NULL;
#endif

#ifdef EXTI11_LINE
static volatile void (*interruption_EXTI11)(void) = NULL;
#endif

#ifdef EXTI12_LINE
static volatile void (*interruption_EXTI12)(void) = NULL;
#endif

#ifdef EXTI13_LINE
static volatile void (*interruption_EXTI13)(void) = NULL;
#endif

#ifdef EXTI14_LINE
static volatile void (*interruption_EXTI14)(void) = NULL;
#endif

#ifdef EXTI15_LINE
static volatile void (*interruption_EXTI15)(void) = NULL;
#endif


void BSP_EXTI_Init(const EXTI_Config *extiConfig)
{
	GPIO_Config extiPin = {0};
	extiPin.velocidade = ALTO;
	extiPin.alternativo = 15U;

	switch (extiConfig->Pull)
	{
		case Pull_UP:
			extiPin.modo = ENTRADA_PullUp;
			break;
		case Pull_Down:
			extiPin.modo = ENTRADA_PullDown;
			break;
		default:
			extiPin.modo = ENTRADA_NoPull;
			break;
	}

	BSP_GPIO_Init(extiConfig->GPIOx, extiConfig->Pin, &extiPin);

	__HAL_RCC_SYSCFG_CLK_ENABLE();

	uint8_t EXTICR = 0x0;
	if (extiConfig->GPIOx == GPIOA)
	{
		EXTICR = 0x0;
	}
	else if (extiConfig->GPIOx == GPIOB)
	{
		EXTICR = 0x1;
	}
	else if (extiConfig->GPIOx == GPIOC)
	{
		EXTICR = 0x2;
	}
	else if (extiConfig->GPIOx == GPIOD)
	{
		EXTICR = 0x3;
	}
	else if (extiConfig->GPIOx == GPIOE)
	{
		EXTICR = 0x4;
	}
	else if (extiConfig->GPIOx == GPIOH)
	{
		EXTICR = 0x7;
	}
	else
	{
		BSP_Error_Handler();
		EXTICR = 0x0;
	}

	switch (extiConfig->ExtiLine)
	{
		case LL_EXTI_LINE_0:
#ifdef EXTI0_LINE
			interruption_EXTI0 = extiConfig->FuncaoInterrupcao;
#endif
			SYSCFG->EXTICR[0] |= EXTICR;
			NVIC_EnableIRQ(EXTI0_IRQn);
			break;
		case LL_EXTI_LINE_1:
#ifdef EXTI1_LINE
			interruption_EXTI1 = extiConfig->FuncaoInterrupcao;
#endif
			SYSCFG->EXTICR[0] |= EXTICR << 4;
			NVIC_EnableIRQ(EXTI1_IRQn);
			break;
		case LL_EXTI_LINE_2:
#ifdef EXTI2_LINE
			interruption_EXTI2 = extiConfig->FuncaoInterrupcao;
#endif
			SYSCFG->EXTICR[0] |= EXTICR << 8;
			NVIC_EnableIRQ(EXTI2_IRQn);
			break;
		case LL_EXTI_LINE_3:
#ifdef EXTI3_LINE
			interruption_EXTI3 = extiConfig->FuncaoInterrupcao;
#endif
			SYSCFG->EXTICR[0] |= EXTICR << 12;
			NVIC_EnableIRQ(EXTI3_IRQn);
			break;
		case LL_EXTI_LINE_4:
#ifdef EXTI4_LINE
			interruption_EXTI4 = extiConfig->FuncaoInterrupcao;
#endif
			SYSCFG->EXTICR[1] |= EXTICR;
			NVIC_EnableIRQ(EXTI4_IRQn);
			break;
		case LL_EXTI_LINE_5:
#ifdef EXTI5_LINE
			interruption_EXTI5 = extiConfig->FuncaoInterrupcao;
#endif
			SYSCFG->EXTICR[1] |= EXTICR << 4;
			NVIC_EnableIRQ(EXTI9_5_IRQn);
			break;
		case LL_EXTI_LINE_6:
#ifdef EXTI6_LINE
			interruption_EXTI6 = extiConfig->FuncaoInterrupcao;
#endif
			SYSCFG->EXTICR[1] |= EXTICR << 8;
			NVIC_EnableIRQ(EXTI9_5_IRQn);
			break;
		case LL_EXTI_LINE_7:
#ifdef EXTI7_LINE
			interruption_EXTI7 = extiConfig->FuncaoInterrupcao;
#endif
			SYSCFG->EXTICR[1] |= EXTICR << 12;
			NVIC_EnableIRQ(EXTI9_5_IRQn);
			break;
		case LL_EXTI_LINE_8:
#ifdef EXTI8_LINE
			interruption_EXTI8 = extiConfig->FuncaoInterrupcao;
#endif
			SYSCFG->EXTICR[2] |= EXTICR;
			NVIC_EnableIRQ(EXTI9_5_IRQn);
			break;
		case LL_EXTI_LINE_9:
#ifdef EXTI9_LINE
			interruption_EXTI9 = extiConfig->FuncaoInterrupcao;
#endif
			SYSCFG->EXTICR[2] |= EXTICR << 4;
			NVIC_EnableIRQ(EXTI9_5_IRQn);
			break;
		case LL_EXTI_LINE_10:
#ifdef EXTI10_LINE
			interruption_EXTI10 = extiConfig->FuncaoInterrupcao;
#endif
			SYSCFG->EXTICR[2] |= EXTICR << 8;
			NVIC_EnableIRQ(EXTI15_10_IRQn);
			break;
		case LL_EXTI_LINE_11:
#ifdef EXTI11_LINE
			interruption_EXTI11 = extiConfig->FuncaoInterrupcao;
#endif
			SYSCFG->EXTICR[2] |= EXTICR << 12;
			NVIC_EnableIRQ(EXTI15_10_IRQn);
			break;
		case LL_EXTI_LINE_12:
#ifdef EXTI12_LINE
			interruption_EXTI12 = extiConfig->FuncaoInterrupcao;
#endif
			SYSCFG->EXTICR[3] |= EXTICR;
			NVIC_EnableIRQ(EXTI15_10_IRQn);
			break;
		case LL_EXTI_LINE_13:
#ifdef EXTI13_LINE
			interruption_EXTI13 = extiConfig->FuncaoInterrupcao;
#endif
			SYSCFG->EXTICR[3] |= EXTICR << 4;
			NVIC_EnableIRQ(EXTI15_10_IRQn);
			break;
		case LL_EXTI_LINE_14:
#ifdef EXTI14_LINE
			interruption_EXTI14 = extiConfig->FuncaoInterrupcao;
#endif
			SYSCFG->EXTICR[3] |= EXTICR << 8;
			NVIC_EnableIRQ(EXTI15_10_IRQn);
			break;
		case LL_EXTI_LINE_15:
#ifdef EXTI15_LINE
			interruption_EXTI15 = extiConfig->FuncaoInterrupcao;
#endif
			SYSCFG->EXTICR[3] |= EXTICR << 12;
			NVIC_EnableIRQ(EXTI15_10_IRQn);
			break;
		default:
			BSP_Error_Handler();
			break;
	}

	EXTI->IMR |= extiConfig->ExtiLine; /* Desmacara a lina de exti */

	if (extiConfig->Trigger == RisingEdge)
	{
		EXTI->RTSR |= extiConfig->ExtiLine;
		EXTI->FTSR &= ~extiConfig->ExtiLine;
	}
	else if (extiConfig->Trigger == FallingEdge)
	{
		EXTI->RTSR &= ~extiConfig->ExtiLine;
		EXTI->FTSR |= extiConfig->ExtiLine;
	}
	else if (extiConfig->Trigger == BothEdge)
	{
		EXTI->RTSR |= extiConfig->ExtiLine;
		EXTI->FTSR |= extiConfig->ExtiLine;
	}
	else
	{
		BSP_Error_Handler();
	}
}

#ifdef EXTI0_LINE
void EXTI0_IRQHandler(void)
{
	if (EXTI->PR & (1 << 0) && interruption_EXTI0 != NULL)
	{
		(*interruption_EXTI0)();
		EXTI->PR |= (1 << 0); /* Reset a Flag */
	}
}
#endif

#ifdef EXTI1_LINE
void EXTI1_IRQHandler(void)
{
	if (EXTI->PR & (1 << 1) && interruption_EXTI1 != NULL)
	{
		(*interruption_EXTI1)();
		EXTI->PR |= (1 << 1); /* Reset a Flag */
	}
}
#endif

#ifdef EXTI2_LINE
void EXTI2_IRQHandler(void)
{
	if (EXTI->PR & (1 << 2) && interruption_EXTI2 != NULL)
	{
		(*interruption_EXTI2)();
		EXTI->PR |= (1 << 2); /* Reset a Flag */
	}
}
#endif

#ifdef EXTI3_LINE
void EXTI3_IRQHandler(void)
{
	if (EXTI->PR & (1 << 3) && interruption_EXTI3 != NULL)
	{
		EXTI->PR |= (1 << 3); /* Reset a Flag */
		(*interruption_EXTI3)();
	}
}
#endif

#ifdef EXTI4_LINE
void EXTI4_IRQHandler(void)
{
	if (EXTI->PR & (1 << 4) && interruption_EXTI4 != NULL)
	{
		(*interruption_EXTI4)();
		EXTI->PR |= (1 << 4); /* Reset a Flag */
	}
}
#endif

#if defined(EXTI5_LINE) || defined(EXTI6_LINE) || defined(EXTI7_LINE) || defined(EXTI8_LINE) || defined(EXTI9_LINE)
void EXTI9_5_IRQHandler(void)
{
#ifdef EXTI5_LINE
	if (EXTI->PR & (1 << 5) && interruption_EXTI5 != NULL)
	{
		(*interruption_EXTI5)();
		EXTI->PR |= (1 << 5); /* Reset a Flag */
	}
#endif
#ifdef EXTI6_LINE
	if (EXTI->PR & (1 << 6) && interruption_EXTI6 != NULL)
	{
		(*interruption_EXTI6)();
		EXTI->PR |= (1 << 6); /* Reset a Flag */
	}
#endif
#ifdef EXTI7_LINE
	if (EXTI->PR & (1 << 7) && interruption_EXTI7 != NULL)
	{
		(*interruption_EXTI7)();
		EXTI->PR |= (1 << 7); /* Reset a Flag */
	}
#endif
#ifdef EXTI8_LINE
	if (EXTI->PR & (1 << 8) && interruption_EXTI8 != NULL)
	{
		(*interruption_EXTI8)();
		EXTI->PR |= (1 << 8); /* Reset a Flag */
	}
#endif
#ifdef EXTI9_LINE
	if (EXTI->PR & (1 << 9) && interruption_EXTI9 != NULL)
	{
		(*interruption_EXTI9)();
		EXTI->PR |= (1 << 9); /* Reset a Flag */
	}
#endif
}
#endif

#if defined(EXTI10_LINE) || defined(EXTI11_LINE) || defined(EXTI12_LINE) || defined(EXTI13_LINE) || defined(EXTI14_LINE) || defined(EXTI15_LINE)
void EXTI15_10_IRQHandler(void)
{
#ifdef EXTI10_LINE
	if (EXTI->PR & (1 << 10) && interruption_EXTI10 != NULL)
	{
		EXTI->PR |= (1 << 10); /* Reset a Flag */
		(*interruption_EXTI10)();
	}
#endif
#ifdef EXTI11_LINE
	if (EXTI->PR & (1 << 11) && interruption_EXTI11 != NULL)
	{
		(*interruption_EXTI11)();
		EXTI->PR |= (1 << 11); /* Reset a Flag */
	}
#endif
#ifdef EXTI12_LINE
	if (EXTI->PR & (1 << 12) && interruption_EXTI12 != NULL)
	{
		(*interruption_EXTI12)();
		EXTI->PR |= (1 << 12); /* Reset a Flag */
	}
#endif
#ifdef EXTI13_LINE
	if (EXTI->PR & (1 << 8) && interruption_EXTI13 != NULL)
	{
		(*interruption_EXTI13)();
		EXTI->PR |= (1 << 13); /* Reset a Flag */
	}
#endif
#ifdef EXTI14_LINE
	if (EXTI->PR & (1 << 14) && interruption_EXTI14 != NULL)
	{
		EXTI->PR |= (1 << 14); /* Reset a Flag */
		(*interruption_EXTI14)();
	}
#endif
#ifdef EXTI15_LINE
	if (EXTI->PR & (1 << 15) && interruption_EXTI15 != NULL)
	{
		EXTI->PR |= (1 << 15); /* Reset a Flag */
		(*interruption_EXTI15)();
	}
#endif
}
#endif
