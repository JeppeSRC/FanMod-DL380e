#ifndef _CPUINT_H_
#define _CPUINT_H_

#include "sys.h"

#define CPUINT_ADDR         0x0110

#define CPUINT_CTRLA        0x00
#define CPUINT_STATUS       0x01
#define CPUINT_LVL0PRI      0x02
#define CPUINT_LCL1VEC      0x03

//CTRLA
#define CPUINT_bLVL0RR      MAKEBITS(0x01, 0)
#define CPUINT_bCVT         MAKEBITS(0x01, 5)
#define CPUINT_bIVSEL       MAKEBITS(0x01, 6)

//STATUS
#define	CPUINT_bLVL0EX      MAKEBITS(0x01, 0)
#define CPUINT_bLVL1EX      MAKEBITS(0x01, 1)
#define CPUINT_bNMIEX       MAKEBITS(0x01, 7)

//LVL0PRI
#define CPUINT_bLVL0PRI     MAKEBITS(0xFF, 0)

//LVL1VEC
#define CPUINT_bLVL1VEC     MAKEBITS(0xFF, 0)

void  cpuint_write(uint8 registerOffset, uint16 bits, uint8 data);
uint8 cpuint_read(uint8 registerOffset, uint16 bits);

#endif