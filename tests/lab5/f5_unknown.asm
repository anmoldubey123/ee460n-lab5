; f5_unknown: opcode 1010 -> unknown opcode (x05)
        .ORIG x3000
        .FILL xA000             ; unknown opcode
        TRAP x25
        .END
