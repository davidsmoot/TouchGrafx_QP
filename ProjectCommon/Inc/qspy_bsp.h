/*
 * qspy_bsp.h
 *
 *  Created on: May 5, 2021
 *      Author: dsmoot
 */

#ifndef INCLUDE_QSPY_BSP_H_
#define INCLUDE_QSPY_BSP_H_

namespace COMMON {
namespace QSpy {

// Idle processing--call with interrupts disabled.
void onIdle();

bool uartDisplayString(const char* string);
bool uartDisplayText(const char* text, uint32_t length);

}
}


#endif /* INCLUDE_QSPY_BSP_H_ */
