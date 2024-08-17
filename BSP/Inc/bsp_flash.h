/*
 * bsp_flash.h
 *
 *  Created on: Jul 16, 2024
 *      Author: João Bortolace
 *  Referências:
 *  	https://os.mbed.com/users/olympux/code/eeprom_flash//file/e593ae8ff81d/eeprom_flash.cpp/
 *  	https://stackoverflow.com/questions/44443619/how-to-write-read-to-flash-on-stm32f4-cortex-m4
 *  	https://controllerstech.com/flash-programming-in-stm32/
 */

#ifndef INC_BSP_FLASH_H_
#define INC_BSP_FLASH_H_

#ifdef __cplusplus
extern "C"
{
#endif

/* Includes -------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Defines -------------------------------------------------------------------*/
#define FLASH_START_ADDRESS  	((uint32_t) 0x08040000)
#define FLASH_END_ADDRESS   	((uint32_t) 0x0805FFFF)

/* Protótipos de funções exportadas ------------------------------------------*/
HAL_StatusTypeDef BSP_Write_Flash_Byte(uint32_t addr, uint8_t data);
HAL_StatusTypeDef BSP_Write_Flash_HalfWord(uint32_t addr, uint16_t data);
HAL_StatusTypeDef BSP_Write_Flash_Word(uint32_t addr, uint32_t data);

uint8_t BSP_Read_Flash_Byte(uint32_t addr);
uint16_t BSP_Read_Flash_HalfWord(uint32_t addr);
uint32_t BSP_Read_Flash_Word(uint32_t addr);


#ifdef __cplusplus
}
#endif /* extern "c" */

#endif /* INC_BSP_FLASH_H_ */
