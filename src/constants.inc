
;; Constants

DEF run_dma EQU $FF80 ; DMA transfer function


;; Variables

; Used by FUN_ROM31_5040
DEF UNK_C47C EQU $C47C

DEF IsGBC EQU $C525 ; bool - True if Gameboy color
; Set to $7F in FUN_ROM2_42FA after first memcpy
DEF UNK_C526 EQU $C526
; Set to $7F in FUN_ROM2_42FA after second memcpy
DEF UNK_C527 EQU $C527


; Bit 7 set by disable_lcd when screen is turned off
DEF UNK_C5EC EQU $C5EC

; checked if and set to 0 in vram_clear
DEF UNK_D066 EQU $D066


; Set to zero when FUN_3290 clears sound output terminal
DEF UNK_DD09 EQU $DD09


; Set to 0 at the start of FUN_3290
DEF UNK_DD12 EQU $DD12
; Set to 0 at the start of FUN_3290
DEF UNK_DD13 EQU $DD13
; Set to 0 at the start of FUN_3290
DEF UNK_DD14 EQU $DD14
; Set to 0 at the end of FUN_3290
DEF UNK_DD15 EQU $DD15
; Set to 0 at the end of FUN_3290
DEF UNK_DD19 EQU $DD19