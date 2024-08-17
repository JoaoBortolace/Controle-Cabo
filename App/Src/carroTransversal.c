/*
 * carroTransversal.c
 *
 *  Created on: Aug 16, 2024
 *      Author: João Bortolace
 */

/* Private includes ----------------------------------------------------------*/
#include "carroTransversal.h"

/* Variáveis Privadas --------------------------------------------------------*/
static OS_TCB				carroTransversalTaskTCB;
static CPU_STK          	carroTransversalStk[CARRO_TRANSVERSAL_TASK_STK_SIZE];

static int8_t				bobinaTick = 0;
static int8_t				carroTransversalTick = 0;

static bool					carroTransversalAndar = false;

/* Functions prototypes ------------------------------------------------------*/
static void carroTransversalCtrl(CARRO_TRANSVERSAL_CTRL ctrl);
static void carroTransversalHome(void);

/* Interrupções --------------------------------------------------------------*/
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	switch (GPIO_Pin) {
		case OPTO_1_Pin:
			if (HAL_GPIO_ReadPin(OPTO_2_GPIO_Port, OPTO_2_Pin) == OPTO_OFF) {
				bobinaTick++;

				if (bobinaTick > BOBINA_TICK_VOLTA) {
					bobinaTick = 0;
					carroTransversalAndar = true;

					OS_ERR err;
					OSFlagPost(
						(OS_FLAG_GRP *)&flagsGrp,
						(OS_FLAGS     )MOTOR_BOBINA_LIBERANDO,
						(OS_OPT       )OS_OPT_POST_FLAG_SET,
						(OS_ERR      *)&err
					);
				}
			}
			break;

		case OPTO_2_Pin:
			if (HAL_GPIO_ReadPin(OPTO_1_GPIO_Port, OPTO_1_Pin) == OPTO_OFF) {
				bobinaTick--;

				if (bobinaTick < -1*BOBINA_TICK_VOLTA) {
					bobinaTick = 0;
					carroTransversalAndar = true;

					OS_ERR err;
					OSFlagPost(
						(OS_FLAG_GRP *)&flagsGrp,
						(OS_FLAGS     )MOTOR_BOBINA_PUXANDO,
						(OS_OPT       )OS_OPT_POST_FLAG_SET,
						(OS_ERR      *)&err
					);
				}
			}
			break;

		case OPTO_3_Pin:
			carroTransversalTick++;

			if (carroTransversalTick > CARRO_TRANSVERSAL_TICK_VOLTA) {
				carroTransversalTick = 0;
				carroTransversalAndar = false;
			}
			break;

		default:
			__NOP();
			break;
	}
}

/* Task ----------------------------------------------------------------------*/
static void carroTransversalTask(void *p_arg)
{
	OS_ERR err;
	OS_FLAGS comando;
	CPU_TS ts;

	(void)p_arg;

	HAL_TIM_PWM_Start(&htim1, MOTOR_CARRO_TRANSVERSAL_PWM_Channel);

	/* Trás o carro transversal para posição inicial */
	carroTransversalHome();

	bobinaTick = 0;
	carroTransversalTick = 0;
	carroTransversalAndar = false;

	OS_FLAGS comandoPrev = MOTOR_BOBINA_LIBERANDO;
	CARRO_TRANSVERSAL_CTRL carroCtrl = PARADO;

	/* Infinite loop */
	while (DEF_TRUE) {
		/* Espera o comando para andar */
		comando = OSFlagPend(
					(OS_FLAG_GRP *)&flagsGrp,
					(OS_FLAGS     )MOTOR_BOBINA_LIBERANDO + MOTOR_BOBINA_PUXANDO,
					(OS_TICK      )0,
					(OS_OPT       )(OS_OPT_PEND_FLAG_SET_ANY + OS_OPT_PEND_FLAG_CONSUME),
					(CPU_TS      *)&ts,
					(OS_ERR      *)&err
				);

		while (carroTransversalAndar) {
			bool fimCurso_1 = HAL_GPIO_ReadPin(FIM_CURSO_1_GPIO_Port, FIM_CURSO_1_Pin);
			bool fimCurso_2 = HAL_GPIO_ReadPin(FIM_CURSO_2_GPIO_Port, FIM_CURSO_2_Pin);

			if (fimCurso_1 && fimCurso_2) { /* Ambas fim de cursos acionado -> impossível */
				carroTransversalAndar = false;
				carroCtrl = PARADO;
			}
			else if (fimCurso_1) {
				carroCtrl = DIREITA;
			}
			else if (fimCurso_2) {
				carroCtrl = ESQUERDA;
			}
			else {
				if (comando != comandoPrev) {
					comandoPrev = comando;

					if (carroCtrl == ESQUERDA) {
						carroCtrl = DIREITA;
					}
					else {
						carroCtrl = ESQUERDA;
					}
				}
			}

			carroTransversalCtrl(carroCtrl);
		}

		carroTransversalCtrl(PARADO);
	}
}

/* Functions -----------------------------------------------------------------*/
void carroTransversalCreateTask(void)
{
    OS_ERR err;

	OSTaskCreate(
    	(OS_TCB       *)&carroTransversalTaskTCB,
        (CPU_CHAR     *)"Tarefa de controle do motor do carro transversal",
        (OS_TASK_PTR   )carroTransversalTask,
        (void         *)0u,
        (OS_PRIO       )CARRO_TRANSVERSAL_TASK_PRIO,
        (CPU_STK      *)&carroTransversalStk[0u],
        (CPU_STK_SIZE  )0,
        (CPU_STK_SIZE  )CARRO_TRANSVERSAL_TASK_STK_SIZE,
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

static void carroTransversalCtrl(CARRO_TRANSVERSAL_CTRL ctrl)
{
	switch(ctrl) {
		case ESQUERDA:
			HAL_GPIO_WritePin(MOTOR_CARRO_TRANSVERSAL_DIR1_GPIO_Port, MOTOR_CARRO_TRANSVERSAL_DIR1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(MOTOR_CARRO_TRANSVERSAL_DIR2_GPIO_Port, MOTOR_CARRO_TRANSVERSAL_DIR2_Pin, GPIO_PIN_RESET);
			break;

		case DIREITA:
			HAL_GPIO_WritePin(MOTOR_CARRO_TRANSVERSAL_DIR1_GPIO_Port, MOTOR_CARRO_TRANSVERSAL_DIR1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(MOTOR_CARRO_TRANSVERSAL_DIR2_GPIO_Port, MOTOR_CARRO_TRANSVERSAL_DIR2_Pin, GPIO_PIN_SET);
			break;

		case PARADO:
		default:
			HAL_GPIO_WritePin(MOTOR_CARRO_TRANSVERSAL_DIR1_GPIO_Port, MOTOR_CARRO_TRANSVERSAL_DIR1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(MOTOR_CARRO_TRANSVERSAL_DIR2_GPIO_Port, MOTOR_CARRO_TRANSVERSAL_DIR2_Pin, GPIO_PIN_RESET);
			break;
	}
}

static void carroTransversalHome(void)
{
	#define HOME_TIMEOUT	25000000

	uint32_t homeTimeout = HOME_TIMEOUT;

	while (homeTimeout > 0 && (HAL_GPIO_ReadPin(FIM_CURSO_2_GPIO_Port, FIM_CURSO_2_Pin) == GPIO_PIN_RESET)) {
		carroTransversalCtrl(DIREITA);
		homeTimeout--;
	}

	carroTransversalCtrl(PARADO);
}
