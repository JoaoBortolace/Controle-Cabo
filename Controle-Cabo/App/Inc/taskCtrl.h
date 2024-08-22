/*
 * taskCtrl.h
 *
 *  Created on: Aug 17, 2024
 *      Author: borto
 */

#ifndef INC_TASKCTRL_H_
#define INC_TASKCTRL_H_

#ifdef __cplusplus
extern "C"
{
#endif

/* Defines -------------------------------------------------------------------*/
#define TASK_NUMBER								3

/* Task Priority -------------------------------------------------------------*/
/* Menor o valor -> Maior a prioridade */
#define PROGRAM_START_TASK_PRIO                 5u
#define CARRO_TRANSVERSAL_TASK_PRIO            	(PROGRAM_START_TASK_PRIO - 1)
#define MOTOR_BOBINA_TASK_PRIO                  (PROGRAM_START_TASK_PRIO - 2)

/* Task Stack size -----------------------------------------------------------*/
#define PROGRAM_START_TASK_STK_SIZE             (256u)
#define CARRO_TRANSVERSAL_TASK_STK_SIZE         (256u)
#define MOTOR_BOBINA_TASK_STK_SIZE              (256u)

/* Flags ---------------------------------------------------------------------*/
#define MOTOR_BOBINA_ADC_RDY  					(OS_FLAGS)0x0001
#define MOTOR_BOBINA_LIBERANDO					(OS_FLAGS)0x0002
#define MOTOR_BOBINA_PUXANDO					(OS_FLAGS)0x0004

#ifdef __cplusplus
}
#endif /* extern "c" */

#endif /* INC_TASKCTRL_H_ */
