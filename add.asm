; add.asm: sum the 20 signed bytes at xC000, store the 16-bit sum
; at xC014, then jump to the address given by the sum.
        .ORIG x3000
        LEA R0, CONSTS          ; R0 = address of the constants table
        LDW R1, R0, #0          ; R1 = xC000, pointer to the data
        LDW R6, R0, #1          ; R6 = xFE00, user stack pointer
        AND R2, R2, #0          ; R2 = sum = 0
        AND R3, R3, #0
        ADD R3, R3, #10
        ADD R3, R3, #10         ; R3 = 20, bytes left
LOOP    LDB R4, R1, #0          ; R4 = next byte, sign-extended
        ADD R2, R2, R4          ; sum = sum + byte
        ADD R1, R1, #1          ; pointer = pointer + 1
        ADD R3, R3, #-1         ; one byte fewer left
        BRp LOOP                ; repeat until all 20 are added
        STW R2, R1, #0          ; R1 is now xC014: M[xC014] = sum
        JMP R2                  ; jump to the sum (x0052)
CONSTS  .FILL xC000             ; start of the data
        .FILL xFE00             ; initial user stack pointer
        .END
