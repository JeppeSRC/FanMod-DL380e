#ifndef _TWI_H_
#define _TWI_H_

#include "def.h"

#define TWI_ADDR 0x0810

#define TWI_CTRLA       0x00
#define TWI_DBGCTRL     0x02
#define TWI_MCTRLA      0x03
#define TWI_MCTRLB      0x04
#define TWI_MSTATUS     0x05
#define TWI_MBAUD       0x06
#define TWI_MADDR       0x07
#define TWI_MDATA       0x08
#define TWI_SCTRLA      0x09
#define TWI_SCTRLB      0x0A
#define TWI_SSTATUS     0x0B
#define TWI_SADDR       0x0C
#define TWI_SDATA       0x0D
#define TWI_SADDRMASK   0x0E

//CTRLA
#define TWI_bFMPEN      0x02
#define TWI_bSDAHOLD    0x0C
#define TWI_bSDASETUP   0x10

//DBGCTRL
#define TWI_bDBGRUN     0x01

//MCTRLA
#define TWI_bENABLE     0x01
#define TWI_bSMEN       0x02
#define TWI_bTIMEOUT    0x0C
#define TWI_bQCEN       0x10
#define TWI_bWIEN       0x40
#define TWI_bRIEN       0x80

//MCTRLB
#define TWI_bMCMD       0x03
#define TWI_bACKACT     0x04
#define TWI_bFLUSH      0x08

//MSTATUS
#define TWI_bBUSSTATE   0x03
#define TWI_bBUSERR     0x04
#define TWI_bARBLOST    0x08
#define TWI_bRXACK      0x10
#define TWI_bCLKHOLD    0x20
#define TWI_bWIF        0x40
#define TWI_bRIF        0x80

//MBAUD
#define TWI_bBAUD       0xFF

//MADDR
#define TWI_bADDR       0xFF

//MDATA
#define TWI_bDATA       0xFF

//SCTRLA
//#define TWI_bENABLE     0x01
//#define TWI_bSMEN       0x02
#define TWI_bPMEN       0x04
#define TWI_bPIEN       0x20
#define TWI_bAPIEN      0x40
#define TWI_bDIEN       0x80

//SCTRLB
#define TWI_bSCMD       0x03
//#define TWI_bACKACT     0x04

//SSTATUS
#define TWI_bAP         0x01
#define TWI_bDIR        0x02
//#define TWI_bBUSERR     0x04
#define TWI_bCOLL       0x08
//#define TWI_bRXACK      0x10
//#define TWI_bCLKHOLD    0x20
#define TWI_bAPIF       0x40
#define TWI_bDIF        0x80

//SADDR
//#define TWI_bADDR       0xFF

//SDATA
//#define TWI_bDATA       0xFF

//SADDRMASK
#define TWI_bADDRMASK   0xFF

void  twi_write(uint8 registerOffset, uint8 mask, uint8 data);
uint8 twi_read(uint8 registerOffset, uint8 mask);



#endif
