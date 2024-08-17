/*
 * carroTransversal.h
 *
 *  Created on: Aug 16, 2024
 *      Author: João Bortolace
 */

#ifndef __CARRO_TRANSVERSAL_H
#define __CARRO_TRANSVERSAL_H


#ifdef __cplusplus
extern "C"
{
#endif

/* Private includes ----------------------------------------------------------*/
#include "main.h"

/* Private define ------------------------------------------------------------*/
#define CARRO_TRANSVERSAL_TASK_PRIO            	(PROGRAM_START_TASK_PRIO - 1)
#define CARRO_TRANSVERSAL_TASK_STK_SIZE         (256u)

#define BOBINA_TICK_VOLTA						(8u)
#define CARRO_TRANSVERSAL_TICK_VOLTA			(20u)

/* TypeDef -------------------------------------------------------------------*/
typedef enum {
	ESQUERDA = 0,
	DIREITA,
	PARADO,
} CARRO_TRANSVERSAL_CTRL;

/* Exported functions prototypes ---------------------------------------------*/
void carroTransversalCreateTask(void);


#ifdef __cplusplus
}
#endif


#endif /* __CARRO_TRANSVERSAL_H */
