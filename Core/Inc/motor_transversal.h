/*
 * motor_transversal.h
 *
 *  Created on: Aug 13, 2024
 *      Author: João Bortolace
 */

#ifndef INC_MOTOR_TRANSVERSAL_H_
#define INC_MOTOR_TRANSVERSAL_H_

#ifdef __cplusplus
extern "C"
{
#endif

#define MOTOR_CARRO_TRANSVERSAL_DIR1_Pin 	DIGOUT4_Pin
#define MOTOR_CARRO_TRANSVERSAL_DIR1_Port 	DIGOUT4_Port
#define MOTOR_CARRO_TRANSVERSAL_DIR2_Pin 	DIGOUT5_Pin
#define MOTOR_CARRO_TRANSVERSAL_DIR2_Port 	DIGOUT5_Port

#define MOTOR_CARRO_TRANSVERSAL_PWM_Pin 	DIGOUT0_Pin
#define MOTOR_CARRO_TRANSVERSAL_PWM_Port 	DIGOUT0_Port
#define MOTOR_CARRO_TRANSVERSAL_PWM_TIMER 	DIGOUT0_TIMER
#define MOTOR_CARRO_TRANSVERSAL_PWM_CANAL 	PWM_1

/* TypeDef -------------------------------------------------------------------*/
typedef enum
{
	HORARIO = 0,
	ANTI_HORARIO,
	FREIO,
	PARADO
} MOTOR_DIR;

/* Includes ------------------------------------------------------------------*/
#include "bsp.h"

/* Protótipos de funções exportadas ------------------------------------------*/
void Motor_Transversal_Init(void);
void Motor_Transversal_Ctrl(MOTOR_DIR ctrl);
void Motor_Transversal_ToggleDir(void);

MOTOR_DIR Motor_Transversal_GetDir(void);

#ifdef __cplusplus
}
#endif /* extern "c" */

#endif /* INC_MOTOR_TRANSVERSAL_H_ */
