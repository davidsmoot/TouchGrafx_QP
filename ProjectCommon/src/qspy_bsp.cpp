/*
 * qspy_bsp.cpp
 *
 *  Created on: May 5, 2021
 *      Author: dsmoot
 */

#include "qpcpp.hpp"
#include "user_uart_drv.h"
#include "reset.h"
#include <stdint.h>
#include <cstring>
#include <array>
#include "qspy_bsp.h"
#include "Project.h"
#include "stm32h7xx_hal_uart.h"

namespace COMMON {
namespace QSpy {

#ifdef Q_SPY
static void MaybeSendTxBlock() {

	if (IsQSPYUartReadyToTxMore() ) {
		uint16_t bytesToSend = 50;
		uint8_t const *bufPtr = QP::QS::getBlock(&bytesToSend);
		if (bufPtr != nullptr)
		{
			TakeQSPYTxMutex();
			if (HAL_OK != HAL_UART_Transmit_IT(&QSPY_UART_HANDLE, const_cast<uint8_t *>(bufPtr), bytesToSend))
			{
				//todo do something!
			}
		}
	}

}
#endif

// Call with interrupts disabled.
void onIdle() {
#ifdef Q_SPY
	// Service the QSpy processing.
	QP::QS::rxParse();

	MaybeSendTxBlock();
#endif
}

bool uartDisplayText(const char* text, uint32_t length) {
#ifdef Q_SPY
	// TODO(jec):  Enumerate application-specific QS IDs in PlatformCommon / project.h.
	if (length < strlen(text)){
		const char *Err = "Unterminated / too long string error";
		QS_BEGIN_ID(QSUserMessages::DisplayText, QP::QS_AP_ID)
		QS_STR(Err);
		QS_END()
	}
	else {
		QS_BEGIN_ID(QSUserMessages::DisplayText, QP::QS_AP_ID)
		QS_STR(text);
		QS_END()
	}

#else

#endif
	return true;
}

bool uartDisplayString(const char* string) {
	return uartDisplayText(string, strlen(string));
}


}	//namespace QSPY
}	//namespace COMMON

namespace QP {


// QS callbacks =============================================================
// TODO:  Move some of this functionality into the ports, because the backend
// will be uart on the device, and something else on the win32 build.

#ifdef Q_SPY

bool QS::onStartup(const void* userData) {
	// Allocate static Tx and Rx buffers for QSpy.  Start at 4K each in the
	// absence of compelling reason otherwise.  If the buffers are too small,
	// you might lose data when there are big bursts.  If the buffers are too large
	// you might exceed the RAM on the device.
	static constexpr uint16_t buf_size = 4096;
	static std::array<uint8_t, buf_size> qspyRxBuf {};
	static std::array<uint8_t, buf_size> qspyTxBuf {};

	QS::initBuf(qspyTxBuf.data(), static_cast<uint16_t>(qspyTxBuf.size()));
	QS::rxInitBuf(qspyRxBuf.data(), static_cast<uint16_t>(qspyRxBuf.size()));

	StartInterruptReceiveOfSingleByteOnQSPYUart();

	return true;
}

void QS::onCleanup() {
	// Cleanup not required.
}

// Flush QS buffer to host--This sends the contents of the QSpy buffer
// to the uart UART peripheral.
// Note: This can be called from ISR if QS_ASSERT, so need proper critical
// section wrappers
void QS::onFlush() {
	uint16_t bytesToSend = 50;

	uint32_t dummy_arg;

	QF_CRIT_ENTRY(dummy_arg);

	uint8_t const *bufPtr = QS::getBlock(&bytesToSend);
	while (bufPtr != nullptr) {
		QF_CRIT_EXIT(dummy_arg);
		HAL_UART_Transmit(&QSPY_UART_HANDLE, const_cast<uint8_t *>(bufPtr), bytesToSend, 100);
		QF_CRIT_ENTRY(dummy_arg);
		bytesToSend = 50;
		bufPtr = QP::QS::getBlock(&bytesToSend);
	}
	QF_CRIT_EXIT(dummy_arg);
}


/* QS::onGetTime() provided by QUTest */
#ifndef Q_UTEST
QP::QSTimeCtr QS::onGetTime() {
	//todo implement for this platform
	//return rti_drv_get_current_tick();
	return 0;
}
#endif

// Reset the target--Do software reset?
void QS::onReset() {
	software_reset();
}

void QS::onCommand(std::uint8_t cmdId,
		std::uint32_t param1,
		std::uint32_t param2,
		std::uint32_t param3) {
// todo	COMMON::TestProtocol::HandleCommand(cmdId, param1, param2, param3);
	return;
}

#endif /* Q_SPY */

#ifdef Q_UTEST
void QS::onTestLoop() {
	// This flag is apparently both a notification that the stack contains
	// this function, and also a keepGoing flag for this function.
	rxPriv_.inTestLoop = true;
	while (rxPriv_.inTestLoop) {
		rxParse();
		COMMON::QSpy::MaybeSendTxBlock();
	}

	rxPriv_.inTestLoop = true;
}

void QS::onTestEvt(QP::QEvt* e) {
	return;
}

#endif /* Q_UTEST */

} // namespace QP


