/*
 * opto.c
 *
 *  Created on: Aug 13, 2024
 *      Author: João Bortolace
 */

/* Includes ----------------------------------------------------------------------*/
#include "opto.h"
#include "motor_transversal.h"

/* Defines -------------------------------------------------------------------*/
#define BOBINA_TICK_VOLTA 				(8)
#define CARRO_TRANSVERAL_TICK_VOLTA 	(20)

/* Interrupções --------------------------------------------------------------*/
static void OPTO1_Interruption(void)
{
	if (BSP_GPIO_ReadPin(OPTO_2_Port, OPTO_2_Pin) == OPTO_OFF)
	{
		passo++;

		if (passo > BOBINA_TICK_VOLTA)
		{
			bobina_voltas++;
			passo = 0;
			andar = true;
			dir = LIBERANDO;
		}
	}
}

static void OPTO2_Interruption(void)
{
	if (BSP_GPIO_ReadPin(OPTO_1_Port, OPTO_1_Pin) == OPTO_OFF)
	{
		passo--;

		if (passo < -BOBINA_TICK_VOLTA)
		{
			bobina_voltas--;
			passo = 0;
			andar = true;
			dir = PUXANDO;
		}
	}
}

static void OPTO3_Interruption(void)
{
	cont++;

	if (cont > CARRO_TRANSVERAL_TICK_VOLTA)
	{
		carro_transversal_voltas++;
		cont = 0;
		andar = false;
	}
}

void OPTO_Init(void)
{
  	/* Configura as interrrupções externas do encoder */
  	EXTI_Config extiConfig = {0};
  	extiConfig.Pull = Pull_UP;
  	extiConfig.Trigger = FallingEdge;

  	extiConfig.ExtiLine = OPTO_1_EXTI;
  	extiConfig.GPIOx = OPTO_1_Port;
  	extiConfig.Pin = OPTO_1_Pin;
  	extiConfig.FuncaoInterrupcao = &OPTO1_Interruption;
  	BSP_EXTI_Init(&extiConfig);

  	extiConfig.ExtiLine = OPTO_2_EXTI;
  	extiConfig.GPIOx = OPTO_2_Port;
  	extiConfig.Pin = OPTO_2_Pin;
  	extiConfig.FuncaoInterrupcao = &OPTO2_Interruption;
  	BSP_EXTI_Init(&extiConfig);

  	extiConfig.ExtiLine = OPTO_3_EXTI;
  	extiConfig.GPIOx = OPTO_3_Port;
  	extiConfig.Pin = OPTO_3_Pin;
  	extiConfig.FuncaoInterrupcao = &OPTO3_Interruption;
  	BSP_EXTI_Init(&extiConfig);
}

