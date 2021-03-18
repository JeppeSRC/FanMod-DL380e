ENTRY(Reset_Handler)

MEMORY {
    FLASH_CODE (rx) : ORIGIN = 0x0000, LENGTH = 4096
    FLASH_DATA (rx) : ORIGIN = 0x8000, LENGTH = 4096
    RAM (rxw) : ORIGIN = 0x3F00, LENGTH = 256
}

SECTIONS {
    .isr_vector : {
        KEEP(*(.isr_vector))
    } > FLASH_CODE

    .text : {
        *(.text)
        *(.text*)
        _textend = .;
    } > FLASH_CODE

    .rodata : {
        *(.rodata)
        *(.rodata*)
    } > FLASH_DATA AT > FLASH_CODE

    _dataLoadAddr = LOADADDR(.data) + 0x8000;

    .data : {
        _datastart = .;
        *(.data)
        *(.data*)
        _dataend = .;
    } > RAM AT > FLASH_CODE

    .bss : {
        _bssstart = .;
        *(.bss)
        *(.bss*)
        _bssend = .;
    } > RAM
}