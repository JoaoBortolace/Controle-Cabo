/*
 * bsp_flash.c
 *
 *  Created on: Jul 16, 2024
 *      Author: João Bortolace
 *  Referências:
 *  	https://os.mbed.com/users/olympux/code/eeprom_flash//file/e593ae8ff81d/eeprom_flash.cpp/
 *  	https://stackoverflow.com/questions/44443619/how-to-write-read-to-flash-on-stm32f4-cortex-m4
 *  	https://controllerstech.com/flash-programming-in-stm32/
 */


#include "bsp_flash.h"
#include "bsp.h"

HAL_StatusTypeDef BSP_Write_Flash_Byte(uint32_t addr, uint8_t data)
{
	addr += FLASH_START_ADDRESS;
	if (addr <= FLASH_END_ADDRESS)
	{
		HAL_FLASH_Unlock();
		__HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_EOP | FLASH_FLAG_OPERR | FLASH_FLAG_WRPERR | FLASH_FLAG_PGAERR | FLASH_FLAG_PGSERR);
		FLASH_Erase_Sector(FLASH_SECTOR_6, VOLTAGE_RANGE_3);
		HAL_StatusTypeDef status = HAL_FLASH_Program(FLASH_TYPEPROGRAM_BYTE, addr, data);
		HAL_FLASH_Lock();

		return status;

	}
	return HAL_ERROR;
}

HAL_StatusTypeDef BSP_Write_Flash_HalfWord(uint32_t addr, uint16_t data)
{
	addr += FLASH_START_ADDRESS;
	if (addr <= FLASH_END_ADDRESS - 1)
	{
		HAL_FLASH_Unlock();
		__HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_EOP | FLASH_FLAG_OPERR | FLASH_FLAG_WRPERR | FLASH_FLAG_PGAERR | FLASH_FLAG_PGSERR);
		FLASH_Erase_Sector(FLASH_SECTOR_6, VOLTAGE_RANGE_3);
		HAL_StatusTypeDef status = HAL_FLASH_Program(FLASH_TYPEPROGRAM_HALFWORD, addr, data);
		HAL_FLASH_Lock();

		return status;
	}
	return HAL_ERROR;
}

HAL_StatusTypeDef BSP_Write_Flash_Word(uint32_t addr, uint32_t data)
{
	addr += FLASH_START_ADDRESS;
	if (addr <= FLASH_END_ADDRESS - 3)
	{
		HAL_FLASH_Unlock();
		__HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_EOP | FLASH_FLAG_OPERR | FLASH_FLAG_WRPERR | FLASH_FLAG_PGAERR | FLASH_FLAG_PGSERR);
		FLASH_Erase_Sector(FLASH_SECTOR_6, VOLTAGE_RANGE_3);
		HAL_StatusTypeDef status = HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, addr, data);
		HAL_FLASH_Lock();

		return status;
	}
	return HAL_ERROR;
}

uint8_t BSP_Read_Flash_Byte(uint32_t addr)
{
	addr += FLASH_START_ADDRESS;

	if (addr <= FLASH_END_ADDRESS)
	{
		HAL_FLASH_Lock();
		uint8_t data =  *(__IO uint8_t*)addr;
		HAL_FLASH_Unlock();
		return data;
	}

	BSP_Error_Handler();

	return 0;
}

uint16_t BSP_Read_Flash_HalfWord(uint32_t addr)
{
	addr += FLASH_START_ADDRESS;

	if (addr <= FLASH_END_ADDRESS - 1)
	{
		HAL_FLASH_Lock();
		uint16_t data =  *(__IO uint16_t*)addr;
		HAL_FLASH_Unlock();
		return data;
	}

	BSP_Error_Handler();

	return 0;
}

uint32_t BSP_Read_Flash_Word(uint32_t addr)
{
	addr += FLASH_START_ADDRESS;

	if (addr <= FLASH_END_ADDRESS - 3)
	{
		HAL_FLASH_Lock();
		uint32_t data =  *(__IO uint32_t*)addr;
		HAL_FLASH_Unlock();
		return data;
	}

	BSP_Error_Handler();

	return 0;
}
