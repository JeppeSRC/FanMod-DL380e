#include "sys.h"
#include "cpu.h"
#include <math/math.h>

#define LSBPOS(x) logBase2(maskLSB(x))

void write(uint16 registerAddress, uint8 mask, uint8 data, uint8 protection) {
    volatile uint8* reg = (uint8*)registerAddress;

    if (mask == 0xFF) {
        *reg = data;
        return;
    }

    uint8 tmp = *reg & ~mask;
    tmp |= (data << LSBPOS(mask)) & mask;


    if (protection) {
        volatile uint8* ccp = (uint8*)(CPU_ADDR + CPU_CCP);
        *ccp = protection;
    }

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

    if (mask == 0xFF) {
        return *reg;
    }

    return (*reg & mask) >> LSBPOS(mask);
}

uint16 readw(uint16 registerAddress) {
    volatile uint8* reg = (uint8*)registerAddress;

    return ((uint16)*(reg+1) << 8) | *reg;
}

