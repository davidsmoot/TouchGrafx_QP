/*
 * user_uart.h
 *
 *  Created on: May 5, 2021
 *      Author: dsmoot
 */

#ifndef APP_COMMON_INCLUDE_USER_UART_H_
#define APP_COMMON_INCLUDE_USER_UART_H_

#include "stm32h7xx_hal.h"


#if defined (CORE_CM7)

	#define QSPY_UART_HANDLE huart1
#elif defined (CORE_CM4)
	#define QSPY_UART_HANDLE huart8
#endif


extern UART_HandleTypeDef QSPY_UART_HANDLE;
void TakeQSPYTxMutex();
void StartInterruptReceiveOfSingleByteOnQSPYUart();
bool IsQSPYUartReadyToTxMore();



#endif /* APP_COMMON_INCLUDE_USER_UART_H_ */
