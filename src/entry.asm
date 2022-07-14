
;; Definitions
INCLUDE "src/includes/hardware.inc"
INCLUDE "src/constants.inc"
INCLUDE "src/macros.inc"

INCLUDE "src/todo.inc"


;; Code
INCLUDE "src/ResetVectors/reset_vectors.inc"          ;; ROM0[$0000]
INCLUDE "src/ResetVectors/hardware_interrupts.inc"    ;; ROM0[$0040]
INCLUDE "src/ResetVectors/copy_dma_transfer.inc"      ;; ROM0[$0080]



SECTION "Header", ROM0[$0100]

EntryPoint:
	nop
	jp  Start


ds $150 - @, 0 ; Make room for the header


Start: ;;0150
	;; Tests if console is GBC
	;; Stores result in $C525
	cp  $11
	ld  a,$00
	jr  nz,.dmg
	inc a
.dmg:  ;;0157
	ld  [IsGBC],a

.initialize: ;;015A
	di
	ld  sp,$DFFF

	;; Initialization
	call set_interrupts
	call memory_initialization
	call copy_dma_transfer

	;; Clear $8000-$9C00
	ld  hl,$8000
	ld  bc,$1C00
	xor a
	call memset

	;; Skip if DMG
	ld  a,[IsGBC]
	or  a
	jr  z,.skip_color_vram_clear

	;; Clear [$9800-$9FFF] in VRAM bank 1
	ld  a,$01
	ldh [rVBK],a

	ld  hl,$9800
	ld  bc,$0800
	xor a
	call memset

	ld  a,$00
	ldh [rVBK],a

.skip_color_vram_clear: ;;0189
	;; Clear [$C5DB-$C5DE]
	ld  hl,$C5DB
	xor a
	ld  [hl+],a
	ld  [hl+],a
	ld  [hl+],a
	ld  [hl],a

	;; [UNK_C5DB] = 5
	ld  a,$05
	ld  [UNK_C5DB],a

	;; Selects ROM bank 1
	ld  a,$00
	ld  [rRAMB],a
	ld  a,$00
	ld  [rRAMG],a
	ld  a,$01
	ld  [rROMB0],a
	ld  a,$00
	ld  [rROMB1],a

	;; [UNK_C524] = true
	ld  a,$01
	ld  [UNK_C524],a

	;; [$C60A-$C60B] = $FF
	ld  a,$FF
	ld  [$C60A],a
	ld  [$C60B],a

	call FUN_3290

	;; [$C58C] = $00
	xor a
	ld  [$C58C],a

	;; Skip if DMG
	ld  a,[IsGBC]
	or  a
	jr  z,.skip_color_vram_rst

	;; Set VRAM and WRAM banks to 0 and disable infrared
	xor a
	ldh [rVBK],a
	ldh [rSVBK],a
	ldh [rRP],a

	;; Call FUN_ROM2_42FA
	ld  hl,$42FA
	ld  b,2
	rst $10

	jr  .continue_gbc


.skip_color_vram_rst: ;;01D3
	call FUN_05E2

	;; Skip if result of FUN_05E2 is true
	jr  c,.continue_dmg

.continue_gbc: ;;01D8
	;; [UNK_C524] = false
	xor a
	ld  [UNK_C524],a

	jp  .ei_main_loop


.continue_dmg: ;;01DF

	;; Wait 12 times
	ld  bc,12
	call wait_1750_x

	long_call_rom31_5040 20
	long_call_rom31_5040 2
	long_call_rom31_5040 3
	long_call_rom31_5040 4
	long_call_rom31_5040 5
	long_call_rom31_5040 6
	long_call_rom31_5040 7
	long_call_rom31_5040 8
	long_call_rom31_5040 9

	;; 
	ld  a,$0C
	ld  bc,$0800
	ld  e,$6C
	ld  d,$44
	ld  h,$17
	call FUN_0705

	call wait_7000

	ld  a,$0D
	ld  e,$8C
	ld  d,$44
	ld  b,$17
	call FUN_06A8

	call wait_7000

	long_call_rom31_5040 18
	long_call_rom31_5040 10
	long_call_rom31_5040 19
	long_call_rom31_5040 14

	;; [UNK_C524] = true
	ld  a,$01
	ld  [UNK_C524],a

	;; [$C523] = $FF
	ld  a,$FF
	ld  [$C523],a

	;; [$C51F-$C520] = $00
	xor a
	ld  [$C51F],a
	ld  [$C520],a
	
	;; Call FUN_ROM23_41CF
	ld  hl,$41CF
	ld  b,23
	rst $10

.ei_main_loop: ;;02D1
	ei

.main_loop: ;;02D2

	call vram_clear
	call clear_work_start
	call FUN_0B7F
	call clear_8_hram
	call FUN_0DCA

	;; [$C586],[$C52B],[$C52F],[$C530] = 0
	xor a
	ld  [$C586],a
	ld  [$C52B],a
	ld  [$C52F],a
	ld  [$C530],a
	Call FUN_0355

	;; [$C5DF],[$C5E0],[$C5EE],[$C0C0],[$C0C1],[$C0D8],[$C0D9],[$C5ED],[$C5F0],[$C5F1] = 0
	xor a
	ld  [$C5DF],a
	ld  [$C5E0],a
	ld  [$C5EE],a
	ld  [$C0C0],a
	ld  [$C0C1],a
	ld  [$C0D8],a
	ld  [$C0D9],a
	ld  [$C5ED],a
	ld  [$C5F0],a
	ld  [$C5F1],a

	;; [$FFB9] = 0, [$FFBA] = $80
	ldh [$FFB9], a
	ld  a,$80
	ldh [$FFBA], a

	;; [$C58D-$C58E] = 0
	xor a
	ld  [$C58D],a
	ld  [$C58E],a

	;; [$C604-$C607] = 0
	ld  hl,$C604
	ld  [hl+], a
	ld  [hl+], a
	ld  [hl+], a
	ld  [hl], a

.loop: ;;0324
	;; If [$C58A] = 0, FUN_095B
	ld  a,[$C58A]
	or  a
	call z,FUN_095B

	halt
	
	;; Continue
	ld  a,[$C5DF]
	or  a
	jr  z,.loop

	;; Break
	ld  a,[$C56C]
	or  a
	jr  z,.break

	;; Continue
	bit 7,a
	jr  z,.loop

.break: ;;033D
	di

	call set_interrupts
	call wait_7000

	;; Call FUN_ROM31_5040 with input of 0
	ld  a,0
	ld  [$C47C],a
	ld  b,31
	ld  hl,$5040
	rst $10
	call wait_7000

	jp  .main_loop




INCLUDE "src/Bank0/FUN_0355.inc"                 ;; ROM0[$0355]
INCLUDE "src/Bank0/FUN_03A4.inc"                 ;; ROM0[$03A4]
INCLUDE "src/Bank0/FUN_0474.inc"                 ;; ROM0[$0474]
INCLUDE "src/Bank0/FUN_048A.inc"                 ;; ROM0[$048A]
INCLUDE "src/Bank0/FUN_04ED.inc"                 ;; ROM0[$04ED]
INCLUDE "src/Bank0/AREA_0531.inc"                ;; ROM0[$0531]
INCLUDE "src/Bank0/wait_7000.inc"                ;; ROM0[$05D1]
INCLUDE "src/Bank0/FUN_05E2.inc"                 ;; ROM0[$05E2]
INCLUDE "src/Bank0/FUN_0646.inc"                 ;; ROM0[$0646]
INCLUDE "src/Bank0/wait_1750_x.inc"              ;; ROM0[$0692]
INCLUDE "src/Bank0/FUN_06A8.inc"                 ;; ROM0[$06A8]
INCLUDE "src/Bank0/FUN_0705.inc"                 ;; ROM0[$0705]
INCLUDE "src/Bank0/FUN_076B.inc"                 ;; ROM0[$076B]
INCLUDE "src/Bank0/FUN_077A.inc"                 ;; ROM0[$077A]
INCLUDE "src/Bank0/set_interrupts.inc"           ;; ROM0[$078D]
INCLUDE "src/Bank0/disable_lcd.inc"              ;; ROM0[$0796]
INCLUDE "src/Bank0/FUN_07AA.inc"                 ;; ROM0[$07AA]
INCLUDE "src/Bank0/AREA_07C6.inc"                ;; ROM0[$07AA]
INCLUDE "src/Bank0/FUN_07D1.inc"                 ;; ROM0[$07D1]
INCLUDE "src/Bank0/set_enabled_interrupts.inc"   ;; ROM0[$07D8]
INCLUDE "src/Bank0/FUN_07E0.inc"                 ;; ROM0[$07E0]
INCLUDE "src/Bank0/FUN_07F1.inc"                 ;; ROM0[$07F1]
INCLUDE "src/Bank0/FUN_07FD.inc"                 ;; ROM0[$07FD]
;; ----------------------------------------------------------------- ;;
;; AREA_080A - Pointed to by FUN_ROM31_5134                          ;;
;;  Might be data, but may also be code...                           ;;
LAB_080A:	db $FA, $25, $C5, $B7, $C8, $FA, $00, $40, $F5, $78, $EA ;;
			db $00, $21, $06, $40, $1A, $22, $13, $05, $20, $FA, $06 ;;
LAB_0820:	db $00, $09, $36, $7F, $F1, $EA, $00, $21, $C9           ;;
;; ----------------------------------------------------------------- ;;
INCLUDE "src/Bank0/copy_bg_palette.inc"          ;; ROM0[$0829]
INCLUDE "src/Bank0/copy_obj_palette.inc"         ;; ROM0[$085C]
;INCLUDE "src/Bank0/FUN_0897.inc"                 ;; ROM0[$0897]

INCLUDE "src/Bank0/memory_initialization.inc"    ;; ROM0[$08D0]
INCLUDE "src/Bank0/vram_clear.inc"               ;; ROM0[$0930]
INCLUDE "src/Bank0/memset.inc"                   ;; ROM0[$0949]
INCLUDE "src/Bank0/FUN_095B.inc"                 ;; ROM0[$095B]
;INCLUDE "src/Bank0/FUN_09F3.inc"                 ;; ROM0[$09F3]
;INCLUDE "src/Bank0/FUN_0A17.inc"                 ;; ROM0[$0A17]
;INCLUDE "src/Bank0/FUN_0A61.inc"                 ;; ROM0[$0A61]

INCLUDE "src/Bank0/FUN_0B7F.inc"                 ;; ROM0[$0B7F]
INCLUDE "src/Bank0/clear_8_hram.inc"             ;; ROM0[$0B9B]

INCLUDE "src/Bank0/clear_work_start.inc"         ;; ROM0[$0BA7]

INCLUDE "src/Bank0/FUN_0DCA.inc"                 ;; ROM0[$0DCA]

INCLUDE "src/Bank0/FUN_14D1.inc"                 ;; ROM0[$14D1]

INCLUDE "src/Bank0/memcpy.inc"                   ;; ROM0[$1679]

INCLUDE "src/Bank0/FUN_255B.inc"                 ;; ROM0[$255B]
INCLUDE "src/Bank0/stat_interrupt.inc"           ;; ROM0[$256A]

INCLUDE "src/Bank0/FUN_3290.inc"                 ;; ROM0[$3290]


INCLUDE "src/Bank1/FUN_4001.inc"                 ;; ROM0[$4001], BANK[1]


INCLUDE "src/Bank2/FUN_42FA.inc"                 ;; ROMX[$3290], BANK[2]

INCLUDE "src/Bank27/FUN_4001.inc"                ;; ROMX[$5040], BANK[27]

INCLUDE "src/Bank31/FUN_5040.inc"                ;; ROMX[$5040], BANK[31]



SECTION "End", ROMX[$7FFF], BANK[255]
	db  $00