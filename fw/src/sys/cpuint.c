#include "cpuint.h"

void  cpuint_write(uint8 registerOffset, uint16 bits, uint8 data) {
    write(CPUINT_ADDR + registerOffset, bits, data);
}

uint8 cpuint_read(uint8 registerOffset, uint16 bits) {
    return read(CPUINT_ADDR + registerOffset, bits);
}
