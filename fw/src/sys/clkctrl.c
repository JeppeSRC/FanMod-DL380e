#include "clkctrl.h"
#include "sys.h"
#include "cpu.h"

void clkctrl_write(uint8 registerOffset, uint8 mask, uint8 data) {
    if (registerOffset == CLKCTRL_MCLKCTRLA || registerOffset == CLKCTRL_MCLKCTRLB) {
        write(CLKCTRL_ADDR + registerOffset, mask, data, CPU_CCP_IOREG);
    } else {
        write(CLKCTRL_ADDR + registerOffset, mask, data, 0);
    }
}

uint8 clkctrl_read(uint8 registerOffset, uint8 mask) {
    return read(CLKCTRL_ADDR + registerOffset, mask);
}

