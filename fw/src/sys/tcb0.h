#ifndef _TCB0_H_
#define _TCB0_H_

#include "def.h"

#define TCB0_ADDR 0x0A40

#define TCB0_CTRLA      0x00
#define TCB0_CTRLB      0x01
#define TCB0_EVCTRL     0x04
#define TCB0_INTCTRL    0x05
#define TCB0_INTFLAGS   0x06
#define TCB0_STATUS     0x07
#define TCB0_DBGCTRL    0x08
#define TCB0_TEMP       0x09
#define TCB0_CNT        0x0A
#define TCB0_CNTL       TCB0_CNT
#define TCB0_CNTH       TCB0_CNT+1
#define TCB0_CCMP       0x0C
#define TCB0_CCMPL      TCB0_CCMP
#define TCB0_CCMPH      TCB0_CCMP+1

//CTRLA
#define TCB0_bENABLE    0x01
#define TCB0_bCLKSEL    0x06
#define TCB0_bSYNCUPD   0x10
#define TCB0_bRUNSTDBY  0x40

//CTRLB
#define TCB0_bCNTMODE   0x07
#define TCB0_bCCNPEN    0x10
#define TCB0_bCCMPINIT  0x20
#define TCB0_bASYNC     0x40

//EVCTRL
#define TCB0_bCAPTEI    0x01
#define TCB0_bEDGE      0x10
#define TCB0_bFILTER    0x40

//INTCTRL / INTFLAGS
#define TCB0_bCAPT      0x01

// STATUS
#define TCB0_bRUN       0x01

//DBGCTRL
#define TCB0_bDBGRUN    0x01

//TEMP
#define TCB0_bTEMP      0xFF

//CNT
#define TCB0_bCNT       0xFF

//CCMP
#define TCB0_bCCMP      0xFF

void   tcb0_write(uint8 registerOffset, uint8 mask, uint8 data);
void   tcb0_writew(uint8 registerOffset, uint16 data);
uint8  tcb0_read(uint8 registerOffset, uint8 mask);
uint16 tcb0_readw(uint8 registerOffset);


#endif
