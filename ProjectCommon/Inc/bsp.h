/*
 * bsp.h
 *
 *  Created on: May 5, 2021
 *      Author: dsmoot
 */

#ifndef BSP_H_
#define BSP_H_

namespace COMMON {

class BSP {
public:
    enum { BSP_TICKS_PER_SEC = 1000 };
    static void init(void);
    static void terminate(int16_t const result);
    static void onIdle();
    static void BSP_ledOff();
    static void BSP_ledOn();
};

} //namespace common

#endif /* BSP_H_ */
