/*
 * main.h
 *
 *  Created on: Jun 27, 2024
 *      Author: borto
 */

#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C"
{
#endif

/* Defines -------------------------------------------------------------------*/
#define FIM_CURSO_2_Pin 	DIGIN1_Pin
#define FIM_CURSO_2_Port 	DIGIN1_Port
#define FIM_CURSO_1_Pin 	DIGIN4_Pin
#define FIM_CURSO_1_Port 	DIGIN4_Port

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"
#include <stdbool.h>
#include <stdlib.h>

/* Private includes ----------------------------------------------------------*/
#include "bsp.h"
#include "motor_bobina.h"
#include "motor_transversal.h"
#include "opto.h"

/* Exported types ------------------------------------------------------------*/


/* Exported constants --------------------------------------------------------*/


/* Exported macro ------------------------------------------------------------*/


/* Exported functions prototypes ---------------------------------------------*/



#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
