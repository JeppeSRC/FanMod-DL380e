#include "twi.h"
#include "sys.h"

void twi_write(uint8 registerOffset, uint8 mask, uint8 data) {
    write(TWI_ADDR + registerOffset, mask, data);
}

uint8 twi_read(uint8 registerOffset, uint8 mask) {
    return read(TWI_ADDR + registerOffset, mask);
}

void twi_init(uint8 address) {
    twi_write(TWI_SADDR, TWI_bADDR, address);
    twi_write(TWI_SCTRLA, 0xFF, TWI_bDIEN | TWI_bAPIEN | TWI_bSMEN | TWI_bENABLE);
}
