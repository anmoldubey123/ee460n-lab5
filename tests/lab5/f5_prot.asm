; f5_prot: user jumps to x0052 (system page 0) -> protection (x04)
        .ORIG x3000
        AND R5, R5, #0
        ADD R5, R5, #10
        LSHF R5, R5, #3         ; R5 = 80
        ADD R5, R5, #2          ; R5 = 82 = x0052
        JMP R5                  ; fetch x0052 in user mode
        TRAP x25
        .END
