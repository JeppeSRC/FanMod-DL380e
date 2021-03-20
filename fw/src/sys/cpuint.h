#ifndef _CPUINT_H_
#define _CPUINT_H_

#include "sys.h"

#define CPUINT_ADDR 0x0110

#define CPUINT_CTRLA    0x00
#define CPUINT_STATUS   0x01
#define CPUINT_LVL0PRI  0x02
#define CPUINT_LCL1VEC  0x03

//CTRLA
#define LVL0RR          MAKEBITS(0x01, 0)
#define CVT             MAKEBITS(0x01, 5)
#define IVSEL           MAKEBITS(0x01, 6)

//STATUS
#define	LVL0EX          MAKEBITS(0x01, 0)
#define LVL1EX          MAKEBITS(0x01, 1)
#define NMIEX           MAKEBITS(0x01, 7)

//LVL0PRI
#define LVL0PRI         MAKEBITS(0xFF, 0)

//LVL1VEC
#define LVL1VEC         MAKEBITS(0xFF, 0)

void  cpuint_write(uint8 registerOffset, uint16 bits, uint8 data);
uint8 cpuint_read(uint8 registerOffset, uint16 bits);

#endif