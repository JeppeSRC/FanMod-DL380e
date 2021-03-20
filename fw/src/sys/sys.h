#ifndef _SYS_H_
#define _SYS_H_

#include "def.h"

#define MAKEBITS(mask, shift) (((mask & 0xFF) << (8 + (shift & 0xFF))) | (shift & 0xFF))
#define SHIFT(bits) ((uint8)(bits & 0xFF))
#define MASK(bits) ((uint8)((bits >> 8) & 0xFF))

void  write(uint16 registerAddress, uint16 bits, uint8 data);
uint8 read(uint16 registerAddress, uint16 bits);

#endif