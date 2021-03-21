#ifndef _CLKCTRL_H_
#define _CLKCTRL_H_

#include "sys.h"

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
#define CLKCTRL_bCLKSEL         0x03

//MCLKCTRLB
#define CLKCTRL_bPEN            0x01
#define CLKCTRL_bPDIV           0x1E

//MCLKLOCK
#define CLKCTRL_bLOCKEN         0x01

//MCLKSTATUS
#define CLKCTRL_bSOSC           0x01
#define CLKCTRL_bOSC20MS        0x10
#define CLKCTRL_bOSC32KS        0x20
#define CLKCTRL_bEXTS           0x80

//OSC20MCTRLA
#define CLKCTRL_bRUNSTDBY       0x02

//OSC20MCALIBA
#define CLKCTRL_bCAL20M         0x3F

//OSC20MCALIBB
#define CLKCTRL_bTEMPCAL20M     0x0F
#define CLKCTRL_bLOCK           0x80

//OSC32KCTRLA
//#define RUNSTDBY

void  clkctrl_write(uint8 registerOffset, uint8 mask, uint8 data);
uint8 clkctrl_read(uint8 registerOffset, uint8 mask);

#endif