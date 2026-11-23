; f5_unaligned: LDW from odd address xC001 -> unaligned (x03)
        .ORIG x3000
        AND R0, R0, #0
        ADD R0, R0, #3
        LSHF R0, R0, #14        ; R0 = xC000
        ADD R0, R0, #1          ; R0 = xC001
        LDW R2, R0, #0          ; unaligned -> handler x1A00
        TRAP x25
        .END
