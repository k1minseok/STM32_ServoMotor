/*
 * UART.c
 *
 *  Created on: Mar 11, 2024
 *      Author: minseok
 */

#include "UART.h"
#include <stdio.h>

UART_HandleTypeDef *myHuart;

#define rxBufferMax 255

int rxBufferGp;			// get pointer (read)
int rxBufferPp;			// put pointer (write)
uint8_t rxBuffer[rxBufferMax];
uint8_t rxChar;

uint8_t i = 0;

// Device init
void initUart(UART_HandleTypeDef *inHuart)		// Interrupt setting
{
	myHuart = inHuart;
	HAL_UART_Receive_IT(myHuart, &rxChar, 1);
}

// process received character
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	rxBuffer[rxBufferPp++] = rxChar;
	rxBufferPp %= rxBufferMax;
	HAL_UART_Receive_IT(myHuart, &rxChar, 1);
}

// get character form buffer
uint8_t getChar()
{
	uint8_t result;
	if(rxBufferGp == rxBufferPp) return 0;
	result = rxBuffer[rxBufferGp++];
	rxBufferGp %= rxBufferMax;
	return result;
}

int _write(int file, char *p, int len)
{
	HAL_UART_Transmit(myHuart, p, len, 10);
	return len;
}
