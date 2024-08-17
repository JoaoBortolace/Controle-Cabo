/*
 * flash.h
 *
 *  Created on: Aug 17, 2024
 *      Author: borto
 */

#ifndef INC_FLASH_H_
#define INC_FLASH_H_

#ifdef __cplusplus
extern "C"
{
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Defines -------------------------------------------------------------------*/
#define FLASH_START_ADDR		0x081E0000
#define FLASH_END_ADDR			0x081FFFFF

/* TypeDef -------------------------------------------------------------------*/
typedef enum {
	FLASH_OK = 0,
	FLASH_ERRO,
} FLASH_STATUS;

/* Exported functions prototypes ---------------------------------------------*/
FLASH_STATUS Write_BYTE_Flash(uint32_t addr, uint8_t data);
FLASH_STATUS Write_HALFWORD_Flash(uint32_t addr, uint16_t data);
FLASH_STATUS Write_WORD_Flash(uint32_t addr, uint32_t data);

FLASH_STATUS Read_BYTE_Flash(uint32_t addr, uint8_t *data);
FLASH_STATUS Read_HALFWORD_Flash(uint32_t addr, uint16_t *data);
FLASH_STATUS Read_WORD_Flash(uint32_t addr, uint32_t *data);

FLASH_STATUS Read_BYTE_Config(uint32_t addr, uint8_t *data);
FLASH_STATUS Read_HALFWORD_Config(uint32_t addr, uint16_t *data);
FLASH_STATUS Read_WORD_Config(uint32_t addr, uint32_t *data);

#ifdef __cplusplus
}
#endif /* extern "c" */

#endif /* INC_FLASH_H_ */
