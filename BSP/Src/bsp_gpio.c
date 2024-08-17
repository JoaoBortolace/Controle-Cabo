/*
 * bsp_gpio.c
 *
 *  Created on: Jun 27, 2024
 *      Author: borto
 */

/* Includes ------------------------------------------------------------------*/
#include "bsp_gpio.h"
#include "bsp.h"

void BSP_GPIO_Init(__IO GPIO_TypeDef *GPIOx, uint32_t Pin, const GPIO_Config *pinConfig)
{
	GPIOx_CLK_ENABLE(GPIOx);

	if (pinConfig->modo == ENTRADA_NoPull)
	{
		GPIOx->MODER &= ~(3U << Pin*2U);
		GPIOx->PUPDR &= ~(3U << Pin*2U);
	}
	else if (pinConfig->modo == ENTRADA_PullDown)
	{
		GPIOx->MODER &= ~(3U << Pin*2U);

		GPIOx->PUPDR &= ~(3U << Pin*2U);
		GPIOx->PUPDR |= (2U << Pin*2U);
	}
	else if (pinConfig->modo == ENTRADA_PullUp)
	{
		GPIOx->MODER &= ~(3U << Pin*2U);

		GPIOx->PUPDR &= ~(3U << Pin*2U);
		GPIOx->PUPDR |= (1U << Pin*2U);
	}
	else if (pinConfig->modo == SAIDA_OD)
	{
		GPIOx->MODER &= ~(3U << Pin*2U);
		GPIOx->MODER |= (1U << Pin*2U);

		GPIOx->OTYPER |= (1 << Pin);

		GPIOx->PUPDR &= ~(3U << Pin*2U);
	}
	else if (pinConfig->modo == SAIDA_PP)
	{
		GPIOx->MODER &= ~(3U << Pin*2U);
		GPIOx->MODER |= (1U << Pin*2U);

		GPIOx->OTYPER &= ~(0 << Pin);

		GPIOx->PUPDR &= ~(3U << Pin*2U);
	}
	else if (pinConfig->modo == ANALOGICO)
	{
		GPIOx->MODER |= (3U << Pin*2U);
		GPIOx->PUPDR &= ~(3U << Pin*2U);
	}
	else if (pinConfig->modo == ALTERNATIVO_OD)
	{
		GPIOx->MODER &= ~(3U << Pin*2U);
		GPIOx->MODER |= (10 << Pin*2U);

		GPIOx->OTYPER |= (1 << Pin);

		GPIOx->PUPDR &= ~(3U << Pin*2U);
	}
	else if (pinConfig->modo == ALTERNATIVO_PP)
	{
		GPIOx->MODER &= ~(3U << Pin*2U);
		GPIOx->MODER |= (10 << Pin*2U);

		GPIOx->OTYPER &= ~(0 << Pin);

		GPIOx->PUPDR &= ~(3U << Pin*2U);
	}
	else
	{
		BSP_Error_Handler();
	}

	if (Pin < 8)
	{
		GPIOx->AFR[0] &= ~(1111 << 4U*Pin);
		GPIOx->AFR[0] |= (pinConfig->alternativo << 4U*Pin);
	}
	else
	{
		GPIOx->AFR[1] &= ~(1111 << 4U*Pin);
		GPIOx->AFR[1] |= (pinConfig->alternativo << 4U*Pin);
	}

	if (pinConfig->velocidade == BAIXO)
	{
		GPIOx->OSPEEDR &= ~(3U << Pin*2U);
	}
	else if (pinConfig->velocidade == MEDIO)
	{
		GPIOx->OSPEEDR &= ~(3U << Pin*2U);
		GPIOx->OSPEEDR |= (1U << Pin*2U);
	}
	else if (pinConfig->velocidade == ALTO)
	{
		GPIOx->OSPEEDR &= ~(3U << Pin*2U);
		GPIOx->OSPEEDR |= (2U << Pin*2U);
	}
	else if (pinConfig->velocidade == MUITO_ALTO)
	{
		GPIOx->OSPEEDR |= (3U << Pin*2U);
	}
	else
	{
		BSP_Error_Handler();
	}
}

void BSP_GPIO_WritePin(__IO GPIO_TypeDef *GPIOx, uint32_t Pin, bool Value)
{
	if(Value)
	{
		GPIOx->ODR |= (1 << Pin);
	}
	else
	{
		GPIOx->ODR &= ~(1 << Pin);
	}
}

void BSP_GPIO_SetPin(__IO GPIO_TypeDef *GPIOx, uint32_t Pin)
{
	GPIOx->ODR |= (1 << Pin);
}

void BSP_GPIO_ResetPin(__IO GPIO_TypeDef *GPIOx, uint32_t Pin)
{
	GPIOx->ODR &= ~(1 << Pin);
}

void BSP_GPIO_WritePort(__IO GPIO_TypeDef *GPIOx, uint32_t Value)
{
	GPIOx->ODR = Value;
}

void BSP_GPIO_TogglePin(__IO GPIO_TypeDef *GPIOx, uint32_t Pin)
{
	if (GPIOx->ODR & (1 << Pin))
	{
		GPIOx->ODR &= ~(1 << Pin);
	}
	else
	{
		GPIOx->ODR |= (1 << Pin);
	}
}

bool BSP_GPIO_ReadPin(__IO GPIO_TypeDef *GPIOx, uint32_t Pin)
{
	return (GPIOx->IDR & (1 << Pin));
}

uint32_t BSP_GPIO_ReadPort(__IO GPIO_TypeDef *GPIOx)
{
	return GPIOx->IDR;
}

bool BSP_GPIO_ReadOutputPin(__IO GPIO_TypeDef *GPIOx, uint32_t Pin)
{
	return (GPIOx->ODR & (1 << Pin));
}
uint32_t BSP_GPIO_ReadOutputPort(__IO GPIO_TypeDef *GPIOx)
{
	return GPIOx->ODR;
}
