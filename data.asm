; data.asm: 20 bytes at xC000, two per word, low byte first:
; x12 x11 x39 x23 x02 xF6 x12 x23 x56 x89 xBC xEF x00 x01 ... x07
        .ORIG xC000
        .FILL x1112             ; xC000 = x12, xC001 = x11
        .FILL x2339             ; xC002 = x39, xC003 = x23
        .FILL xF602             ; xC004 = x02, xC005 = xF6
        .FILL x2312             ; xC006 = x12, xC007 = x23
        .FILL x8956             ; xC008 = x56, xC009 = x89
        .FILL xEFBC             ; xC00A = xBC, xC00B = xEF
        .FILL x0100             ; xC00C = x00, xC00D = x01
        .FILL x0302             ; xC00E = x02, xC00F = x03
        .FILL x0504             ; xC010 = x04, xC011 = x05
        .FILL x0706             ; xC012 = x06, xC013 = x07
        .END
