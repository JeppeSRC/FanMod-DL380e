#ifndef _TCB0_H_
#define _TCB0_H_

#include "def.h"

#define TCB_ADDR        0x0A40

#define TCB_CTRLA       0x00
#define TCB_CTRLB       0x01
#define TCB_EVCTRL      0x04
#define TCB_INTCTRL     0x05
#define TCB_INTFLAGS    0x06
#define TCB_STATUS      0x07
#define TCB_DBGCTRL     0x08
#define TCB_TEMP        0x09
#define TCB_CNT         0x0A
#define TCB_CNTL        TCB_CNT
#define TCB_CNTH        TCB_CNT+1
#define TCB_CCMP        0x0C
#define TCB_CCMPL       TCB_CCMP
#define TCB_CCMPH       TCB_CCMP+1

//CTRLA
#define TCB_bENABLE     0x01
#define TCB_bCLKSEL     0x06
#define TCB_bSYNCUPD    0x10
#define TCB_bRUNSTDBY   0x40

//CTRLB
#define TCB_bCNTMODE    0x07
#define TCB_bCCNPEN     0x10
#define TCB_bCCMPINIT   0x20
#define TCB_bASYNC      0x40

//EVCTRL
#define TCB_bCAPTEI     0x01
#define TCB_bEDGE       0x10
#define TCB_bFILTER     0x40

//INTCTRL / INTFLAGS
#define TCB_bCAPT       0x01

// STATUS
#define TCB_bRUN        0x01

//DBGCTRL
#define TCB_bDBGRUN     0x01

//TEMP
#define TCB_bTEMP       0xFF

//CNT
#define TCB_bCNT        0xFF

//CCMP
#define TCB_bCCMP       0xFF

void   tcb_write(uint8 registerOffset, uint8 mask, uint8 data);
void   tcb_writew(uint8 registerOffset, uint16 data);
uint8  tcb_read(uint8 registerOffset, uint8 mask);
uint16 tcb_readw(uint8 registerOffset);


#endif
