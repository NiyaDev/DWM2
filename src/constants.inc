
;; Constants

DEF run_dma EQU $FF80 ; DMA transfer function

DEF BCPD_MEM_LENGTH EQU $40
DEF BCPD_MEM_UPPER  EQU $C4
DEF BCPD_MEM_LOWER  EQU $9F

DEF OCPD_MEM_LENGTH EQU $40
DEF OCPD_MEM_UPPER  EQU $C4
DEF OCPD_MEM_LOWER  EQU $DF


;; Variables

; Used by FUN_ROM31_5040
DEF UNK_C47C EQU $C47C


; Memory $C47F->$C48F
; Set to zero in FUN_076B


; The start of background color data in memory
DEF BCPD_MEM_START EQU $C49F
; The start of object color data in memory
DEF OCPD_MEM_START EQU $C4DF


; entry sets to true and false in different places
; If false, return from wait_7000   early
; If false, return from wait_1750_x early
; If false, return from FUN_06A8    early
; If false, return from FUN_0705    early
; If false, return from FUN_07AA    early
;; Tentative:
;;   [UNK_C524] == [WAIT]
DEF UNK_C524 EQU $C524 ; bool
DEF IsGBC    EQU $C525 ; bool - True if Gameboy color

; Set to $7F in FUN_ROM2_42FA after first memcpy
; Bit  7   skip flag
; Bits 3-5 used for offset
; Tentative:
;;   [UNK_C526] == [DAT_rBCPS]
DEF UNK_C526 EQU $C526 ; byte

; Set to $7F in FUN_ROM2_42FA after second memcpy
; Bit  7   skip flag
; Bits 3-5 used for offset
; Tentative:
;;   [UNK_C527] == [DAT_rOCPS]
DEF UNK_C527 EQU $C527

; If == 0 in FUN_0474, calls FUN_0BB4
; If != 0 in FUN_048A && ([UNK_C56C] & $80) == false, return from FUN_048A
DEF UNK_C56C EQU $C56C

; If != 0, check [UNK_C56C] in FUN_048A
; If != 0, call FUN_14D1 in FUN_077A
DEF UNK_C58A EQU $C58A


; Grabbed in FUN_07FD and used in [rBGP], [rOBP0], and [rOBP1] respectively
DEF UNK_C5E9 EQU $C5E9 ; byte
DEF UNK_C5EA EQU $C5EA ; byte
DEF UNK_C5EB EQU $C5EB ; byte


; Bit 7 set by disable_lcd when screen is turned off
; Bit 7 set by FUN_07AA, then it's copied to rLCDC
; Set to $81 by FUN_06A8
; Loaded into [rLCDC] by FUN_07F1
DEF UNK_C5EC EQU $C5EC ; byte

; entry sets to 5
; FUN_0355 chooses which long call based on this as an offset
; FUN_048A chooses which long call based on this as an offset
DEF UNK_C5DB EQU $C5DB

; FUN_048A immediately leaves if != 0
DEF UNK_C5DF EQU $C5DF


; In FUN_04ED, if ([UNK_C604] | [UNK_C605]) == false, return
;; Tentative:
;;   [UNK_C604] == [SCY_MOD] | byte
;;   [UNK_C605] == [SCX_MOD] | byte
DEF UNK_C604 EQU $C604
DEF UNK_C605 EQU $C605


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


; Set to 0 at start of FUN_0474
DEF UNK_FFB1 EQU $FFB1

;
DEF rBCPD_SH EQU $69

; Copied to [rSCX], [rSCY], [rWX], and [rWY] respectively in FUN_07E0
DEF UNK_FFA1 EQU $A1
DEF UNK_FFA5 EQU $A5
DEF UNK_FF9F EQU $9F
DEF UNK_FFA0 EQU $A0