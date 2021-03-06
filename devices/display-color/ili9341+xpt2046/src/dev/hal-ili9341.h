/*
* Copyright (c) 2018 Vladimir Alemasov
* All rights reserved
*
* This program and the accompanying materials are distributed under 
* the terms of GNU General Public License version 2 
* as published by the Free Software Foundation.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*/

#ifndef HAL_ILI9341_H_
#define HAL_ILI9341_H_

#if !defined ILI9341_SPI && !defined ILI9341_8080I
#error "At least one ILI9341 display must be defined: ILI9341_SPI or ILI9341_8080I"
#elif defined ILI9341_SPI && defined ILI9341_8080I
#error "One ILI9341 display must be defined, not both"
#endif

void hal_ili9341_init(void);
void hal_ili9341_reset(void);
void hal_ili9341_command(void);
void hal_ili9341_data(void);
void hal_ili9341_init_dma(void);
void hal_ili9341_write_dma(uint8_t *txbuf, uint32_t length);

#ifdef ILI9341_8080I
#define hal_ili9341_reset()
#define hal_ili9341_select()
#define hal_ili9341_release()
void hal_ili9341_tx(uint16_t data);
#define hal_ili9341_tx_complete()
void *hal_ili9341_get_data_addr(void);
#endif

#ifdef ILI9341_SPI
void hal_ili9341_reset(void);
void hal_ili9341_select(void);
void hal_ili9341_release(void);
void hal_ili9341_tx(uint8_t data);
void hal_ili9341_tx_complete(void);
#endif

#endif // HAL_ILI9341_H_
