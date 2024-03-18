/*
 * UART.h
 *
 *  Created on: Mar 11, 2024
 *      Author: minseok
 */

#ifndef SRC_UART_H_
#define SRC_UART_H_

#include "main.h"

void initUart(UART_HandleTypeDef *inHuart);
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);
uint8_t getChar();
int _write(int file, char *p, int len);


#endif /* SRC_UART_H_ */
