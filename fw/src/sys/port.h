#ifndef _PORT_H_
#define _PORT_H_

#include "def.h"

#define PORT_ADDR       0x0400

#define PORT_DIR        0x00
#define PORT_DIRSET     0x01
#define PORT_DIRCLR     0x02
#define PORT_DIRTGL     0x03
#define PORT_OUT        0x04
#define PORT_OUTSET     0x05
#define PORT_OUTCLR     0x06
#define PORT_OUTTGL     0x07
#define PORT_IN         0x08
#define PORT_INTFLAGS   0x09
#define PORT_PIN0CTRL   0x10
#define PORT_PIN1CTRL   0x11
#define PORT_PIN2CTRL   0x12
#define PORT_PIN3CTRL   0x13
#define PORT_PIN4CTRL   0x14
#define PORT_PIN5CTRL   0x15
#define PORT_PIN6CTRL   0x16
#define PORT_PIN7CTRL   0x17

void port_write(uint8 registerOffset, uint8 data);
uint8 port_read(uint8 registerOffset);

void port_pin_mode(uint8 pin, uint8 mode);
void port_pin_out(uint8 pin, uint8 output);
uint8 port_pin_in(uint8 pin);

#endif
