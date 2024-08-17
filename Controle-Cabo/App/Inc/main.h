/*
 * main.h
 *
 *  Created on: Aug 15, 2024
 *      Author: borto
 */

#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C"
{
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"
#include <os.h>
#include <stdlib.h>
#include <stdbool.h>

/* Private includes ----------------------------------------------------------*/
#include "perifericos.h"
#include "flash.h"
#include "taskCtrl.h"
#include "bobina.h"
#include "carroTransversal.h"

/* Exported types ------------------------------------------------------------*/


/* Exported variables --------------------------------------------------------*/
extern OS_FLAG_GRP flagsGrp;

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);
void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Defines -------------------------------------------------------------------*/
#define MOTOR_CARRO_TRANSVERSAL_DIR1_Pin 					GPIO_PIN_5
#define MOTOR_CARRO_TRANSVERSAL_DIR1_GPIO_Port 				GPIOE
#define MOTOR_CARRO_TRANSVERSAL_DIR2_Pin 					GPIO_PIN_6
#define MOTOR_CARRO_TRANSVERSAL_DIR2_GPIO_Port 				GPIOE
#define MOTOR_CARRO_TRANSVERSAL_PWM_TIM						TIM1
#define MOTOR_CARRO_TRANSVERSAL_PWM_Channel 				TIM_CHANNEL_4
#define MOTOR_CARRO_TRANSVERSAL_PWM_Pin 					GPIO_PIN_14
#define MOTOR_CARRO_TRANSVERSAL_PWM_GPIO_Port 				GPIOE

#define MOTOR_BOBINA_EN_Pin 								GPIO_PIN_8
#define MOTOR_BOBINA_EN_GPIO_Port 							GPIOF
#define MOTOR_BOBINA_DIR_Pin 								GPIO_PIN_9
#define MOTOR_BOBINA_DIR_GPIO_Port 							GPIOF
#define MOTOR_BOBINA_TENSAO_Pin 							GPIO_PIN_6
#define MOTOR_BOBINA_TENSAO_GPIO_Port 						GPIOA
#define MOTOR_BOBINA_VEL_Pin 								GPIO_PIN_4
#define MOTOR_BOBINA_VEL_GPIO_Port 							GPIOA
#define MOTOR_BOBINA_VEL_DAC_CHANNEL 						DAC_CHANNEL_1

#define MOTOR_POLIA_EN_Pin 									GPIO_PIN_9
#define MOTOR_POLIA_EN_GPIO_Port 							GPIOE
#define MOTOR_POLIA_DIR_Pin 								GPIO_PIN_11
#define MOTOR_POLIA_DIR_GPIO_Port 							GPIOE
#define MOTOR_POLIA_TENSAO_Pin 								GPIO_PIN_0
#define MOTOR_POLIA_TENSAO_GPIO_Port 						GPIOC
#define MOTOR_POLIA_VEL_Pin 								GPIO_PIN_5
#define MOTOR_POLIA_VEL_GPIO_Port 							GPIOA
#define MOTOR_POLIA_VEL_DAC_CHANNEL 						DAC_CHANNEL_2

#define LED_ON												GPIO_PIN_RESET
#define LED_OFF												GPIO_PIN_SET
#define LED0_Pin 											GPIO_PIN_13
#define LED0_GPIO_Port 										GPIOF
#define LED1_Pin 											GPIO_PIN_14
#define LED1_GPIO_Port 										GPIOF
#define LED2_Pin 											GPIO_PIN_15
#define LED2_GPIO_Port										GPIOF
#define LED3_Pin 											GPIO_PIN_0
#define LED3_GPIO_Port 										GPIOG
#define LED4_Pin 											GPIO_PIN_1
#define LED4_GPIO_Port 										GPIOG
#define LED_ERRO_Pin										LED1_Pin
#define LED_ERRO_GPIO_Port									LED1_GPIO_Port

#define ENAOUT03_Pin 										GPIO_PIN_10
#define ENAOUT03_GPIO_Port 									GPIOE
#define ENAOUT04_Pin 										GPIO_PIN_12
#define ENAOUT04_GPIO_Port 									GPIOE

#define SW_ON												GPIO_PIN_RESET
#define SW_OFF												GPIO_PIN_SET
#define SW0_Pin 											GPIO_PIN_10
#define SW0_GPIO_Port 										GPIOD
#define SW1_Pin 											GPIO_PIN_11
#define SW1_GPIO_Port 										GPIOD
#define SW2_Pin 											GPIO_PIN_12
#define SW2_GPIO_Port 										GPIOD
#define SW3_Pin 											GPIO_PIN_13
#define SW3_GPIO_Port 										GPIOD

#define OPTO_ON												GPIO_PIN_RESET
#define OPTO_OFF											GPIO_PIN_SET
#define OPTO_1_Pin 											GPIO_PIN_14
#define OPTO_1_GPIO_Port 									GPIOD
#define OPTO_1_EXTI_IRQn 									EXTI15_10_IRQn
#define OPTO_2_Pin 											GPIO_PIN_15
#define OPTO_2_GPIO_Port 									GPIOD
#define OPTO_2_EXTI_IRQn 									EXTI15_10_IRQn
#define OPTO_3_Pin 											GPIO_PIN_3
#define OPTO_3_GPIO_Port 									GPIOD
#define OPTO_3_EXTI_IRQn 									EXTI3_IRQn

#define FIM_CURSO_1_Pin 									GPIO_PIN_3
#define FIM_CURSO_1_GPIO_Port 								GPIOB
#define FIM_CURSO_2_Pin 									GPIO_PIN_15
#define FIM_CURSO_2_GPIO_Port 								GPIOA

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
