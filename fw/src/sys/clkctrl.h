#ifndef _CLKCTRL_H_
#define _CLKCTRL_H_

#include "def.h"

#define CLKCTRL_ADDR 0x0060

#define CLKCTRL_MCLKCTRLA		0x00
#define CLKCTRL_MCLKCTRLB		0x01
#define CLKCTRL_MCLKLOCK		0x02
#define CLKCTRL_MCLKSTATUS		0x03
#define CLKCTRL_OSC20MCTRLA		0x10
#define CLKCTRL_OSC20MCALIBA	0x11
#define CLKCTRL_OSC20MCALIBB	0x11
#define CLKCTRL_OSC32KCTRLA		0x18


//MCLKCTRLA
#define CLKSEL					MAKEBITS(0x03, 0)

//MCLKCTRLB
#define PEN						MAKEBITS(0x01, 0)
#define PDIV					MAKEBITS(0x0F, 1)

//MCLKLOCK
#define LOCKEN					MAKEBITS(0x01, 0)

//MCLKSTATUS
#define SOSC					MAKEBITS(0x01, 0)
#define OSC20MS					MAKEBITS(0x01, 4)
#define OSC32KS					MAKEBITS(0x01, 5)
#define EXTS					MAKEBITS(0x01, 7)

//OSC20MCTRLA
#define RUNSTDBY				MAKEBITS(0x01, 1)

//OSC20MCALIBA
#define CAL20M					MAKEBITS(0x3F, 0)

//OSC20MCALIBB
#define TEMPCAL20M				MAKEBITS(0x0F, 0)
#define LOCK					MAKEBITS(0x01, 7)

//OSC32KCTRLA
//#define RUNSTDBY

void  clkctrl_write(uint8 registerOffset, uint16 bits, uint8 data);
uint8 clkctrl_read(uint8 registerOffset, uint16 bits);

#endif