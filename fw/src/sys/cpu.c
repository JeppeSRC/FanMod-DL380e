#include "cpu.h"
#include "sys.h"

void cpu_write(uint8 registerOffset, uint8 mask, uint8 data) {
    write(CPU_ADDR + registerOffset, mask, data, 0);
}
uint8 cpu_read(uint8 registerOffset, uint8 mask) {
    return read(CPU_ADDR + registerOffset, mask);
}
