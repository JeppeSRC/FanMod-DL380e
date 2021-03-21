#include "cpuint.h"
#include "sys.h"

void cpuint_write(uint8 registerOffset, uint8 mask, uint8 data) {
    write(CPUINT_ADDR + registerOffset, mask, data);
}

uint8 cpuint_read(uint8 registerOffset, uint8 mask) {
    return read(CPUINT_ADDR + registerOffset, mask);
}
