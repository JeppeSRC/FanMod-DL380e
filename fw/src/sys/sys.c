#include "sys.h"


void write(uint16 registerAddress, uint16 bits, uint8 data) {
    volatile uint8* reg = (uint8*)registerAddress;

    uint8 tmp = *reg & ~MASK(bits);
    tmp |= (data << SHIFT(bits)) & MASK(bits);
    *reg = tmp;
}

void writew(uint16 registerAddress, uint16 data) {
    volatile uint8* reg = (uint8*)registerAddress;

    *reg = (uint8)(data & 0xFF);
    reg++;
    *reg = (uint8)(data >> 8);
}

uint8 read(uint16 registerAddress, uint16 bits) {
    volatile uint8* reg = (uint8*)registerAddress;

    return (*reg >> SHIFT(bits)) & MASK(bits);
}

uint16 readw(uint16 registerAddress) {
    volatile uint8* reg = (uint8*)registerAddress;

    return ((uint16)*(reg+1) << 8) | *reg;
}

