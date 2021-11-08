/*
 * bsp.cpp
 *
 *  Created on: May 5, 2021
 *      Author: dsmoot
 */

#include "qpcpp.h"
#include "bsp.h"
#include "reset.h"
#include "main.h"
#include <cstring>
#include <stdio.h>
#include "qspy_bsp.h"
#include "user_uart_drv.h"
#include "stm32h7xx_hal_gpio.h"

volatile bool qp_running = false;

namespace COMMON {

#ifdef Q_SPY
static BSP l_BSP {};
#endif

static char projMsg[] = "H747i-Disco Dev Kit Prototype\n\r";
static char startMsg[] = " Application\n\r";
static char starMsg[]  = "****************\n\r";



extern "C" void HAL_IncTick(void)
{
	uwTick += uwTickFreq; //keeping HAL functionality at least for now.

	if (qp_running) {     // only call QP tick if QP is initialized
		QP::QF::TICK_X(0U, &COMMON::l_BSP); // time events for rate 0
	}


	QV_ARM_ERRATUM_838869(); //todo investigate what this is and necessity.
}


void BSP::init(void) {

#ifdef Q_SPY
	StartInterruptReceiveOfSingleByteOnQSPYUart();
#endif

    QS_OBJ_DICTIONARY(&COMMON::l_BSP);

    COMMON::QSpy::uartDisplayText(starMsg, strlen(starMsg) );
    COMMON::QSpy::uartDisplayText(projMsg, strlen(projMsg) );
    COMMON::QSpy::uartDisplayText(startMsg, strlen(startMsg) );

    COMMON::QSpy::uartDisplayText( (char *)"\n\r\n\r", strlen("\n\r\n\r") );

}

//............................................................................
void BSP::terminate(int16_t result) {
    (void)result;
}

void BSP::onIdle() {
}

void BSP::BSP_ledOn()
{
	HAL_GPIO_WritePin(BSP_LED_PORT, BSP_LED_PIN, GPIO_PIN_SET);
}

void BSP::BSP_ledOff()
{
	HAL_GPIO_WritePin(BSP_LED_PORT, BSP_LED_PIN, GPIO_PIN_RESET);
}

} //namespace COMMON

// namespace QP **************************************************************
namespace QP {


// QF callbacks ==============================================================


//............................................................................
void QF::onCleanup(void) {
}

void QV::onIdle(void) { // CAUTION: called with interrupts DISABLED, NOTE01

    COMMON::QSpy::onIdle();
    QF_INT_ENABLE();
    COMMON::BSP::onIdle();
}

static char resetMsg[]  = "ERROR: Q_onAssert software reset!\n\r";

//............................................................................
extern "C" void Q_onAssert(char const *module, int loc) {
    char buf[64];
    //
    // NOTE: add here your application-specific error handling
    //
    //(void)module;
    //(void)loc;
    QS_ASSERTION(module, loc, static_cast<uint32_t>(10000U));

    COMMON::QSpy::uartDisplayString(resetMsg);
    COMMON::QSpy::uartDisplayString(module);
    sprintf(buf, " location=%d", loc);
    COMMON::QSpy::uartDisplayString(buf);
    COMMON::QSpy::uartDisplayString("\r\n");

    __asm("  bkpt #0"); // breakpoint if debugger is attached.

    software_reset();
}

} //namespace QP
