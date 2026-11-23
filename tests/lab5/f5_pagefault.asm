; f5_pagefault: LDW from x4000 (page 32, not valid) -> page fault (x02)
        .ORIG x3000
        AND R0, R0, #0
        ADD R0, R0, #1
        LSHF R0, R0, #14        ; R0 = x4000
        LDW R2, R0, #0          ; page fault -> handler x1400
        TRAP x25
        .END
