#include "clkctrl.h"
#include "sys.h"

void  clkctrl_write(uint8 registerOffset, uint16 bits, uint8 data) {
    write(CLKCTRL_ADDR + registerOffset, bits, data);
}

uint8 clkctrl_read(uint8 registerOffset, uint16 bits) {
    return read(CLKCTRL_ADDR + registerOffset, bits);
}

