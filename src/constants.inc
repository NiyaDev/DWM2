
;; Constants

DEF run_dma EQU $FF80 ; DMA transfer function

DEF BCPD_MEM_LENGTH EQU $40
DEF BCPD_MEM_UPPER  EQU $C4
DEF BCPD_MEM_LOWER  EQU $9F

DEF OCPD_MEM_LENGTH EQU $40
DEF OCPD_MEM_UPPER  EQU $C4
DEF OCPD_MEM_LOWER  EQU $DF


;; Variables

; FUN_0A17 - Copied to [UNK_C55E]
DEF UNK_C474 EQU $C474

; FUN_0A17 - Copied to [UNK_C560]
DEF UNK_C476 EQU $C476

; FUN_ROM31_5040
DEF UNK_C47C EQU $C47C

; Memory $C47F->$C48F
; Set to zero in FUN_076B

; The start of background color data in memory
DEF BCPD_MEM_START EQU $C49F
; The start of object color data in memory
DEF OCPD_MEM_START EQU $C4DF


; entry sets to true and false in different places.
; wait_7000 - If false, return early.
; wait_1750_x - If false, return early.
; FUN_06A8 - If false, return early.
; FUN_0705 - If false, return early.
; FUN_07AA - If false, return early.
; FUN_0A17 - If false, use different version.
;; Tentative:
;;   [UNK_C524] == [WAIT]
DEF UNK_C524 EQU $C524 ; bool
DEF IsGBC    EQU $C525 ; bool - True if Gameboy color
; FUN_ROM2_42FA - Set to $7F after first memcpy
; Bit  7   skip flag
; Bits 3-5 used for offset
; Tentative:
;;   [UNK_C526] == [DAT_rBCPS]
DEF UNK_C526 EQU $C526 ; byte
; FUN_ROM2_42FA - Set to $7F after second memcpy
; Bit  7   skip flag
; Bits 3-5 used for offset
; Tentative:
;;   [UNK_C527] == [DAT_rOCPS]
DEF UNK_C527 EQU $C527


; FUN_0A17 - cleared.
; FUN_0A8D - If == 0 and [UNK_C58A] == 0, clears [UNK_C560] and [UNK_C561].
DEF UNK_C55D EQU $C55D
; FUN_0A17 - Copied to [UNK_C55F]
; FUN_0A8D - Loaded, XORd with [UNK_C55F], ANDd with original value, and saved into [$C562]
;          - Checked if 0.
;          - Checked if == [UNK_C55F].
DEF UNK_C55E EQU $C55E
DEF UNK_C55F EQU $C55F
; FUN_0A17 - Copied to [UNK_C561].
; FUN_0A8D - Cleared if [UNK_C58A] == 0 and [UNK_C55D] == 0.
DEF UNK_C560 EQU $C560
DEF UNK_C561 EQU $C561
; FUN_0A8D - Set to (([UNK_C55E] ^ [UNK_C55F]) & [UNK_C55E]).
DEF UNK_C562 EQU $C562
; FUN_0A8D - Cleared.
;          - Set to [UNK_C562].
;          - Set to [UNK_C55E].
DEF UNK_C563 EQU $C563
; FUN_0A8D - Set to $14.
;          - If == 0 set to 6, else decrement.
DEF UNK_C564 EQU $C564
; FUN_0A8D - Set to (([UNK_C560] ^ [UNK_C561]) & [UNK_C560]).
DEF UNK_C566 EQU $C566
; FUN_0A8D - Cleared.
;          - Set to [UNK_C566].
;          - Set to [UNK_C560].
DEF UNK_C567 EQU $C567
; FUN_0A8D - Set to $14.
;          - If == 0 set to 6, else decrement.
DEF UNK_C568 EQU $C568


; FUN_0474 - If == 0 call FUN_0BB4.
; FUN_048A - If != 0 && ([UNK_C56C] & $80) == false, return.
DEF UNK_C56C EQU $C56C

; FUN_048A - If != 0, check [UNK_C56C].
; FUN_077A - If != 0, call FUN_14D1.
; FUN_0A8D - If == 0 and [UNK_C55D] == 0, clears [UNK_C560] and [UNK_C561].
DEF UNK_C58A EQU $C58A

; FUN_095B - byte is loaded from [[UNK_C5E8] + $0973].
DEF UNK_C5E7 EQU $C5E7 ; byte

; FUN_095B - Loaded, incremented, then AND'd with $7F and resaved.
DEF UNK_C5E8 EQU $C5E8 ; byte

; FUN_07FD - Loaded and used in [rBGP], [rOBP0], and [rOBP1] respectively.
; FUN_0B7F - Set to $D2, $D2, $E2 respectively.
DEF UNK_C5E9 EQU $C5E9 ; byte
DEF UNK_C5EA EQU $C5EA ; byte
DEF UNK_C5EB EQU $C5EB ; byte

; FUN_0B7F - Set to $D2, $D2, $E2 respectively.
DEF UNK_D040 EQU $D040 ; byte
DEF UNK_D041 EQU $D041 ; byte
DEF UNK_D042 EQU $D042 ; byte


; disable_lcd - Bit 7 set when screen is turned off.
; FUN_07AA - Bit 7 set, then it's copied to rLCDC.
; FUN_06A8 - Set to $81.
; FUN_07F1 - Loaded into [rLCDC].
DEF UNK_C5EC EQU $C5EC ; byte

; entry - Set to 5
; FUN_0355 - Chooses which long call based on this as an offset.
; FUN_048A - Chooses which long call based on this as an offset.
DEF UNK_C5DB EQU $C5DB

; FUN_048A - Immediately leaves if != 0.
DEF UNK_C5DF EQU $C5DF


; FUN_04ED - if ([UNK_C604] | [UNK_C605]) == false, return.
;; Tentative:
;;   [UNK_C604] == [SCY_MOD] | byte
;;   [UNK_C605] == [SCX_MOD] | byte
DEF UNK_C604 EQU $C604
DEF UNK_C605 EQU $C605


; vram_clear - checked if and set to 0.
DEF UNK_D066 EQU $D066


; FUN_09F3 - loaded from, Logic is done, then saved.
DEF UNK_CD03 EQU $CD03 ; byte
DEF UNK_CD04 EQU $CD04 ; byte


; FUN_3290 - Set to zero when sound output terminal cleared.
DEF UNK_DD09 EQU $DD09


; FUN_3290 - Set to 0 at the start.
DEF UNK_DD12 EQU $DD12
; FUN_3290 - Set to 0 at the start.
DEF UNK_DD13 EQU $DD13
; FUN_3290 - Set to 0 at the start.
DEF UNK_DD14 EQU $DD14
; FUN_3290 - Set to 0 at the end.
DEF UNK_DD15 EQU $DD15
; FUN_3290 - Set to 0 at the end.
DEF UNK_DD19 EQU $DD19


; FUN_0474 - Set to 0 at start.
DEF UNK_FFB1 EQU $FFB1

;
DEF rBCPD_SH EQU $69

; FUN_07E0 - Copied to [rSCX], [rSCY], [rWX], and [rWY] respectively.
DEF UNK_FFA1 EQU $A1
DEF UNK_FFA5 EQU $A5
DEF UNK_FF9F EQU $9F
DEF UNK_FFA0 EQU $A0