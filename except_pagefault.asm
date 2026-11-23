; except_pagefault.asm: page fault handler (vector x02). Halts the machine.
        .ORIG x1400
        TRAP x25
        .END
