#include "tca0.h"

void tca0_write(uint8 registerOffset, uint8 mask, uint8 data) {
    write(TCA0_ADDR + registerOffset, mask, data);
}

void tca0_writew(uint8 registerOffset, uint16 data) {
    writew(TCA0_ADDR + registerOffset, data);
}

uint8 tca0_read(uint8 registerOffset, uint8 mask) {
    return read(TCA0_ADDR + registerOffset, mask);
}

uint16 tca0_readw(uint8 registerOffset) {
    return readw(TCA0_ADDR + registerOffset);
}