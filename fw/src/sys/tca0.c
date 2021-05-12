#include "tca0.h"
#include "sys.h"

void tca_write(uint8 registerOffset, uint8 mask, uint8 data) {
    write(TCA_ADDR + registerOffset, mask, data, 0);
}

void tca_writew(uint8 registerOffset, uint16 data) {
    writew(TCA_ADDR + registerOffset, data);
}

uint8 tca_read(uint8 registerOffset, uint8 mask) {
    return read(TCA_ADDR + registerOffset, mask);
}

uint16 tca_readw(uint8 registerOffset) {
    return readw(TCA_ADDR + registerOffset);
}