#ifndef _TCA0_H_
#define _TCA0_H_

#include "def.h"

#define TCA_ADDR        0x0A00

#define TCA_CTRLA       0x00
#define TCA_CTRLB       0x01
#define TCA_CTRLC       0x02
#define TCA_CTRLD       0x03
#define TCA_CTRLECLR    0x04
#define TCA_CTRLESET    0x05
#define TCA_CTRLFCLR    0x06
#define TCA_CTRLFSET    0x07
#define TCA_EVCTRL      0x09
#define TCA_INTCRTRL    0x0A
#define TCA_INTCFLAGS   0x0B
#define TCA_DBGCTRL     0x0E
#define TCA_TEMP        0x0F
#define TCA_CNT         0x20
#define TCA_CNTL        TCA_CNT
#define TCA_CNTH        TCA_CNT+1
#define TCA_PER         0x26
#define TCA_PERL        TCA_PER
#define TCA_PERH        TCA_PER+1
#define TCA_CMP0        0x28
#define TCA_CMP0L       TCA_CMP0
#define TCA_CMP0H       TCA_CMP0+1
#define TCA_CMP1        0x2A
#define TCA_CMP1L       TCA_CMP1
#define TCA_CMP1H       TCA_CMP1+1
#define TCA_CMP2        0x2C
#define TCA_CMP2L       TCA_CMP2
#define TCA_CMP2H       TCA_CMP2+1
#define TCA_PERBUF      0x36
#define TCA_PERBUFL     TCA_PERBUF
#define TCA_PERBUFH     TCA_PERBUF+1
#define TCA_CMP0BUF     0x38
#define TCA_CMP0BUFL    TCA_CMP0BUF
#define TCA_CMP0BUFH    TCA_CMP0BUF+1
#define TCA_CMP1BUF     0x3A
#define TCA_CMP1BUFL    TCA_CMP1BUF
#define TCA_CMP1BUFH    TCA_CMP1BUF+1
#define TCA_CMP2BUF     0x3C
#define TCA_CMP2BUFL    TCA_CMP2BUF
#define TCA_CMP2BUFH    TCA_CMP2BUF+1

//CTRLA
#define TCA_bENABLE     0x01
#define TCA_bCLKSEL     0x0E

//CTRLB
#define TCA_bWGMODE     0x07
#define TCA_bALUPD      0x08
#define TCA_bCMP0EN     0x10
#define TCA_bCMP1EN     0x20
#define TCA_bCMP2EN     0x40

//CTRLC
#define TCA_bCMP0OV     0x01
#define TCA_bCMP1OV     0x02
#define TCA_bCMP2OV     0x04

//CTRLD
#define TCA_bSPLITM     0x01

//CTRLE
#define TCA_bDIR        0x01
#define TCA_bLUPD       0x02
#define TCA_bCMD        0x0C

//CTRLF
#define TCA_bPERBV      0x01
#define TCA_bCMP0BV     0x02
#define TCA_bCMP1BV     0x04
#define TCA_bCMP2BV     0x08

//EVCTRL
#define TCA_bCNTEI      0x01
#define TCA_bEVACT      0x06

//INTCTRL / INTFLAGS
#define TCA_bOVF        0x01
#define TCA_bCMP0       0x10
#define TCA_bCMP1       0x20
#define TCA_bCMP2       0x40

//DBGCTRL
#define TCA_bDBGRUN     0x01

//TEMP
#define TCA_bTEMP       0xFF

//CNT
#define TCA_bCNT        0xFF

//PER
#define TCAbPER         0xFF

//CMP0 / CMP1 / CMP2
#define TCA_bCMP        0xFF

//PERBUF
#define TCA_bPERBUF     0xFF

//CMP0BUF / CMP1BUF / C M
#define TCA_bCMPBUF     0xFF

void   tca_write(uint8 registerOffset, uint8 mask, uint8 data);
void   tca_writew(uint8 registerOffset, uint16 data);
uint8  tca_read(uint8 registerOffset, uint8 mask);
uint16 tca_readw(uint8 registerOffset);

#endif
