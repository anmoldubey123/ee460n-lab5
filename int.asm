; int.asm: timer interrupt service routine at x1200.
; Clears the reference bit (bit 0) of all 128 PTEs. The page table
; starts at x1000; system pages map to the same frames, so the ISR
; can use x1000 directly as a virtual address.
        .ORIG x1200
        ADD R6, R6, #-2         ; push R0..R3 on the supervisor stack
        STW R0, R6, #0
        ADD R6, R6, #-2
        STW R1, R6, #0
        ADD R6, R6, #-2
        STW R2, R6, #0
        ADD R6, R6, #-2
        STW R3, R6, #0
        LEA R0, CONSTS          ; R0 = address of the constants table
        LDW R3, R0, #1          ; R3 = xFFFE, mask that clears bit 0
        LDW R1, R0, #2          ; R1 = 128, PTEs left
        LDW R0, R0, #0          ; R0 = x1000, address of PTE 0
LOOP    LDW R2, R0, #0          ; R2 = PTE
        AND R2, R2, R3          ; clear the R bit
        STW R2, R0, #0          ; write the PTE back
        ADD R0, R0, #2          ; next PTE
        ADD R1, R1, #-1         ; one PTE fewer left
        BRp LOOP                ; repeat for all 128
        LDW R3, R6, #0          ; pop R3..R0
        ADD R6, R6, #2
        LDW R2, R6, #0
        ADD R6, R6, #2
        LDW R1, R6, #0
        ADD R6, R6, #2
        LDW R0, R6, #0
        ADD R6, R6, #2
        RTI
CONSTS  .FILL x1000             ; address of the page table
        .FILL xFFFE             ; mask: all bits except R
        .FILL #128              ; number of PTEs
        .END
