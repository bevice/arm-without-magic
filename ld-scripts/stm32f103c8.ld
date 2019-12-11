OUTPUT_FORMAT("elf32-littlearm", "elf32-littlearm", "elf32-littlearm")
OUTPUT_ARCH(arm)
MEMORY
{
    ROM  (rx) : ORIGIN = 0x08000000, LENGTH = 64K
    RAM (rwx) : ORIGIN = 0x20000000, LENGTH = 20K
}

SECTIONS
{
    . =  ORIGIN(ROM);
    .isr_vector :
    {
        KEEP(*(.isr_vector))
    }
    . = ALIGN(16);

    .text :
    {
        *(.text*);
    }

    . = ALIGN(4);
    __data_rom__ = .;
    . += SIZEOF(.data);

    . = ORIGIN(RAM);

    .common ALIGN(4) (NOLOAD) :
    {
        *(COMMON)
    }

    .bss (NOLOAD): {
        PROVIDE(__bss_start__ = .);
        *(.bss*)
        PROVIDE(__bss_end__ = .);
    }

    .data ALIGN(4): AT(__data_rom__)
    {
        PROVIDE(__data_start__ = .);
        *(.data*)
        PROVIDE(__data_end__ = .);
    } >RAM

    PROVIDE(__data_lma__ = LOADADDR(.data));
    PROVIDE(__stack_top__ = ORIGIN(RAM) + LENGTH(RAM));
}