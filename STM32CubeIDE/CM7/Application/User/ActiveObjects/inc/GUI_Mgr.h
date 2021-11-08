/*
 * GUI_Mgr.h
 *
 * Created on: Oct 15, 2021
 *     Author: David Smoot
 */

#ifndef INCLUDE_GUI_MGR_H_
#define INCLUDE_GUI_MGR_H_

#include "qpcpp.h"
#include "Project.h"
#include <touchgfx/hal/HAL.hpp>

namespace COMMON {

class GUI_Mgr : public QP::QActive {
public:
	GUI_Mgr();
	void SetDsiHandle(DSI_HandleTypeDef * pDSI);

private:
	bool FirstVSync;
	DSI_HandleTypeDef * DsiHandle;

protected:
	Q_STATE_DECL(initial);
	Q_STATE_DECL(running);


};	//class GUI_Mgr

}  // namespace COMMON


#endif /* INCLUDE_GUI_MGR_H_ */
