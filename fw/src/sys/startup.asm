.org 0

.section .isr_vector,"ax"

.global isr_vector
.global Reset_Handler
.global Default_Handler

.extern main
.extern _datastart
.extern _dataend
.extern _dataLoadAddr
.extern _bssstart
.extern _bssend

.macro NOP
    .word 0
    .word 0
.endm

.macro IRQ handler
    .weak \handler
    jmp \handler
.endm

isr_vector:
    IRQ Reset_Handler
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    #13
    IRQ TCB0_Handler
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    #24
    IRQ TWIS_Handler

datastart: .word _datastart
dataend: .word _dataend
dataLoadAddr: .word _dataLoadAddr
bssstart: .word _bssstart
bssend: .word _bssend

Reset_Handler:
# X = loadaddr
    lds r26, dataLoadAddr
    lds r27, dataLoadAddr+1
# Y = datastart
    lds r28, datastart
    lds r29, datastart+1

#copy low half of datastart
    mov r0, r28
#load low half of dataend
    lds r1, dataend

#skip data copy if size is 0
    sub r1, r0
    breq BSS

DataCopy:
    ld r0, X+
    st Y+, r0
    dec r1
    brne DataCopy

BSS:
# X = bss start
    lds r26, bssstart
    lds r27, bssstart+1

#load low half of bssend
    lds r1, bssend

    sub r1, r26
    breq Main

    eor r0, r0
ZeroBSS:
    st X+, r0
    dec r1
    brne ZeroBSS

Main:
    call main


Default_Handler:
    jmp Default_Handler

