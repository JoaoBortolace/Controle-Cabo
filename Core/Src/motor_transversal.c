/*
 * motor_transversal.c
 *
 *  Created on: Aug 13, 2024
 *      Author: João Bortolace
 */

/* Includes ----------------------------------------------------------------------*/
#include "motor_transversal.h"

//static PWM motor_tranversal_pwm;

void Motor_Transversal_Init(void)
{
	GPIO_Config pinConfig = {0};

	/* Configura o pino de direção do carro transversal */
  	pinConfig.velocidade = ALTO;
  	pinConfig.modo = SAIDA_PP;
  	BSP_GPIO_Init(MOTOR_CARRO_TRANSVERSAL_DIR1_Port, MOTOR_CARRO_TRANSVERSAL_DIR1_Pin, &pinConfig);
  	BSP_GPIO_Init(MOTOR_CARRO_TRANSVERSAL_DIR2_Port, MOTOR_CARRO_TRANSVERSAL_DIR2_Pin, &pinConfig);

//  	/* Configura o PWM de controle de velocidade do motor do carro transversal */
//  	PWM_Config pwmConfig = {0};
//  	pwmConfig.GPIOx = MOTOR_CARRO_TRANSVERSAL_PWM_Port;
//  	pwmConfig.Pin = MOTOR_CARRO_TRANSVERSAL_PWM_Pin;
//  	/* TIM_CLK = 90MHz / (45*100*1) =  20kHz */
//  	pwmConfig.Prescaler = 45-1;
//  	pwmConfig.Counter = 100;
//
//  	motor_tranversal_pwm.TIMx = MOTOR_CARRO_TRANSVERSAL_PWM_TIMER;
//  	motor_tranversal_pwm.channel = MOTOR_CARRO_TRANSVERSAL_PWM_CANAL;
//
//  	BSP_PWM_Init(&motor_tranversal_pwm, &pwmConfig);
//  	BSP_PWM_SetDuty(&motor_tranversal_pwm, 0);
}

void Motor_Transversal_Ctrl(MOTOR_DIR ctrl)
{
	switch (ctrl) {
		case HORARIO:
			BSP_GPIO_SetPin(MOTOR_CARRO_TRANSVERSAL_DIR1_Port, MOTOR_CARRO_TRANSVERSAL_DIR1_Pin);
			BSP_GPIO_ResetPin(MOTOR_CARRO_TRANSVERSAL_DIR2_Port, MOTOR_CARRO_TRANSVERSAL_DIR2_Pin);
			break;
		case ANTI_HORARIO:
			BSP_GPIO_ResetPin(MOTOR_CARRO_TRANSVERSAL_DIR1_Port, MOTOR_CARRO_TRANSVERSAL_DIR1_Pin);
			BSP_GPIO_SetPin(MOTOR_CARRO_TRANSVERSAL_DIR2_Port, MOTOR_CARRO_TRANSVERSAL_DIR2_Pin);
			break;
		case FREIO:
			BSP_GPIO_SetPin(MOTOR_CARRO_TRANSVERSAL_DIR1_Port, MOTOR_CARRO_TRANSVERSAL_DIR1_Pin);
			BSP_GPIO_SetPin(MOTOR_CARRO_TRANSVERSAL_DIR2_Port, MOTOR_CARRO_TRANSVERSAL_DIR2_Pin);
			break;
		case PARADO:
			BSP_GPIO_ResetPin(MOTOR_CARRO_TRANSVERSAL_DIR1_Port, MOTOR_CARRO_TRANSVERSAL_DIR1_Pin);
			BSP_GPIO_ResetPin(MOTOR_CARRO_TRANSVERSAL_DIR2_Port, MOTOR_CARRO_TRANSVERSAL_DIR2_Pin);
		  	break;
		default:
			BSP_GPIO_ResetPin(MOTOR_CARRO_TRANSVERSAL_DIR1_Port, MOTOR_CARRO_TRANSVERSAL_DIR1_Pin);
			BSP_GPIO_ResetPin(MOTOR_CARRO_TRANSVERSAL_DIR2_Port, MOTOR_CARRO_TRANSVERSAL_DIR2_Pin);
		  	BSP_Error_Handler();
			break;
	}
}

MOTOR_DIR Motor_Transversal_GetDir(void)
{
	bool dir1 = BSP_GPIO_ReadOutputPin(MOTOR_CARRO_TRANSVERSAL_DIR1_Port, MOTOR_CARRO_TRANSVERSAL_DIR1_Pin);
	bool dir2 = BSP_GPIO_ReadOutputPin(MOTOR_CARRO_TRANSVERSAL_DIR2_Port, MOTOR_CARRO_TRANSVERSAL_DIR2_Pin);

	if (dir1 && dir2)
	{
		return FREIO;
	}
	else if (dir1 && !dir2)
	{
		return HORARIO;
	}
	else if (!dir1 && dir2)
	{
		return ANTI_HORARIO;
	}
	else
	{
		return PARADO;
	}
}

void Motor_Transversal_ToggleDir(void)
{
	bool dir1 = BSP_GPIO_ReadOutputPin(MOTOR_CARRO_TRANSVERSAL_DIR1_Port, MOTOR_CARRO_TRANSVERSAL_DIR1_Pin);
	bool dir2 = BSP_GPIO_ReadOutputPin(MOTOR_CARRO_TRANSVERSAL_DIR2_Port, MOTOR_CARRO_TRANSVERSAL_DIR2_Pin);

	if (dir1 ^ dir2)
	{
		BSP_GPIO_TogglePin(MOTOR_CARRO_TRANSVERSAL_DIR1_Port, MOTOR_CARRO_TRANSVERSAL_DIR1_Pin);
		BSP_GPIO_TogglePin(MOTOR_CARRO_TRANSVERSAL_DIR2_Port, MOTOR_CARRO_TRANSVERSAL_DIR2_Pin);
	}
}

