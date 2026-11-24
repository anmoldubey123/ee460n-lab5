; pagetable.asm: LC-3b page table at physical x1000 (frame 8)
; PTE format: PFN[13:9] P[3] V[2] M[1] R[0]
        .ORIG x1000
        .FILL x0004     ; page 0 (system) -> frame 0, P=0 V=1
        .FILL x0204     ; page 1 (system) -> frame 1, P=0 V=1
        .FILL x0404     ; page 2 (system) -> frame 2, P=0 V=1
        .FILL x0604     ; page 3 (system) -> frame 3, P=0 V=1
        .FILL x0804     ; page 4 (system) -> frame 4, P=0 V=1
        .FILL x0A04     ; page 5 (system) -> frame 5, P=0 V=1
        .FILL x0C04     ; page 6 (system) -> frame 6, P=0 V=1
        .FILL x0E04     ; page 7 (system) -> frame 7, P=0 V=1
        .FILL x1004     ; page 8 (system) -> frame 8, P=0 V=1
        .FILL x1204     ; page 9 (system) -> frame 9, P=0 V=1
        .FILL x1404     ; page 10 (system) -> frame 10, P=0 V=1
        .FILL x1604     ; page 11 (system) -> frame 11, P=0 V=1
        .FILL x1804     ; page 12 (system) -> frame 12, P=0 V=1
        .FILL x1A04     ; page 13 (system) -> frame 13, P=0 V=1
        .FILL x1C04     ; page 14 (system) -> frame 14, P=0 V=1
        .FILL x1E04     ; page 15 (system) -> frame 15, P=0 V=1
        .FILL x2004     ; page 16 (system) -> frame 16, P=0 V=1
        .FILL x2204     ; page 17 (system) -> frame 17, P=0 V=1
        .FILL x2404     ; page 18 (system) -> frame 18, P=0 V=1
        .FILL x2604     ; page 19 (system) -> frame 19, P=0 V=1
        .FILL x2804     ; page 20 (system) -> frame 20, P=0 V=1
        .FILL x2A04     ; page 21 (system) -> frame 21, P=0 V=1
        .FILL x2C04     ; page 22 (system) -> frame 22, P=0 V=1
        .FILL x2E04     ; page 23 (system) -> frame 23, P=0 V=1
        .FILL x320C     ; page 24 (user, x3000) -> frame 25, P=1 V=1
        .FILL x0008     ; page 25 (user) not resident, P=1 V=0
        .FILL x0008     ; page 26 (user) not resident, P=1 V=0
        .FILL x0008     ; page 27 (user) not resident, P=1 V=0
        .FILL x0008     ; page 28 (user) not resident, P=1 V=0
        .FILL x0008     ; page 29 (user) not resident, P=1 V=0
        .FILL x0008     ; page 30 (user) not resident, P=1 V=0
        .FILL x0008     ; page 31 (user) not resident, P=1 V=0
        .FILL x3C0C     ; page 32 (user, x4000) -> frame 30, P=1 V=1
        .FILL x0008     ; page 33 (user) not resident, P=1 V=0
        .FILL x0008     ; page 34 (user) not resident, P=1 V=0
        .FILL x0008     ; page 35 (user) not resident, P=1 V=0
        .FILL x0008     ; page 36 (user) not resident, P=1 V=0
        .FILL x0008     ; page 37 (user) not resident, P=1 V=0
        .FILL x0008     ; page 38 (user) not resident, P=1 V=0
        .FILL x0008     ; page 39 (user) not resident, P=1 V=0
        .FILL x0008     ; page 40 (user) not resident, P=1 V=0
        .FILL x0008     ; page 41 (user) not resident, P=1 V=0
        .FILL x0008     ; page 42 (user) not resident, P=1 V=0
        .FILL x0008     ; page 43 (user) not resident, P=1 V=0
        .FILL x0008     ; page 44 (user) not resident, P=1 V=0
        .FILL x0008     ; page 45 (user) not resident, P=1 V=0
        .FILL x0008     ; page 46 (user) not resident, P=1 V=0
        .FILL x0008     ; page 47 (user) not resident, P=1 V=0
        .FILL x0008     ; page 48 (user) not resident, P=1 V=0
        .FILL x0008     ; page 49 (user) not resident, P=1 V=0
        .FILL x0008     ; page 50 (user) not resident, P=1 V=0
        .FILL x0008     ; page 51 (user) not resident, P=1 V=0
        .FILL x0008     ; page 52 (user) not resident, P=1 V=0
        .FILL x0008     ; page 53 (user) not resident, P=1 V=0
        .FILL x0008     ; page 54 (user) not resident, P=1 V=0
        .FILL x0008     ; page 55 (user) not resident, P=1 V=0
        .FILL x0008     ; page 56 (user) not resident, P=1 V=0
        .FILL x0008     ; page 57 (user) not resident, P=1 V=0
        .FILL x0008     ; page 58 (user) not resident, P=1 V=0
        .FILL x0008     ; page 59 (user) not resident, P=1 V=0
        .FILL x0008     ; page 60 (user) not resident, P=1 V=0
        .FILL x0008     ; page 61 (user) not resident, P=1 V=0
        .FILL x0008     ; page 62 (user) not resident, P=1 V=0
        .FILL x0008     ; page 63 (user) not resident, P=1 V=0
        .FILL x0008     ; page 64 (user) not resident, P=1 V=0
        .FILL x0008     ; page 65 (user) not resident, P=1 V=0
        .FILL x0008     ; page 66 (user) not resident, P=1 V=0
        .FILL x0008     ; page 67 (user) not resident, P=1 V=0
        .FILL x0008     ; page 68 (user) not resident, P=1 V=0
        .FILL x0008     ; page 69 (user) not resident, P=1 V=0
        .FILL x0008     ; page 70 (user) not resident, P=1 V=0
        .FILL x0008     ; page 71 (user) not resident, P=1 V=0
        .FILL x0008     ; page 72 (user) not resident, P=1 V=0
        .FILL x0008     ; page 73 (user) not resident, P=1 V=0
        .FILL x0008     ; page 74 (user) not resident, P=1 V=0
        .FILL x0008     ; page 75 (user) not resident, P=1 V=0
        .FILL x0008     ; page 76 (user) not resident, P=1 V=0
        .FILL x0008     ; page 77 (user) not resident, P=1 V=0
        .FILL x0008     ; page 78 (user) not resident, P=1 V=0
        .FILL x0008     ; page 79 (user) not resident, P=1 V=0
        .FILL x0008     ; page 80 (user) not resident, P=1 V=0
        .FILL x0008     ; page 81 (user) not resident, P=1 V=0
        .FILL x0008     ; page 82 (user) not resident, P=1 V=0
        .FILL x0008     ; page 83 (user) not resident, P=1 V=0
        .FILL x0008     ; page 84 (user) not resident, P=1 V=0
        .FILL x0008     ; page 85 (user) not resident, P=1 V=0
        .FILL x0008     ; page 86 (user) not resident, P=1 V=0
        .FILL x0008     ; page 87 (user) not resident, P=1 V=0
        .FILL x0008     ; page 88 (user) not resident, P=1 V=0
        .FILL x0008     ; page 89 (user) not resident, P=1 V=0
        .FILL x0008     ; page 90 (user) not resident, P=1 V=0
        .FILL x0008     ; page 91 (user) not resident, P=1 V=0
        .FILL x0008     ; page 92 (user) not resident, P=1 V=0
        .FILL x0008     ; page 93 (user) not resident, P=1 V=0
        .FILL x0008     ; page 94 (user) not resident, P=1 V=0
        .FILL x0008     ; page 95 (user) not resident, P=1 V=0
        .FILL x380C     ; page 96 (user, xC000) -> frame 28, P=1 V=1
        .FILL x0008     ; page 97 (user) not resident, P=1 V=0
        .FILL x0008     ; page 98 (user) not resident, P=1 V=0
        .FILL x0008     ; page 99 (user) not resident, P=1 V=0
        .FILL x0008     ; page 100 (user) not resident, P=1 V=0
        .FILL x0008     ; page 101 (user) not resident, P=1 V=0
        .FILL x0008     ; page 102 (user) not resident, P=1 V=0
        .FILL x0008     ; page 103 (user) not resident, P=1 V=0
        .FILL x0008     ; page 104 (user) not resident, P=1 V=0
        .FILL x0008     ; page 105 (user) not resident, P=1 V=0
        .FILL x0008     ; page 106 (user) not resident, P=1 V=0
        .FILL x0008     ; page 107 (user) not resident, P=1 V=0
        .FILL x0008     ; page 108 (user) not resident, P=1 V=0
        .FILL x0008     ; page 109 (user) not resident, P=1 V=0
        .FILL x0008     ; page 110 (user) not resident, P=1 V=0
        .FILL x0008     ; page 111 (user) not resident, P=1 V=0
        .FILL x0008     ; page 112 (user) not resident, P=1 V=0
        .FILL x0008     ; page 113 (user) not resident, P=1 V=0
        .FILL x0008     ; page 114 (user) not resident, P=1 V=0
        .FILL x0008     ; page 115 (user) not resident, P=1 V=0
        .FILL x0008     ; page 116 (user) not resident, P=1 V=0
        .FILL x0008     ; page 117 (user) not resident, P=1 V=0
        .FILL x0008     ; page 118 (user) not resident, P=1 V=0
        .FILL x0008     ; page 119 (user) not resident, P=1 V=0
        .FILL x0008     ; page 120 (user) not resident, P=1 V=0
        .FILL x0008     ; page 121 (user) not resident, P=1 V=0
        .FILL x0008     ; page 122 (user) not resident, P=1 V=0
        .FILL x0008     ; page 123 (user) not resident, P=1 V=0
        .FILL x0008     ; page 124 (user) not resident, P=1 V=0
        .FILL x0008     ; page 125 (user) not resident, P=1 V=0
        .FILL x3A0C     ; page 126 (user stack, xFC00) -> frame 29, P=1 V=1
        .FILL x0008     ; page 127 (user) not resident, P=1 V=0
        .END
