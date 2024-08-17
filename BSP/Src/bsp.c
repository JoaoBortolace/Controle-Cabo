/*
 * bsp.c
 *
 *  Created on: Jun 27, 2024
 *      Author: borto
 */

#include "bsp.h"

void BSP_Error_Handler(void)
{
	__disable_irq();

	while (1)
	{
		BSP_GPIO_ResetPin(LED_ERROR_Port, LED_ERROR_Pin);
	}
}

void BSP_Init(void)
{
	NVIC_EnableIRQ(SysTick_IRQn);
	HAL_NVIC_SetPriority(SysTick_IRQn, -1, -1);


	GPIO_Config pinConfig = {0};
	pinConfig.modo = SAIDA_OD;
	pinConfig.velocidade = BAIXO;

	/* Configura os LEDs */
	BSP_GPIO_Init(LED0_Port, LED0_Pin, &pinConfig);
	BSP_GPIO_SetPin(LED0_Port, LED0_Pin);
	BSP_GPIO_Init(LED1_Port, LED1_Pin, &pinConfig);
	BSP_GPIO_SetPin(LED1_Port, LED1_Pin);
	BSP_GPIO_Init(LED2_Port, LED2_Pin, &pinConfig);
	BSP_GPIO_SetPin(LED2_Port, LED2_Pin);
	BSP_GPIO_Init(LED3_Port, LED3_Pin, &pinConfig);
	BSP_GPIO_SetPin(LED3_Port, LED3_Pin);
	BSP_GPIO_Init(LED4_Port, LED4_Pin, &pinConfig);
	BSP_GPIO_SetPin(LED4_Port, LED4_Pin);

	/* Configura os pinos de habilitação das saídas digitais */
	pinConfig.modo = SAIDA_PP;
	BSP_GPIO_Init(ENAOUT03_Port, ENAOUT03_Pin, &pinConfig);
	BSP_GPIO_ResetPin(ENAOUT03_Port, ENAOUT03_Pin);
	BSP_GPIO_Init(ENAOUT04_Port, ENAOUT04_Pin, &pinConfig);
	BSP_GPIO_ResetPin(ENAOUT04_Port, ENAOUT04_Pin);
}
