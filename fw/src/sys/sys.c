#include "sys.h"
#include <math/math.h>

#define LSBPOS(x) log2(maskLSB(x))

void write(uint16 registerAddress, uint8 mask, uint8 data) {
    volatile uint8* reg = (uint8*)registerAddress;

    uint8 tmp = *reg & ~mask;
    tmp |= (data << LSBPOS(mask)) & mask;
    *reg = tmp;
}

void writew(uint16 registerAddress, uint16 data) {
    volatile uint8* reg = (uint8*)registerAddress;

    *reg = (uint8)(data & 0xFF);
    reg++;
    *reg = (uint8)(data >> 8);
}

uint8 read(uint16 registerAddress, uint8 mask) {
    volatile uint8* reg = (uint8*)registerAddress;

    return (*reg & mask) >> LSBPOS(mask);
}

uint16 readw(uint16 registerAddress) {
    volatile uint8* reg = (uint8*)registerAddress;

    return ((uint16)*(reg+1) << 8) | *reg;
}

