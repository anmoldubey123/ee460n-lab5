; f5_priority: LDW from x4001: odd AND invalid page -> unaligned wins
        .ORIG x3000
        AND R0, R0, #0
        ADD R0, R0, #1
        LSHF R0, R0, #14        ; R0 = x4000
        ADD R0, R0, #1          ; R0 = x4001
        LDW R2, R0, #0          ; unaligned (x03), not page fault
        TRAP x25
        .END
