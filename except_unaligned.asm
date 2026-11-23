; except_unaligned.asm: unaligned access handler (vector x03). Halts the machine.
        .ORIG x1A00
        TRAP x25
        .END
