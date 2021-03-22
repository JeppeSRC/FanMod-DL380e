#include "tcb0.h"
#include "sys.h"

void tcb_write(uint8 registerOffset, uint8 mask, uint8 data) {
    write(TCB_ADDR + registerOffset, mask, data);
}

void tcb_writew(uint8 registerOffset, uint16 data) {
    writew(TCB_ADDR + registerOffset, data);
}

uint8 tcb_read(uint8 registerOffset, uint8 mask) {
    return read(TCB_ADDR + registerOffset, mask);
}

uint16 tcb_readw(uint8 registerOffset) {
    return readw(TCB_ADDR + registerOffset);
}