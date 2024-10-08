/*
 * perifericos.h
 *
 *  Created on: Aug 16, 2024
 *      Author: borto
 */

#ifndef INC_PERIFERICOS_H_
#define INC_PERIFERICOS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include "main.h"

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
void MX_GPIO_Init(void);
void MX_DMA_Init(void);
void MX_ADC2_Init(void);
void MX_DAC_Init(void);
void MX_TIM1_Init(void);
void MX_TIM2_Init(void);

/* Exported Handlers ---------------------------------------------------------*/
extern ADC_HandleTypeDef hadc2;
extern DMA_HandleTypeDef hdma_adc2;

extern DAC_HandleTypeDef hdac;
extern DMA_HandleTypeDef hdma_dac1;
extern DMA_HandleTypeDef hdma_dac2;

extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim2;


#ifdef __cplusplus
}
#endif

#endif /* INC_PERIFERICOS_H_ */
