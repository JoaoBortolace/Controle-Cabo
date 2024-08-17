/*
 * opto.h
 *
 *  Created on: Aug 13, 2024
 *      Author: João Bortolace
 */

#ifndef INC_OPTO_H_
#define INC_OPTO_H_

#ifdef __cplusplus
extern "C"
{
#endif

/* Includes ------------------------------------------------------------------*/
#include "bsp.h"

/* Defines -------------------------------------------------------------------*/
#define OPTO_1_Pin 	14
#define OPTO_1_Port GPIOD
#define EXTI14_LINE
#define OPTO_1_EXTI LL_EXTI_LINE_14
#define OPTO_2_Pin 	15
#define OPTO_2_Port GPIOD
#define EXTI15_LINE
#define OPTO_2_EXTI LL_EXTI_LINE_15
#define OPTO_3_Pin 	3
#define OPTO_3_Port GPIOD
#define EXTI3_LINE
#define OPTO_3_EXTI LL_EXTI_LINE_3

#define OPTO_ON		false
#define OPTO_OFF	true

/* TypeDef -------------------------------------------------------------------*/
typedef enum
{
	LIBERANDO = 0,
	PUXANDO,
	IMOVEL,
} DIR_BOBINA;

/* Variaveis externas --------------------------------------------------------*/
extern int16_t passo;
extern int16_t cont;
extern bool andar;
extern DIR_BOBINA dir;


extern int32_t bobina_voltas;
extern int32_t carro_transversal_voltas;

/* Protótipos de funções exportadas ------------------------------------------*/
void OPTO_Init(void);


#ifdef __cplusplus
}
#endif /* extern "c" */

#endif /* INC_OPTO_H_ */
