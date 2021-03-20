#ifndef _TCA0_H_
#define _TCA0_H_

#include "sys.h"

#define TCA0_ADDR       0x0A00

#define TCA0_CTRLA      0x00
#define TCA0_CTRLB      0x01
#define TCA0_CTRLC      0x02
#define TCA0_CTRLD      0x03
#define TCA0_CTRLECLR   0x04
#define TCA0_CTRLESET   0x05
#define TCA0_CTRLFCLR   0x06
#define TCA0_CTRLFSET   0x07
#define TCA0_EVCTRL     0x09
#define TCA0_INTCRTRL   0x0A
#define TCA0_INTCFLAGS  0x0B
#define TCA0_DBGCTRL    0x0E
#define TCA0_TEMP       0x0F
#define TCA0_CNT        0x20
#define TCA0_CNTL       TCA0_CNT
#define TCA0_CNTH       TCA0_CNT+1
#define TCA0_PER        0x26
#define TCA0_PERL       TCA0_PER
#define TCA0_PERH       TCA0_PER+1
#define TCA0_CMP0       0x28
#define TCA0_CMP0L      TCA0_CMP0
#define TCA0_CMP0H      TCA0_CMP0+1
#define TCA0_CMP1       0x2A
#define TCA0_CMP1L      TCA0_CMP1
#define TCA0_CMP1H      TCA0_CMP1+1
#define TCA0_CMP2       0x2C
#define TCA0_CMP2L      TCA0_CMP2
#define TCA0_CMP2H      TCA0_CMP2+1
#define TCA0_PERBUF     0x36
#define TCA0_PERBUFL    TCA0_PERBUF
#define TCA0_PERBUFH    TCA0_PERBUF+1
#define TCA0_CMP0BUF    0x38
#define TCA0_CMP0BUFL   TCA0_CMP0BUF
#define TCA0_CMP0BUFH   TCA0_CMP0BUF+1
#define TCA0_CMP1BUF    0x3A
#define TCA0_CMP1BUFL   TCA0_CMP1BUF
#define TCA0_CMP1BUFH   TCA0_CMP1BUF+1
#define TCA0_CMP2BUF    0x3C
#define TCA0_CMP2BUFL   TCA0_CMP2BUF
#define TCA0_CMP2BUFH   TCA0_CMP2BUF+1

//CTRLA
#define TCA0_bENABLE    MAKEBITS(0x01, 0)
#define TCA0_bCLKSEL    MAKEBITS(0x07, 1)

//CTRLB
#define TCA0_bWGMODE    MAKEBITS(0x07, 0)
#define TCA0_bALUPD     MAKEBITS(0x01, 3)
#define TCA0_bCMP0EN    MAKEBITS(0x01, 4)
#define TCA0_bCMP1EN    MAKEBITS(0x01, 5)
#define TCA0_bCMP2EN    MAKEBITS(0x01, 6)

//CTRLC
#define TCA0_bCMP0OV    MAKEBITS(0x01, 0)
#define TCA0_bCMP1OV    MAKEBITS(0x01, 1)
#define TCA0_bCMP2OV    MAKEBITS(0x01, 2)

//CTRLD
#define TCA0_bSPLITM    MAKEBITS(0x01, 0)

//CTRLE
#define TCA0_bDIR       MAKEBITS(0x01, 0)
#define TCA0_bLUPD      MAKEBITS(0x01, 1)
#define TCA0_bCMD       MAKEBITS(0x03, 2)

//CTRLF
#define TCA0_bPERBV     MAKEBITS(0x01, 0)
#define TCA0_bCMP0BV    MAKEBITS(0x01, 1)
#define TCA0_bCMP1BV    MAKEBITS(0x01, 2)
#define TCA0_bCMP2BV    MAKEBITS(0x01, 3)

//EVCTRL
#define TCA0_bCNTEI     MAKEBITS(0x01, 0)
#define TCA0_bEVACT     MAKEBITS(0x03, 1)

//INTCTRL / INTFLAGS
#define TCA0_bOVF       MAKEBITS(0x01, 0)
#define TCA0_bCMP0      MAKEBITS(0x01, 4)
#define TCA0_bCMP1      MAKEBITS(0x01, 5)
#define TCA0_bCMP2      MAKEBITS(0x01, 6)

//DBGCTRL
#define TCA0_bDBGRUN     MAKEBITS(0x01, 0)

//CNT
#define TCA0_bCNT       MAKEBITS(0xFF, 0)

//PER
#define TCA0_bPER       MAKEBITS(0xFF, 0)

//CMP0 / CMP1 / CMP2
#define TCA0_bCMP       MAKEBITS(0xFF, 0)

//PERBUF
#define TCA0_bPERBUF    MAKEBITS(0xFF, 0)

//CMP0BUF / CMP1BUF / CMP2BUF
#define TCA0_bCMPBUF    MAKEBITS(0xFF, 0)

void   tca0_write(uint8 registerOffset, uint8 bits, uint8 data);
void   tca0_writew(uint8 registerOffset, uint16 data);
uint8  tca0_read(uint8 registerOffset, uint8 bits);
uint16 tca0_readw(uint8 registerOffset);
#endif
