/*
 * user_uart_drv.c
 *
 *  Created on: May 5, 2021
 *      Author: dsmoot
 */
#include "user_uart_drv.h"
#include "qpcpp.h"
#include <stdint.h>

bool QSPY_uart_ready_for_more_data = true;

uint8_t QSPYReceivedByte;
uint8_t MoogReceivedByte;

void StartInterruptReceiveOfSingleByteOnQSPYUart()
{
	UART_Start_Receive_IT(&QSPY_UART_HANDLE, &QSPYReceivedByte, 1);
}


extern "C" {
void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
{
	if (huart->Instance == QSPY_UART_HANDLE.Instance)
		QSPY_uart_ready_for_more_data = true;
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {

#ifdef Q_SPY
	if (QSPY_UART_HANDLE.Instance == huart->Instance) {

		QP::QS::rxPut(QSPYReceivedByte);
		StartInterruptReceiveOfSingleByteOnQSPYUart();

	}
#endif

}

void HAL_UART_ErrorCallback(UART_HandleTypeDef *huart) {
#ifdef Q_SPY
	if (QSPY_UART_HANDLE.Instance == huart->Instance) {
		StartInterruptReceiveOfSingleByteOnQSPYUart();
	}
#endif

}

}

bool IsQSPYUartReadyToTxMore() {
	return QSPY_uart_ready_for_more_data;
}

void TakeQSPYTxMutex() {
	QSPY_uart_ready_for_more_data = false;
}

