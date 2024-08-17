/*
 * motor_bobina.h
 *
 *  Created on: Jul 16, 2024
 *      Author: João Bortolace
 *
 */

#ifndef INC_MOTOR_BOBINA_H_
#define INC_MOTOR_BOBINA_H_

#ifdef __cplusplus
extern "C"
{
#endif

/* Defines -------------------------------------------------------------------*/
#define MOTOR_BOBINA_SET_REF_Pin	SW0_Pin
#define MOTOR_BOBINA_SET_REF_Port	SW0_Port
#define MOTOR_BOBINA_SET_REF_EXTI	SW0_EXTI

#define MOTOR_BOBINA_DAC_ALIGN		bit12_Direita
#define MOTOR_BOBINA_DAC_CHANNEL	DAC_CANAL_1

#define MOTOR_BOBINA_DIR_Pin		DIGOUT7_Pin
#define MOTOR_BOBINA_DIR_Port 		DIGOUT7_Port
#define MOTOR_BOBINA_DIR_CLOCKWISE 	1

#if defined(MOTOR_BOBINA_DIR_CLOCKWISE) && MOTOR_BOBINA_DIR_CLOCKWISE == 0
#define MOTOR_BOBINA_DIR_SET_CLOCKWISE			BSP_GPIO_ResetPin(MOTOR_BOBINA_DIR_Port, MOTOR_BOBINA_DIR_Pin)
#define MOTOR_BOBINA_DIR_SET_COUNTER_CLOCKWISE	BSP_GPIO_SetPin(MOTOR_BOBINA_DIR_Port, MOTOR_BOBINA_DIR_Pin)
#else
#define MOTOR_BOBINA_DIR_SET_CLOCKWISE			BSP_GPIO_SetPin(MOTOR_BOBINA_DIR_Port, MOTOR_BOBINA_DIR_Pin)
#define MOTOR_BOBINA_DIR_SET_COUNTER_CLOCKWISE	BSP_GPIO_ResetPin(MOTOR_BOBINA_DIR_Port, MOTOR_BOBINA_DIR_Pin)
#endif

#define MOTOR_BOBINA_ENABLE_Pin		DIGOUT6_Pin
#define MOTOR_BOBINA_ENABLE_Port	DIGOUT6_Port

#define MOTOR_BOBINA_TURN_OFF_BUT_Port SW3_Port
#define MOTOR_BOBINA_TURN_OFF_BUT_Pin  SW3_Pin

#define ADC2_Interrupt
#define POT_TENSAO_MOTOR_ADC		ADC2
#define POT_TENSAO_MOTOR_CANAL		6
#define POT_TENSAO_MOTOR_Port		ADC2_IN6_Port
#define POT_TENSAO_MOTOR_Pin		ADC2_IN6_Pin
#define POT_TENSAO_MOTOR_AMOSTRAGEM	Cycles_112

/* Includes ------------------------------------------------------------------*/
#include "bsp.h"

/* Protótipos de funções exportadas ------------------------------------------*/
void Motor_Bobina_Init(void);


#ifdef __cplusplus
}
#endif /* extern "c" */

#endif /* INC_MOTOR_BOBINA_H_ */
