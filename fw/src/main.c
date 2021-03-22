#include <sys/cpuint.h>
#include <sys/clkctrl.h>
#include <sys/tca0.h>
#include <sys/twi.h>

#define CMD_GET_SET_PWM 0x01
#define CMD_SET_PWM 0x02
#define CMD_GET_REQUESTED_PWM 0x03

volatile uint8 cmd = 0;
volatile uint8 setPWM = 0;
volatile uint8 requestedPWM = 0;

void TWIS_Handler() {
    uint8 status = twi_read(TWI_SSTATUS, 0xFF);

    //Address match
    if (status & TWI_bAPIF) {
        if (status & TWI_bDIR) {
            //Reading
            if (cmd == CMD_GET_SET_PWM) {
                twi_write(TWI_SDATA, TWI_bDATA, setPWM);
            } else if (cmd == CMD_GET_REQUESTED_PWM) {
                twi_write(TWI_SDATA, TWI_bDATA, requestedPWM);
            }

            cmd = 0;
        } else {
            //Writing
            twi_write(TWI_SSTATUS, TWI_bAPIF, 0x01); // Clear interrupt and return and wait for data interrupt
        }

    // Data transfer
    } else if (status & TWI_bDIF) {
        if (status & TWI_bDIR) {
            //Reading
            twi_write(TWI_SSTATUS, TWI_bDIF, 0x01); // Clear intteripåt and return
        } else {
            //Writing
            uint8 data = twi_read(TWI_SDATA, TWI_bDATA);

            if (cmd == CMD_SET_PWM) {
                setPWM = data;
                cmd = 0;
            } else {
                cmd = data;
            }
        }
    }
}

uint8 currentPWM = 0;

void main() {
    twi_init(1);

    while (1) {

    }
}