#ifndef _SYS_H_
#define _SYS_H_

#include "def.h"

void   write(uint16 registerAddress, uint8 mask, uint8 data);
void   writew(uint16 registerAddress, uint16 data);
uint8  read(uint16 registerAddress, uint8 mask);
uint16 readw(uint16 registerAddress);

#endif