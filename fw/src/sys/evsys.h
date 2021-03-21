#ifndef _EVSYS_H_
#define _EVSYS_H_

#include "def.h"

#define EVSYS_ADDR 0x0180

#define EVSYS_ASYNCSTROBE   0x00
#define EVSYS_SYNCSTROBE    0x01
#define EVSYS_ASYNCCH0      0x02
#define EVSYS_ASYNCCH1      0x03
#define EVSYS_SYNCCH0       0x0A
#define EVSYS_ASYNCUSER0    0x12
#define EVSYS_ASYNCUSER1    0x13
#define EVSYS_ASYNCUSER2    0x14
#define EVSYS_ASYNCUSER3    0x15
#define EVSYS_ASYNCUSER4    0x16
#define EVSYS_ASYNCUSER5    0x17
#define EVSYS_ASYNCUSER6    0x18
#define EVSYS_ASYNCUSER7    0x19
#define EVSYS_ASYNCUSER8    0x1A
#define EVSYS_ASYNCUSER9    0x1B
#define EVSYS_ASYNCUSER10   0x1C
#define EVSYS_SYNCUSER0     0x22
#define EVSYS_SYNCUSER1     0x23

//ASYNCSTROBE
#define EVSYS_bASYNCSTROBE  0xFF

//SYNCSTROBE
#define EVSYS_bSYNCSTROBE   0xFF

//ASYNCHn
#define EVSYS_bASYNCHCH     0xFF

//SYNCCH0
#define EVSYS_bSYNCCH       0xFF

//ASYNCUSERn
#define EVSYS_bASYNCUSER    0xFF

//SYNCHUSERn
#define EVSYS_bSYNCHUSER    0xFF

void  evsys_write(uint8 registerOffset, uint8 mask, uint8 data);
uint8 evsys_read(uint8 registerOffset, uint8 mask);

#endif
