; vector_table.asm: interrupt/exception vector table. The entry for vector V is at x0200 + 2V.
        .ORIG x0200
        .FILL x0000     ; x00: unused
        .FILL x1200     ; x01: timer interrupt -> int.asm
        .FILL x1400     ; x02: page fault -> except_pagefault.asm
        .FILL x1A00     ; x03: unaligned access -> except_unaligned.asm
        .FILL x1600     ; x04: protection -> except_prot.asm
        .FILL x1C00     ; x05: unknown opcode -> except_unknown.asm
        .END
