#ifndef _CPU_H_
#define _CPU_H_

#include "def.h"

#define CPU_ADDR 0x0030

#define CPU_CCP 0x04
#define CPU_SREG 0x0F

#define CPU_bI 0x80
#define CPU_bT 0x40
#define CPU_bH 0x20
#define CPU_bS 0x10
#define CPU_bV 0x08
#define CPU_bN 0x04
#define CPU_bZ 0x02
#define CPU_bC 0x01

void cpu_write(uint8 registerOffset, uint8 mask, uint8 data);
uint8 cpu_read(uint8 registerOffset, uint8 mask);

#define CPU_CCP_SPM 0x9D
#define CPU_CCP_IOREG 0xD8

#endif