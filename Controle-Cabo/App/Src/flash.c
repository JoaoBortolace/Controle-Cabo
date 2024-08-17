/*
 * flash.c
 *
 *  Created on: Aug 17, 2024
 *      Author: borto
 */

/* Includes ------------------------------------------------------------------*/
#include "flash.h"

/* Flash Data ----------------------------------------------------------------*/
__attribute__((__section__(".user_data"))) uint8_t userConfig[64];

extern uint32_t _user_data_start;
extern uint32_t _user_data_end;

const uint32_t userConfig_start = (uint32_t)&_user_data_start;
const uint32_t userConfig_end   = (uint32_t)&_user_data_end;

/* Functions -----------------------------------------------------------------*/
FLASH_STATUS Write_BYTE_Flash(uint32_t addr, uint8_t data)
{
	uint32_t flash_addr = addr + FLASH_START_ADDR;

	if (flash_addr < FLASH_END_ADDR) {
		HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, LED_ON);

		HAL_FLASH_Unlock();
	    __HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_EOP | FLASH_FLAG_OPERR | FLASH_FLAG_WRPERR | FLASH_FLAG_PGAERR | FLASH_FLAG_PGSERR );
	    FLASH_Erase_Sector(FLASH_SECTOR_23, VOLTAGE_RANGE_3);
	    HAL_FLASH_Program(TYPEPROGRAM_BYTE, flash_addr, data);
	    HAL_FLASH_Lock();

		HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, LED_ON);
	    return FLASH_OK;
	}

	return FLASH_ERRO;
}

FLASH_STATUS Write_HALFWORD_Flash(uint32_t addr, uint16_t data)
{
	uint32_t flash_addr = addr + FLASH_START_ADDR;

	if (flash_addr+1 <= FLASH_END_ADDR) {
		HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, LED_ON);

		HAL_FLASH_Unlock();
	    __HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_EOP | FLASH_FLAG_OPERR | FLASH_FLAG_WRPERR | FLASH_FLAG_PGAERR | FLASH_FLAG_PGSERR );
	    FLASH_Erase_Sector(FLASH_SECTOR_23, VOLTAGE_RANGE_3);
	    HAL_FLASH_Program(TYPEPROGRAM_HALFWORD, flash_addr, data);
	    HAL_FLASH_Lock();

		HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, LED_ON);
	    return FLASH_OK;
	}

	return FLASH_ERRO;
}

FLASH_STATUS Write_WORD_Flash(uint32_t addr, uint32_t data)
{
	uint32_t flash_addr = addr + FLASH_START_ADDR;

	if (flash_addr+3 <= FLASH_END_ADDR) {
		HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, LED_ON);

		HAL_FLASH_Unlock();
	    __HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_EOP | FLASH_FLAG_OPERR | FLASH_FLAG_WRPERR | FLASH_FLAG_PGAERR | FLASH_FLAG_PGSERR );
	    FLASH_Erase_Sector(FLASH_SECTOR_23, VOLTAGE_RANGE_3);
	    HAL_FLASH_Program(TYPEPROGRAM_WORD, flash_addr, data);
	    HAL_FLASH_Lock();

		HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, LED_ON);
		return FLASH_OK;
	}

	return FLASH_ERRO;
}

FLASH_STATUS Read_BYTE_Flash(uint32_t addr, uint8_t *data)
{
	uint32_t flash_addr = addr + FLASH_START_ADDR;

	if (flash_addr <= FLASH_END_ADDR) {
		HAL_FLASH_Lock();
		*data = *(const uint8_t*)addr;
		HAL_FLASH_Unlock();

		return FLASH_OK;
	}

	return FLASH_ERRO;
}

FLASH_STATUS Read_HALFWORD_Flash(uint32_t addr, uint16_t *data)
{
	uint32_t flash_addr = addr + FLASH_START_ADDR;

	if (flash_addr+1 <= FLASH_END_ADDR) {
		HAL_FLASH_Lock();
		*data = *(const uint16_t*)addr;
		HAL_FLASH_Unlock();

		return FLASH_OK;
	}

	return FLASH_ERRO;
}

FLASH_STATUS Read_WORD_Flash(uint32_t addr, uint32_t *data)
{
	uint32_t flash_addr = addr + FLASH_START_ADDR;

	if (flash_addr+3 <= FLASH_END_ADDR) {
		HAL_FLASH_Lock();
		*data = *(const uint32_t*)addr;
		HAL_FLASH_Unlock();

		return FLASH_OK;
	}

	return FLASH_ERRO;
}

FLASH_STATUS Read_BYTE_Config(uint32_t addr, uint8_t *data)
{
	uint32_t flash_addr = addr + userConfig_start;

	if (flash_addr <= userConfig_end) {
		*data = userConfig[flash_addr];

		return FLASH_OK;
	}

	return FLASH_ERRO;
}

FLASH_STATUS Read_HALFWORD_Config(uint32_t addr, uint16_t *data)
{
	uint32_t flash_addr = addr + userConfig_start;

	if (flash_addr+1 <= userConfig_end) {
		*data = (userConfig[flash_addr+1] << 8) | userConfig[flash_addr];

		return FLASH_OK;
	}

	return FLASH_ERRO;
}

FLASH_STATUS Read_WORD_Config(uint32_t addr, uint32_t *data)
{
	uint32_t flash_addr = addr + userConfig_start;

	if (flash_addr+3 <= userConfig_end) {
		*data = ((uint32_t) userConfig[flash_addr+3] << 24) | (userConfig[flash_addr+2] << 16) | (userConfig[flash_addr+1] << 8) | userConfig[flash_addr];

		return FLASH_OK;
	}

	return FLASH_ERRO;
}
