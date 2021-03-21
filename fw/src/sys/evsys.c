#include "evsys.h"
#include "sys.h"

void evsys_write(uint8 registerOffset, uint8 mask, uint8 data) {
    write(EVSYS_ADDR + registerOffset, mask, data);
}

uint8 evsys_read(uint8 registerOffset, uint8 mask) {
    return read(EVSYS_ADDR + registerOffset, mask);
}
