#include <sys/cpuint.h>
#include <sys/clkctrl.h>
#include <sys/tca0.h>
#include <sys/tcb0.h>
#include <sys/twi.h>
#include <sys/port.h>
#include <sys/evsys.h>

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
                setPWM = 200 - data;
                cmd = 0;
            } else {
                cmd = data;
            }
        }
    }
}

void TCB_Handler() {
    uint16 cnt = tcb_readw(TCB_CNT);
    uint16 ccmp = tcb_readw(TCB_CCMP);

    float duty = (float)ccmp / (float)cnt;

    requestedPWM = 200 - (uint8)(200.0f * duty);
}

uint8 currentPWM = 0;

void init() {
    twi_init(1); //Initialize twi

    port_pin_mode(3, 1); // Set PA3 to output

    //25KHz PWM
    tca_write(TCA_CTRLB, 0xFF, TCA_bCMP0EN | 0x03); //Enable PWM on WO0 (PA3)
    tca_writew(TCA_PER, 800); // 20 000 000 / 25 000
    tca_writew(TCA_CMP0, 400); //Default to 50% duty cycle
    tca_write(TCA_CTRLA, TCA_bENABLE, 1); //Enable counter

    port_pin_mode(6, 0); //Set PA6 to input

    evsys_write(EVSYS_ASYNCCH0, EVSYS_bASYNCHCH, 0x10); //Set PA6 as event source for ASYNCCH0
    evsys_write(EVSYS_ASYNCUSER0, EVSYS_bASYNCUSER, 0x03); //Set ASYNCH0 as source for TCB input events

    tcb_write(TCB_CTRLB, 0xFF, 0x05); // Enable frequency and pulse-width measurements
    tcb_write(TCB_INTCTRL, 0xFF, 0x01); // Enable capture interrupt
    tcb_write(TCB_CTRLA, 0xFF, 0x01); // Enable
}

void main() {



    while (1) {

    }
}