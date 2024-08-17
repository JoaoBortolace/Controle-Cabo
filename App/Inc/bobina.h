/*
 * bobina.h
 *
 *  Created on: Aug 16, 2024
 *      Author: João Bortolace
 */

#ifndef INC_BOBINA_H_
#define INC_BOBINA_H_

#ifdef __cplusplus
extern "C"
{
#endif

/* Private includes ----------------------------------------------------------*/
#include "main.h"

/* Private define ------------------------------------------------------------*/
#define MOTOR_BOBINA_TASK_PRIO                  (PROGRAM_START_TASK_PRIO - 2)
#define MOTOR_BOBINA_TASK_STK_SIZE              (256u)

#define MOTOR_BOBINA_ADC_RDY  					(OS_FLAGS)0x0001
#define MOTOR_BOBINA_LIBERANDO					(OS_FLAGS)0x0002
#define MOTOR_BOBINA_PUXANDO					(OS_FLAGS)0x0003

#define MOTOR_BOBINA_EN_ON						GPIO_PIN_SET
#define MOTOR_BOBINA_EN_OFF						GPIO_PIN_RESET

#define MOTOR_BOBINA_CLOCKWISE					GPIO_PIN_SET
#define MOTOR_BOBINA_COUNTER_CLOCKWISE			GPIO_PIN_RESET

/* Exported functions prototypes ---------------------------------------------*/
void motorBobinaCreateTask(void);


#ifdef __cplusplus
}
#endif /* extern "c" */

#endif /* INC_BOBINA_H_ */
