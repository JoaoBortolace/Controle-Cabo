/*
 * bsp.h
 *
 *  Created on: Jun 27, 2024
 *      Author: borto
 */

#ifndef BSP_INC_BSP_H_
#define BSP_INC_BSP_H_


#ifdef __cplusplus
extern "C"
{
#endif

/* Defines -------------------------------------------------------------------*/
#define LED_ERROR_Port LED1_Port
#define LED_ERROR_Pin  LED1_Pin

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"
#include "bsp_gpio.h"
#include "bsp_extInt.h"
#include "bsp_adc.h"
#include "bsp_dac.h"
#include "bsp_tim.h"
#include "bsp_pwm.h"
#include "bsp_flash.h"
#include "main.h"

/* Protótipos de funções exportadas ------------------------------------------*/
void BSP_Error_Handler(void);
void BSP_Init(void);

#ifdef __cplusplus
}
#endif

#endif /* BSP_INC_BSP_H_ */
