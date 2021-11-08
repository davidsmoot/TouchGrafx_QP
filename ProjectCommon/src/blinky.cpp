//.$file${src::blinky.cpp} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
//
// Model: blinky.qm
// File:  ${src::blinky.cpp}
//
// This code has been generated by QM 5.1.0 <www.state-machine.com/qm/>.
// DO NOT EDIT THIS FILE MANUALLY. All your changes will be lost.
//
// This program is open source software: you can redistribute it and/or
// modify it under the terms of the GNU General Public License as published
// by the Free Software Foundation.
//
// This program is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
// or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
// for more details.
//
//.$endhead${src::blinky.cpp} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
#include "qpcpp.hpp"  // QP/C++ framework API
#include "blinky.hpp" // Blinky application
#include "bsp.h"    // Board Support Package interface

using namespace QP;

using COMMON::BSP;

// ask QM to declare the Blinky class ----------------------------------------
//.$declare${AOs::Blinky} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
//.${AOs::Blinky} ............................................................
class Blinky : public QP::QActive {
private:
    QP::QTimeEvt m_timeEvt;

public:
    static Blinky inst;

public:
    Blinky();

protected:
    Q_STATE_DECL(initial);
    Q_STATE_DECL(off);
    Q_STATE_DECL(on);
};
//.$enddecl${AOs::Blinky} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

// define the global opaque pointer to Blinky AO -----------------------------
//.$skip${QP_VERSION} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
//. Check for the minimum required QP version
#if (QP_VERSION < 680U) || (QP_VERSION != ((QP_RELEASE^4294967295U) % 0x3E8U))
#error qpcpp version 6.8.0 or higher required
#endif
//.$endskip${QP_VERSION} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//.$define${AOs::AO_Blinky} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv

// global "opaque" pointer to the Blinky AO
//.${AOs::AO_Blinky} .........................................................
QP::QActive * const AO_Blinky = &Blinky::inst;
//.$enddef${AOs::AO_Blinky} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

// ask QM to define the Blinky class (including the state machine) -----------
//.$define${AOs::Blinky} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
//.${AOs::Blinky} ............................................................
Blinky Blinky::inst;
//.${AOs::Blinky::Blinky} ....................................................
Blinky::Blinky()
  : QActive(&initial),
    m_timeEvt(this, TIMEOUT_SIG, 0U)
{}

//.${AOs::Blinky::SM} ........................................................
Q_STATE_DEF(Blinky, initial) {
    //.${AOs::Blinky::SM::initial}
    QS_OBJ_DICTIONARY(&Blinky::inst);
    QS_OBJ_DICTIONARY(&Blinky::inst.m_timeEvt);

    // arm the private time event to expire in 1/2s
    // and periodically every 1/2 second
    m_timeEvt.armX(BSP::BSP_TICKS_PER_SEC/2,
                   BSP::BSP_TICKS_PER_SEC/2);
    (void)e; // unused parameter

    QS_FUN_DICTIONARY(&Blinky::off);
    QS_FUN_DICTIONARY(&Blinky::on);

    return tran(&off);
}
//.${AOs::Blinky::SM::off} ...................................................
Q_STATE_DEF(Blinky, off) {
    QP::QState status_;
    switch (e->sig) {
        //.${AOs::Blinky::SM::off}
        case Q_ENTRY_SIG: {
            BSP::BSP_ledOff();
            status_ = Q_RET_HANDLED;
            break;
        }
        //.${AOs::Blinky::SM::off::TIMEOUT}
        case TIMEOUT_SIG: {
            status_ = tran(&on);
            break;
        }
        default: {
            status_ = super(&top);
            break;
        }
    }
    return status_;
}
//.${AOs::Blinky::SM::on} ....................................................
Q_STATE_DEF(Blinky, on) {
    QP::QState status_;
    switch (e->sig) {
        //.${AOs::Blinky::SM::on}
        case Q_ENTRY_SIG: {
            BSP::BSP_ledOn();
            status_ = Q_RET_HANDLED;
            break;
        }
        //.${AOs::Blinky::SM::on::TIMEOUT}
        case TIMEOUT_SIG: {
            status_ = tran(&off);
            break;
        }
        default: {
            status_ = super(&top);
            break;
        }
    }
    return status_;
}
//.$enddef${AOs::Blinky} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
