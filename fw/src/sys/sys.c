#include "sys.h"


void write(uint16 registerAddress, uint16 bits, uint8 data) {
    volatile uint8* reg = (uint8*)registerAddress;

    uint8 tmp = *reg & ~MASK(bits);
    tmp |= (data << SHIFT(bits)) & MASK(bits);
    *reg = tmp;
}

uint8 read(uint16 registerAddress, uint16 bits) {
    volatile uint8* reg = (uint8*)registerAddress;

    return (*reg >> SHIFT(bits)) & MASK(bits);
}

