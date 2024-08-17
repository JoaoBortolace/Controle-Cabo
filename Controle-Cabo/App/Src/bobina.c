/*
 * bobina.c
 *
 *  Created on: Aug 16, 2024
 *      Author: João Bortolace
 */

/* Private includes ----------------------------------------------------------*/
#include "bobina.h"

/* Variáveis Privadas --------------------------------------------------------*/
static OS_TCB				motorBobinaTaskTCB;
static CPU_STK          	motorBobinaTaskStk[MOTOR_BOBINA_TASK_STK_SIZE];

volatile static uint16_t 	motorBobinaTensaoRead = 0;
volatile static uint16_t 	motorBobinaVel = 0;

/* Functions prototypes ------------------------------------------------------*/

/* Interrupções --------------------------------------------------------------*/
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc)
{
	if (hadc->Instance == ADC2) {
		OS_ERR err;

		OSFlagPost(
			(OS_FLAG_GRP *)&flagsGrp,
			(OS_FLAGS     )MOTOR_BOBINA_ADC_RDY,
			(OS_OPT       )OS_OPT_POST_FLAG_SET,
			(OS_ERR      *)&err
		);
	}
}

/* Task ----------------------------------------------------------------------*/
static void motorBobinaTask(void *p_arg)
{
	#define ERRO_DEATHZONE			(50U)
	#define DAC_RES					(12)
	#define DAC_MAX					((1<<12) - 1)
	#define FREQUENCIA_AMOSTRAGEM	(6400.0)

	OS_ERR err;
	CPU_TS ts;

	(void)p_arg;

	/* Inicializa a amostragem e conversão a/d e d/a */
	HAL_ADC_Start_DMA(&hadc2, (uint32_t *) &motorBobinaTensaoRead, 1);
	HAL_DAC_Start_DMA(&hdac, MOTOR_BOBINA_VEL_DAC_CHANNEL, (const uint32_t *) &motorBobinaVel, 1, DAC_ALIGN_12B_R);
	HAL_TIM_Base_Start(&htim2); /* 6.4 kHz */

	int32_t kp = 15;
	int32_t motorBobinaTensaoRef = 2048;

	/* Infinite loop */
	while (DEF_TRUE) {
		OSFlagPend(
			(OS_FLAG_GRP *)&flagsGrp,
			(OS_FLAGS     )MOTOR_BOBINA_ADC_RDY,
			(OS_TICK      )0,
			(OS_OPT       )(OS_OPT_PEND_FLAG_SET_ANY + OS_OPT_PEND_FLAG_CONSUME),
			(CPU_TS      *)&ts,
			(OS_ERR      *)&err
		);

		int32_t erro = motorBobinaTensaoRef - (int32_t) motorBobinaTensaoRead;

		/* Desliga o motor caso pressionado o switch e também aplica uma zona morta */
		if (abs(erro) <= ERRO_DEATHZONE || (HAL_GPIO_ReadPin(SW3_GPIO_Port, SW3_Pin) == SW_ON)) {
			HAL_GPIO_WritePin(MOTOR_BOBINA_EN_GPIO_Port, MOTOR_BOBINA_EN_Pin, MOTOR_BOBINA_EN_OFF);
			erro = 0;
		}
		else {
			HAL_GPIO_WritePin(MOTOR_BOBINA_EN_GPIO_Port, MOTOR_BOBINA_EN_Pin, MOTOR_BOBINA_EN_ON);
			erro = (erro >= 0 ? erro - ERRO_DEATHZONE : erro + ERRO_DEATHZONE); /* Retira o degrau devido a zona morta */
		}

		/* Controle P */
		int32_t controle = kp*erro;
		int32_t vel_dac = abs(controle);

		/* Limita o valor para o máximo do DAC */
		motorBobinaVel = vel_dac > DAC_MAX ? DAC_MAX : vel_dac;

		/* Caso o valor seja positivo, seta a direção CLOCK_WISE */
		if (controle >= 0) {
			HAL_GPIO_WritePin(MOTOR_BOBINA_DIR_GPIO_Port, MOTOR_BOBINA_DIR_Pin, MOTOR_BOBINA_CLOCKWISE);
		}
		else {
			HAL_GPIO_WritePin(MOTOR_BOBINA_DIR_GPIO_Port, MOTOR_BOBINA_DIR_Pin, MOTOR_BOBINA_COUNTER_CLOCKWISE);
		}

		/* Ajuste do ponto de referência */
		if (HAL_GPIO_ReadPin(SW0_GPIO_Port, SW0_Pin) == SW_ON) {
			motorBobinaTensaoRef = motorBobinaTensaoRead;
		}
	}
}

/* Functions -----------------------------------------------------------------*/
void motorBobinaCreateTask(void)
{
    OS_ERR err;

	OSTaskCreate(
    	(OS_TCB       *)&motorBobinaTaskTCB,
        (CPU_CHAR     *)"Tarefa de controle do motor da bobina",
        (OS_TASK_PTR   )motorBobinaTask,
        (void         *)0u,
        (OS_PRIO       )MOTOR_BOBINA_TASK_PRIO,
        (CPU_STK      *)&motorBobinaTaskStk[0u],
        (CPU_STK_SIZE  )0,
        (CPU_STK_SIZE  )MOTOR_BOBINA_TASK_STK_SIZE,
        (OS_MSG_QTY    )0u,
        (OS_TICK       )0u,
        (void         *)0u,
        (OS_OPT        )(OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR),
        (OS_ERR       *)&err
	);

	if (err != OS_ERR_NONE) {
		Error_Handler();
	}
}
