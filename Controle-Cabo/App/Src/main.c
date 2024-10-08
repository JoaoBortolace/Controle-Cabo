/*
 * mian
 *
 *  Created on: Aug 15, 2024
 *      Author: borto
 */

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Variáveis Privadas --------------------------------------------------------*/
volatile OS_FLAG_GRP 		flagsGrp;

static OS_TCB				programStartTaskTCB;
static CPU_STK          	programStartTaskStk[PROGRAM_START_TASK_STK_SIZE];

/* Task prototypes -----------------------------------------------------------*/
static void programStartTask(void *p_arg);

/* Main ----------------------------------------------------------------------*/
int main(void)
{
	/* MCU Configuration -----------------------------------------------------*/

	/* Reset of all peripherals, Initializes the Flash interface and the Systick. */
	HAL_Init();

	/* Configura o CLock da CPU para 160MHz */
	SystemClock_Config();

	/* Iniciliza o CPU */
	CPU_Init();

	/* Inicializa o sistema */
	OS_ERR err;

	OSInit(&err);

	if (err != OS_ERR_NONE) {
		Error_Handler();
	}

	OSFlagCreate(
		(OS_FLAG_GRP *)&flagsGrp,
		(CPU_CHAR    *)"Grupo de flags",
		(OS_FLAGS     )0,
		(OS_ERR      *)&err
	);

	if (err != OS_ERR_NONE) {
		Error_Handler();
	}

    OSTaskCreate(
    	(OS_TCB       *)&programStartTaskTCB,
        (CPU_CHAR     *)"Tarefa de Inicializar o programa",
        (OS_TASK_PTR   )programStartTask,
        (void         *)0u,
        (OS_PRIO       )PROGRAM_START_TASK_PRIO,
        (CPU_STK      *)&programStartTaskStk[0u],
        (CPU_STK_SIZE  )programStartTaskStk[PROGRAM_START_TASK_STK_SIZE / 10u],
        (CPU_STK_SIZE  )PROGRAM_START_TASK_STK_SIZE,
        (OS_MSG_QTY    )0u,
        (OS_TICK       )0u,
        (void         *)0u,
        (OS_OPT        )(OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR),
        (OS_ERR       *)&err
	);

	if (err != OS_ERR_NONE) {
		Error_Handler();
	}

    OSStart(&err);

	if (err != OS_ERR_NONE) {
		Error_Handler();
	}

	/* Infinite loop */
	while (DEF_TRUE) {
		;;
	}

	return 0;
}

/* Task ----------------------------------------------------------------------*/
static void programStartTask(void *p_arg)
{
	OS_ERR err;
	(void)p_arg;

	/* Inicializa todos os periféricos configurados */
	MX_GPIO_Init();
	MX_DMA_Init();
	MX_ADC2_Init();
	MX_DAC_Init();
	MX_TIM1_Init();
	MX_TIM2_Init();

	/* Habilita as saídas digitais */
	HAL_GPIO_WritePin(ENAOUT03_GPIO_Port, ENAOUT03_Pin | ENAOUT04_Pin, GPIO_PIN_SET);

	/* Cria a tarefa de controle do motor do carro transversal */
	carroTransversalCreateTask();

	/* Cria a tarefa de controle do motor da bobina */
	motorBobinaCreateTask();

	/* Infinite loop */
	while (DEF_TRUE) {
		HAL_GPIO_TogglePin(LED0_GPIO_Port, LED0_Pin);
		OSTimeDlyHMSM(0, 0, 1, 0, OS_OPT_TIME_HMSM_NON_STRICT + OS_OPT_TIME_DLY, &err);
		//OSTimeDly(500, OS_OPT_TIME_DLY, &err);
	}
}

/* Error ---------------------------------------------------------------------*/
void Error_Handler(void)
{
	/* User can add his own implementation to report the HAL error return state */
	__disable_irq();

	HAL_GPIO_WritePin(LED_ERRO_GPIO_Port, LED_ERRO_Pin, LED_ON);

	while (1) {
		;;
	}
}
