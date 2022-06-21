

INCLUDE "src/includes/hardware.inc"



DEF IsGBC          EQU $C525



INCLUDE "src/ResetVectors/ResetVectors.inc"         ;; ROM0[$0000]
INCLUDE "src/ResetVectors/HardInterrupts.inc"       ;; ROM0[$0040]
INCLUDE "src/ResetVectors/CopyDMATransfer.inc"      ;; ROM0[$0080]


SECTION "Header", ROM0[$0100]

EntryPoint:
	nop
	jp  Start

		ds $150 - @, 0 ; Make room for the header

Start:             ;; $0150
	cp  $11                  ;; 
	ld  a,$00                ;; 
	jr  nz,.DMG              ;; if console != GBC, jump
	inc a                    ;; else, IsGBC = true

.DMG:              ;; $0157
	ld  [IsGBC],a            ;; 

.initialize:       ;; $015A
	di                       ;;
	ld  sp,$DFFF             ;; 

	call SetInterrupts       ;; =SetInterrupts()
	call MemInitialization   ;; =MemInitialization()
	call CopyDMATransfer     ;; =CopyDMATransfer()

	ld  hl,$8000             ;; =Pointer    ;;
	ld  bc,$1C00             ;; =Counter    ;; Clears memory at
	xor a                    ;; =Value      ;;   $8000-$9C00
	call Memset              ;; =Memset()   ;;      (VRAM)

	ld  a,[IsGBC]            ;;
	or  a                    ;;
	jr  z,.skipColorVRAMClear;; if IsGBC == false, jump

	ld  a,$01                ;;
	ldh [rVBK],a             ;;
	ld  hl,$9800             ;; =Pointer    ;;
	ld  bc,$0800             ;; =Counter    ;; Clears memory at
	xor a                    ;; =Value      ;;   $9800-$9FFF
	call Memset              ;; =Memset()   ;;      (VRAM)

	ld  a,$00                ;;
	ldh [rVBK],a             ;;

.skipColorVRAMClear:    ;; $0189
	ld  hl,$C5DB             ;;
	xor a                    ;;
	ld  [hl+],a              ;;
	ld  [hl+],a              ;;
	ld  [hl+],a              ;;
	ld  [hl],a               ;; Clears memory $C5DB-$C5DE
	ld  a,$05                ;;
	ld  [$C5DB],a            ;; [$C5DB] = $05

	ld  a,$00                ;;
	ld  [rRAMB],a            ;; Selects cart RAM bank 0
	ld  a,$00                ;;
	ld  [rRAMG],a            ;; Disables writing to Cart RAM 
	ld  a,$01                ;;                                           ;;
	ld  [rROMB0],a           ;; Lower 8-bits of ROM banks set to 0x01     ;; ROM Bank 1
	ld  a,$00                ;;                                           ;;  selected
	ld  [rROMB1],a           ;; Upper 1-bit  of ROM banks set to 0x00     ;;

	ld  a,$01                ;; 
	ld  [$C524],a            ;; [$C524] = $01
	ld  a,$FF                ;; 
	ld  [$C60A],a            ;; 
	ld  [$C60B],a            ;; [$C60A-$C60B] = $FF

	call FUN_3290            ;; =FUN_3290() ;; Audio prep?

	xor a                    ;;
	ld  [$C58C],a            ;; [$C58C] = $00

	ld  a,[IsGBC]            ;;
	or  a                    ;;
	jr  z,.skipColorVRAM_RST ;; if isGBC == false, skip

	xor a                    ;;
	ldh [rVBK],a             ;;
	ldh [rSVBK],a            ;;
	ldh [rRP],a              ;;

	ld  hl,$42FA             ;;
	ld  b,$02                ;;
	rst $10                  ;; =RST10 (2, $42FA) ;; Call FUN_ROM2_42FA

	jr  .LAB_01D8            ;;

.skipColorVRAM_RST:;; $01D3
	call FUN_05E2
	jr  c,.LAB_01DF

.LAB_01D8:         ;; $01D8
	xor a
	ld  [$C524],a
	jp  .LAB_02D1

.LAB_01DF:         ;; $01DF
	ld  bc,$000C             ;; 
	call Wait1750_X          ;; =Wait1750_X (12)

	ld  a,$14                ;;
	ld  [$C47C],a            ;; $C47C = $14
	
	ld  b,$1F                ;;
	ld  hl,$5040             ;;
	rst $10                  ;; =RST10 (31, $5040) ;; FUN_ROM31_5040 ()

	call Wait7000            ;; =Wait7000

	ld  a,$02                ;;
	ld  [$C47C],a            ;; $C47C = $02

	ld  b,$1F                ;;
	ld  hl,$5040             ;;
	rst $10                  ;; =RST10 (31, $5040) ;; FUN_ROM31_5040 ()

	call Wait7000            ;; =Wait7000

	ld  a,$03                ;;
	ld  [$C47C],a            ;; $C47C = $03

	ld  b,$1F                ;;
	ld  hl,$5040             ;;
	rst $10                  ;; =RST10 (31, $5040) ;; FUN_ROM31_5040 ()

	call Wait7000            ;; =Wait7000

	ld  a,$04                ;;
	ld  [$C47C],a            ;; $C47C = $04

	ld  b,$1F                ;;
	ld  hl,$5040             ;;
	rst $10                  ;; =RST10 (31, $5040) ;; FUN_ROM31_5040 ()

	call Wait7000            ;; =Wait7000

	ld  a,$05                ;;
	ld  [$C47C],a            ;; $C47C = $05

	ld  b,$1F                ;;
	ld  hl,$5040             ;;
	rst $10                  ;; =RST10 (31, $5040) ;; FUN_ROM31_5040 ()

	call Wait7000            ;; =Wait7000

	ld  a,$06                ;;
	ld  [$C47C],a            ;; $C47C = $06

	ld  b,$1F                ;;
	ld  hl,$5040             ;;
	rst $10                  ;; =RST10 (31, $5040) ;; FUN_ROM31_5040 ()

	call Wait7000            ;; =Wait7000

	ld  a,$07                ;;
	ld  [$C47C],a            ;; $C47C = $07

	ld  b,$1F                ;;
	ld  hl,$5040             ;;
	rst $10                  ;; =RST10 (31, $5040) ;; FUN_ROM31_5040 ()

	call Wait7000            ;; =Wait7000

	ld  a,$08                ;;
	ld  [$C47C],a            ;; $C47C = $08

	ld  b,$1F                ;;
	ld  hl,$5040             ;;
	rst $10                  ;; =RST10 (31, $5040) ;; FUN_ROM31_5040 ()

	call Wait7000            ;; =Wait7000

	ld  a,$09                ;;
	ld  [$C47C],a            ;; $C47C = $09

	ld  b,$1F                ;;
	ld  hl,$5040             ;;
	rst $10                  ;; =RST10 (31, $5040) ;; FUN_ROM31_5040 ()

	call Wait7000            ;; =Wait7000

	ld  a,$0C
	ld  bc,$0800
	ld  e,$6C
	ld  d,$44
	ld  h,$17
	call FUN_0705            ;;FUN_0705 (A: value, BC: counter, DE: ptr, H: bank)

	call Wait7000

	ld  a,$0D
	ld  e,$8C
	ld  d,$44
	ld  b,$17
	call FUN_06A8

	call Wait7000

	ld  a,$12                ;;
	ld  [$C47C],a            ;; $C47C = $12

	ld  b,$1F                ;;
	ld  hl,$5040             ;;
	rst $10                  ;; =RST10 (31, $5040) ;; FUN_ROM31_5040 ()

	call Wait7000            ;; =Wait7000

	ld  a,$0A                ;;
	ld  [$C47C],a            ;; $C47C = $0A

	ld  b,$1F                ;;
	ld  hl,$5040             ;;
	rst $10                  ;; =RST10 (31, $5040) ;; FUN_ROM31_5040 ()

	call Wait7000            ;; =Wait7000

	ld  a,$13                ;;
	ld  [$C47C],a            ;; $C47C = $13

	ld  b,$1F                ;;
	ld  hl,$5040             ;;
	rst $10                  ;; =RST10 (31, $5040) ;; FUN_ROM31_5040 ()

	call Wait7000            ;; =Wait7000

	ld  a,$0E                ;;
	ld  [$C47C],a            ;; $C47C = $0E

	ld  b,$1F                ;;
	ld  hl,$5040             ;;
	rst $10                  ;; =RST10 (31, $5040) ;; FUN_ROM31_5040 ()

	call Wait7000            ;; =Wait7000

	ld  a,$01                ;;
	ld  [$C524],a            ;;
	ld  a,$FF                ;;
	ld  [$C523],a            ;;
	xor a                    ;;
	ld  [$C51F],a            ;;
	ld  [$C520],a            ;;
	
	ld  hl,$41CF             ;;
	ld  b,$17                ;;
	rst $10                  ;; =RST10 (23, $41CF) ;; FUN_ROM23_41CF ()

.LAB_02D1:         ;; $02D1
	ei

.main_loop:        ;; $02D2
	call VRAMClear

	call FUN_0BA7

	call FUN_0B7F

	call FUN_0B9B

	call FUN_0DCA

	xor a
	ld  [$C586],a
	ld  [$C52B],a
	ld  [$C52F],a
	ld  [$C530],a
	Call FUN_0355

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
	ldh [$ff00+$B9], a
	ld  a,$80
	ldh [$ff00+$BA], a
	xor a
	ld  [$C58D],a
	ld  [$C58E],a
	ld  hl,$C604
	ld  [hl+], a
	ld  [hl+], a
	ld  [hl+], a
	ld  [hl], a

.loop:             ;; $0324
	ld  a,[$C58A]
	or  a
	call z,FUN_095B

	halt
	
	ld  a,[$C5DF]
	or  a
	jr  z,.loop

	ld  a,[$C56C]
	or  a
	jr  z,.break

	bit 7,a
	jr  z,.loop

.break:            ;; $033D
	di

	call SetInterrupts

	call Wait7000

	ld  a,$00                ;;
	ld  [$C47C],a            ;; $C47C = $00

	ld  b,$1F                ;;
	ld  hl,$5040             ;;
	rst $10                  ;; =RST10 (31, $5040) ;; FUN_ROM23_5040 ()

	call Wait7000            ;; =Wait7000

	jp  .main_loop


;---------------------------------- TODO:

SECTION "03A4", ROM0[$03A4]
FUN_03A4:
	ret

SECTION "06A8", ROM0[$06A8]
FUN_06A8:
	ret
	
SECTION "095B", ROM0[$095B]
FUN_095B:
	ret
	
SECTION "0B7F", ROM0[$0B7F]
FUN_0B7F:
	ret

SECTION "0B9B", ROM0[$0B9B]
FUN_0B9B:
	ret

SECTION "0DCA", ROM0[$0DCA]
FUN_0DCA:
	ret

SECTION "255B", ROM0[$255B]
FUN_255B:
	ret

SECTION "256A", ROM0[$256A]
FUN_256A:
	ret



INCLUDE "src/Bank0/FUN_0355.inc"             ;; ROM0[$0355]

INCLUDE "src/Bank0/Wait7000.inc"             ;; ROM0[$05D1]
INCLUDE "src/Bank0/FUN_05E2.inc"             ;; ROM0[$05E2]
;INCLUDE "src/Bank0/FUN_0646.inc"             ;; ROM0[$0646]
INCLUDE "src/Bank0/Wait1750_X.inc"           ;; ROM0[$0692]
;INCLUDE "src/Bank0/FUN_06A8.inc"             ;; ROM0[$06A8]
INCLUDE "src/Bank0/FUN_0705.inc"             ;; ROM0[$0705]
;INCLUDE "src/Bank0/FUN_076B.inc"             ;; ROM0[$076B]
INCLUDE "src/Bank0/InterruptLCD.inc"         ;; ROM0[$078D]
;INCLUDE "src/Bank0/FUN_07E0.inc"             ;; ROM0[$07E0]
;INCLUDE "src/Bank0/FUN_07F1.inc"             ;; ROM0[$07F1]
;INCLUDE "src/Bank0/FUN_07FD.inc"             ;; ROM0[$07FD]
;INCLUDE "src/Bank0/FUN_0829.inc"             ;; ROM0[$0829]
;INCLUDE "src/Bank0/FUN_085C.inc"             ;; ROM0[$085C]
;INCLUDE "src/Bank0/FUN_0897.inc"             ;; ROM0[$0897]

INCLUDE "src/Bank0/MemInitial.inc"           ;; ROM0[$08D0]
INCLUDE "src/Bank0/VRAMClear.inc"            ;; ROM0[$0930]
INCLUDE "src/Bank0/Memset.inc"               ;; ROM0[$0949]
;INCLUDE "src/Bank0/FUN_095B.inc"             ;; ROM0[$095B]
;INCLUDE "src/Bank0/FUN_09F3.inc"             ;; ROM0[$09F3]
;INCLUDE "src/Bank0/FUN_0A17.inc"             ;; ROM0[$0A17]
;INCLUDE "src/Bank0/FUN_0A61.inc"             ;; ROM0[$0A61]

INCLUDE "src/Bank0/FUN_0BA7.inc"             ;; ROM0[$0BA7]

INCLUDE "src/Bank0/CopyData.inc"             ;; ROM0[$1679]

INCLUDE "src/Bank0/FUN_3290.inc"             ;; ROM0[$3290]


INCLUDE "src/Bank2/FUN_42FA.inc"             ;; ROMX[$3290], BANK[2]


INCLUDE "src/Bank31/FUN_5040.inc"            ;; ROMX[$5040], BANK[31]



SECTION "End", ROMX[$7FFF], BANK[255]
	db  $00