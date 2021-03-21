#ifndef _CPUINT_H_
#define _CPUINT_H_

#include "sys.h"

#define CPUINT_ADDR         0x0110

#define CPUINT_CTRLA        0x00
#define CPUINT_STATUS       0x01
#define CPUINT_LVL0PRI      0x02
#define CPUINT_LCL1VEC      0x03

//CTRLA
#define CPUINT_bLVL0RR      0x01
#define CPUINT_bCVT         0x20
#define CPUINT_bIVSEL       0x40

//STATUS
#define CPUINT_bLVL0EX      0x01
#define CPUINT_bLVL1EX      0x02
#define CPUINT_bNMIEX       0x80

//LVL0PRI
#define CPUINT_bLVL0PRI     0xFF

//LVL1VEC
#define CPUINT_bLVL1VEC     0xFF

void  cpuint_write(uint8 registerOffset, uint8 mask, uint8 data);
uint8 cpuint_read(uint8 registerOffset, uint8 mask);

#endif