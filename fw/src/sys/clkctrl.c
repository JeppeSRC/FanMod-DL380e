#include "clkctrl.h"
#include "sys.h"

void clkctrl_write(uint8 registerOffset, uint8 mask, uint8 data) {
    write(CLKCTRL_ADDR + registerOffset, mask, data);
}

uint8 clkctrl_read(uint8 registerOffset, uint8 mask) {
    return read(CLKCTRL_ADDR + registerOffset, mask);
}

