#ifndef _CPUINT_H_
#define _CPUINT_H_

#include "def.h"

#define CPUINT_ADDR 0x0110

//CTRLA
#define IVSEL	0x40
#define CVT		0x20
#define LVL0RR	0x01

//STATUS
#define NMIEX	0x80
#define LVL1EX	0x02
#define	LVL0EX	0x01

typedef struct {
	uint8 CTRLA;
	uint8 STATUS;
	uint8 LVL0PRI;
	uint8 LVL1VEC;
} _CPUINT;

extern volatile _CPUINT* CPUINT;

#endif