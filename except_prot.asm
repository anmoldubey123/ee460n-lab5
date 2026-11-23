; except_prot.asm: protection exception handler (vector x04). Halts the machine.
        .ORIG x1600
        TRAP x25
        .END
