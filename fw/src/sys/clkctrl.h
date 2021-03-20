#ifndef _CLKCTRL_H_
#define _CLKCTRL_H_

#include "def.h"

#define CLKCTRL_ADDR            0x0060

#define CLKCTRL_MCLKCTRLA       0x00
#define CLKCTRL_MCLKCTRLB       0x01
#define CLKCTRL_MCLKLOCK        0x02
#define CLKCTRL_MCLKSTATUS      0x03
#define CLKCTRL_OSC20MCTRLA     0x10
#define CLKCTRL_OSC20MCALIBA    0x11
#define CLKCTRL_OSC20MCALIBB    0x11
#define CLKCTRL_OSC32KCTRLA     0x18


//MCLKCTRLA
#define CLKCTRL_CLKSEL          MAKEBITS(0x03, 0)

//MCLKCTRLB
#define CLKCTRL_PEN             MAKEBITS(0x01, 0)
#define CLKCTRL_PDIV            MAKEBITS(0x0F, 1)

//MCLKLOCK
#define CLKCTRL_LOCKEN          MAKEBITS(0x01, 0)

//MCLKSTATUS
#define CLKCTRL_SOSC            MAKEBITS(0x01, 0)
#define CLKCTRL_OSC20MS         MAKEBITS(0x01, 4)
#define CLKCTRL_OSC32KS         MAKEBITS(0x01, 5)
#define CLKCTRL_EXTS            MAKEBITS(0x01, 7)

//OSC20MCTRLA
#define CLKCTRL_RUNSTDBY        MAKEBITS(0x01, 1)

//OSC20MCALIBA
#define CLKCTRL_CAL20M          MAKEBITS(0x3F, 0)

//OSC20MCALIBB
#define CLKCTRL_TEMPCAL20M      MAKEBITS(0x0F, 0)
#define CLKCTRL_LOCK            MAKEBITS(0x01, 7)

//OSC32KCTRLA
//#define RUNSTDBY

void  clkctrl_write(uint8 registerOffset, uint16 bits, uint8 data);
uint8 clkctrl_read(uint8 registerOffset, uint16 bits);

#endif