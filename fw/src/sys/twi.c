#include "twi.h"
#include "sys.h"

void twi_write(uint8 registerOffset, uint8 mask, uint8 data) {
    write(TWI_ADDR + registerOffset, mask, data);
}

uint8 twi_read(uint8 registerOffset, uint8 mask) {
    return read(TWI_ADDR + registerOffset, mask);
}
