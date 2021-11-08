/*
 * Project.h
 *
 *  Created on: May 5, 2021
 *      Author: dsmoot
 *
 */

#ifndef APP_COMMON_INCLUDE_PLATFORMCOMMON_H_
#define APP_COMMON_INCLUDE_PLATFORMCOMMON_H_

#include "qpcpp.h"
#include "MaxSizeEvent.hpp"
#include "main.h"

#include <array>


namespace COMMON {


extern QP::QActive * const AO_GUI_Mgr;


enum CommonUserSignals {
	VSYNC_OCCURRED_SIG = QP::Q_USER_SIG,
	LAST_COMMON_SIG, // must be last in the enum list!
};

enum QPSignals {
	MAX_PUB_SIG = COMMON::LAST_COMMON_SIG // Must be last!
};



class BoolEvt : public QP::QEvt {
public:
	bool data;
};

class ByteEvent : public QP::QEvt {
public:
	uint8_t data;
};

class Uint16_tEvt : public QP::QEvt {
public:
	uint16_t	data;
};

class Float_Evt : public QP::QEvt {
public:
	float  data;
};

#define MAX_TEXT_LEN 16
class TextEvt : public QP::QEvt {
public:
    char text[MAX_TEXT_LEN]; // text to deliver
};



#ifdef Q_SPY
enum class QSUserMessages {
	DisplayText = QP::QS_USER,
	LastUserSig
};
#endif

#ifdef Q_SPY
// Application specific QSpy IDs
enum QSAppIds {
	QSApp_DisplayText = QP::QS_AP_ID,
	QSApp_CmdReturn
};
#endif


// NOTE:  If you add an event, add it to the list below.
// This will help ensure that the event pool block size is large
// enough to store all of the events.
using LargestEvent = typename FindMaxSizeEvent
		<TextEvt,  ByteEvent, Uint16_tEvt, BoolEvt, Float_Evt>::type;

} //namespace COMMON

#endif /* APP_COMMON_INCLUDE_PLATFORMCOMMON_H_ */
