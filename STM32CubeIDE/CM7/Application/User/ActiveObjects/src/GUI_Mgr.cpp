/*
 * GUI_Mgr.cpp
 *
 * Created on: Oct 15, 2021
 *     Author: David Smoot
 */

#include "GUI_Mgr.h"
#include "bsp.h"
#include "stm32h7xx_hal_dsi.h"

#include <texts/TypedTextDatabase.hpp>
#include <fonts/ApplicationFontProvider.hpp>
#include <gui/common/FrontendHeap.hpp>
#include <BitmapDatabase.hpp>
#include <platform/driver/lcd/LCD24bpp.hpp>
#include <touchgfx/hal/OSWrappers.hpp>
#include <STM32DMA.hpp>
#include <TouchGFXHAL.hpp>
#include <STM32TouchController.hpp>
#include <stm32h7xx_hal.h>

Q_DEFINE_THIS_FILE

#define LCD_OTM8009A_ID  ((uint32_t) 0)
namespace COMMON {

static GUI_Mgr l_GUI_Mgr;
QP::QActive * const AO_GUI_Mgr = &l_GUI_Mgr;



GUI_Mgr::GUI_Mgr() : QActive(Q_STATE_CAST(&GUI_Mgr::initial)),
		FirstVSync(true),
		DsiHandle(nullptr)
{
}

Q_STATE_DEF(GUI_Mgr, initial) {
	(void) e;

//	subscribe(VSYNC_OCCURRED_SIG);
//	ToughGfxHalHandle->enableLCDControllerInterrupt();
//	ToughGfxHalHandle->enableInterrupts();
	return tran(&running);
}

Q_STATE_DEF(GUI_Mgr, running) {
	QP::QState status_;

	switch(e->sig) {
	case Q_EXIT_SIG:
		status_ = Q_RET_HANDLED;
		break;

	case Q_ENTRY_SIG:
		status_ = Q_RET_HANDLED;
		break;

	case VSYNC_OCCURRED_SIG:
		touchgfx::HAL::getInstance()->backPorchExited();
		if (FirstVSync) {
			HAL_DSI_ShortWrite(DsiHandle, LCD_OTM8009A_ID, DSI_DCS_SHORT_PKT_WRITE_P1, OTM8009A_CMD_DISPON, 0x00);
			FirstVSync = false;
		}
		status_ = Q_RET_HANDLED;
		break;

	default:
		status_ = super(&top);
		break;
	}
	return status_;
}


void GUI_Mgr::SetDsiHandle(DSI_HandleTypeDef * pDSI) {
	DsiHandle = pDSI;
}
}  // namespace COMMON
