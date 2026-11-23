; except_unknown.asm: unknown opcode handler (vector x05). Halts the machine.
        .ORIG x1C00
        TRAP x25
        .END
