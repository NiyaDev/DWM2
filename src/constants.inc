
;; Constants
DEF run_dma EQU $FF80 ; DMA transfer function


;; Variables
DEF IsGBC EQU $C525 ; bool - True if Gameboy color


; Bit 7 set by disable_lcd when screen is turned off
DEF UNK_C5EC EQU $C5EC

; checked if and set to 0 in vram_clear
DEF UNK_D066 EQU $D066