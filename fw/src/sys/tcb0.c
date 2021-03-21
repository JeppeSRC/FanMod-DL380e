#include "tcb0.h"
#include "sys.h"

void tcb0_write(uint8 registerOffset, uint8 mask, uint8 data) {
    write(TCB0_ADDR + registerOffset, mask, data);
}

void tcb0_writew(uint8 registerOffset, uint16 data) {
    writew(TCB0_ADDR + registerOffset, data);
}

uint8 tcb0_read(uint8 registerOffset, uint8 mask) {
    return read(TCB0_ADDR + registerOffset, mask);
}

uint16 tcb0_readw(uint8 registerOffset) {
    return readw(TCB0_ADDR + registerOffset);
}