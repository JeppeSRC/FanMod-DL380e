#include "math.h"

uint8 logBase2(uint8 v) {
    switch (v) {
        case 0x80:
            return 7;
        case 0x40:
            return 6;
        case 0x20:
            return 5;
        case 0x10:
            return 4;
        case 0x08:
            return 3;
        case 0x04:
            return 2;
        case 0x02:
            return 1;
        case 0x01:
            return 0;
    }

    return 0xFF;
}

uint8 maskLSB(uint8 v) {
    return v &= ~v + 1;
}