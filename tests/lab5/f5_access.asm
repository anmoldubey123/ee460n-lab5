; f5_access: STW/LDW/LDB/STB through translation, then a user TRAP
        .ORIG x3000
        AND R1, R1, #0
        ADD R1, R1, #7          ; R1 = 7
        AND R0, R0, #0
        ADD R0, R0, #3
        LSHF R0, R0, #14        ; R0 = xC000 (page 96 -> frame 28)
        STW R1, R0, #10         ; M[xC014] = x0007, sets R and M
        LDW R2, R0, #10         ; R2 = x0007
        LDB R3, R0, #20         ; R3 = x0007 (byte at xC014)
        STB R1, R0, #21         ; byte xC015 = x07, word = x0707
        LDW R4, R0, #10         ; R4 = x0707
        TRAP x25                ; user TRAP: page 0 read allowed
        .END
