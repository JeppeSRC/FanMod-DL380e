#include "port.h"
#include "sys.h"

void port_write(uint8 registerOffset, uint8 data) {
    write(PORT_ADDR + registerOffset, 0xFF, data, 0);
}
uint8 port_read(uint8 registerOffset) {
    return read(PORT_ADDR + registerOffset, 0xFF);
}

void port_pin_mode(uint8 pin, uint8 mode) {
    if (mode == 0) {
        port_write(PORT_DIRCLR, 1 << pin);
    } else if (mode == 1) {
        port_write(PORT_DIRSET, 1 << pin);
    }
}

void port_pin_ctrl(uint8 pin, uint8 isc, uint8 pullup, uint8 inv) {
    volatile uint8* reg = (uint8*)(PORT_ADDR + PORT_PIN0CTRL + pin);

    *reg = ((inv & 0x01) << 7) | ((pullup & 0x01) << 3) | (isc & 0x07);
}

void port_pin_out(uint8 pin, uint8 output) {
    if (output == 0) {
        port_write(PORT_OUTCLR, 1 << pin);
    } else {
        port_write(PORT_OUTSET, 1 << pin);
    }
}

uint8 port_pin_in(uint8 pin) {
    return (port_read(PORT_IN) >> pin) & 0x01;
}