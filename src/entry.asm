

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
	ld  [hl],a               ;; Clears memory $C5DB-$C5DF
	ld  a,$05                ;;
	ld  [$C5DB],a            ;; [$C5DB] = $05

	ld  a,$00                ;;
	ld  [$4100],a            ;; Selects cart RAM bank 0
	ld  a,$00                ;;
	ld  [$0100],a            ;; Disables writing to Cart RAM 
	ld  a,$01                ;;                                           ;;
	ld  [$2100],a            ;; Lower 8-bits of ROM banks set to 0x01     ;; ROM Bank 1
	ld  a,$00                ;;                                           ;;  selected
	ld  [$3100],a            ;; Upper 1-bit  of ROM banks set to 0x00     ;;

	ld  a,$01                ;; 
	ld  [$C524],a            ;; [$C524] = $01
	ld  a,$FF                ;; 
	ld  [$C60A],a            ;; 
	ld  [$C60B],a            ;; [$C60A-$C60B] = $FF

	call Unknown1            ;; =Unknown1() ;; Audio prep?

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
	rst $10                  ;; =RST10 (2, $42FA) ;; Call Unknown3

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
	rst $10                  ;; =RST10 (31, $5040)

	call Wait7000            ;; =Wait7000

	ld  a,$02                ;;
	ld  [$C47C],a            ;; $C47C = $02

	ld  b,$1F                ;;
	ld  hl,$5040             ;;
	rst $10                  ;; =RST10 (31, $5040)

	call Wait7000            ;; =Wait7000

	ld  a,$03                ;;
	ld  [$C47C],a            ;; $C47C = $03

	ld  b,$1F                ;;
	ld  hl,$5040             ;;
	rst $10                  ;; =RST10 (31, $5040)

	call Wait7000            ;; =Wait7000

	ld  a,$04                ;;
	ld  [$C47C],a            ;; $C47C = $04

	ld  b,$1F                ;;
	ld  hl,$5040             ;;
	rst $10                  ;; =RST10 (31, $5040)

	call Wait7000            ;; =Wait7000

	ld  a,$05                ;;
	ld  [$C47C],a            ;; $C47C = $05

	ld  b,$1F                ;;
	ld  hl,$5040             ;;
	rst $10                  ;; =RST10 (31, $5040)

	call Wait7000            ;; =Wait7000

	ld  a,$06                ;;
	ld  [$C47C],a            ;; $C47C = $06

	ld  b,$1F                ;;
	ld  hl,$5040             ;;
	rst $10                  ;; =RST10 (31, $5040)

	call Wait7000            ;; =Wait7000

	ld  a,$07                ;;
	ld  [$C47C],a            ;; $C47C = $07

	ld  b,$1F                ;;
	ld  hl,$5040             ;;
	rst $10                  ;; =RST10 (31, $5040)

	call Wait7000            ;; =Wait7000

	ld  a,$08                ;;
	ld  [$C47C],a            ;; $C47C = $08

	ld  b,$1F                ;;
	ld  hl,$5040             ;;
	rst $10                  ;; =RST10 (31, $5040)

	call Wait7000            ;; =Wait7000

	ld  a,$09                ;;
	ld  [$C47C],a            ;; $C47C = $09

	ld  b,$1F                ;;
	ld  hl,$5040             ;;
	rst $10                  ;; =RST10 (31, $5040)

	call Wait7000            ;; =Wait7000

	ld  a,$0C
	ld  bc,$0800
	ld  e,$6C
	ld  d,$44
	ld  h,$17
	call FUN_0705

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
	ld  hl,$5040             ;; =RST10
	rst $10                  ;;

	call Wait7000            ;; =Wait7000

	ld  a,$0A                ;;
	ld  [$C47C],a            ;; $C47C = $0A

	ld  b,$1F                ;;
	ld  hl,$5040             ;; =RST10
	rst $10                  ;;

	call Wait7000            ;; =Wait7000

	ld  a,$13                ;;
	ld  [$C47C],a            ;; $C47C = $13

	ld  b,$1F                ;;
	ld  hl,$5040             ;; =RST10
	rst $10                  ;;

	call Wait7000            ;; =Wait7000

	ld  a,$0E                ;;
	ld  [$C47C],a            ;; $C47C = $0E

	ld  b,$1F                ;;
	ld  hl,$5040             ;; =RST10
	rst $10                  ;;

	call Wait7000            ;; =Wait7000

	ld  a,$01
	ld  [$C524],a
	ld  a,$FF
	ld  [$C523],a
	xor a
	ld  [$C51F],a
	ld  [$C520],a
	
	ld  hl,$41CF
	ld  b,$17
	rst $10

.LAB_02D1:         ;; $02D1
	ei

.LAB_02D2:         ;; $02D2
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
	Call Unknown2

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

.LAB_0324:         ;; $0324
	ld  a,[$C58A]
	or  a
	call z,FUN_095B

	halt
	
	ld  a,[$C5DF]
	or  a
	jr  z,.LAB_0324

	ld  a,[$C56C]
	or  a
	jr  z,.LAB_033D

	bit 7,a
	jr  z,.LAB_0324

.LAB_033D:         ;; $033D
	di

	call SetInterrupts

	call Wait7000

	ld  a,$00                ;;
	ld  [$C47C],a            ;; $C47C = $00

	ld  b,$1F                ;;
	ld  hl,$5040             ;; =RST10
	rst $10                  ;;

	call Wait7000            ;; =Wait7000

	jp  .LAB_02D2


;---------------------------------- TODO:

SECTION "03A4", ROM0[$03A4]
FUN_03A4:
	ret

;---------------------------------- TODO:

;---------------------------------- TODO:

SECTION "05E2", ROM0[$05E2]


;; FUN_05E2 ()
FUN_05E2:          ;; $05E2
	ld  a,$0B                ;;
	ld  [$C47C],a            ;; [$C47C] = $0B

	ld  b,$1F                ;;
	ld  hl,$5040             ;;
	rst $10                  ;; =RST10 (31, $5040) ;; Call FUN_ROM31_5040

	call Wait7000            ;; =Wait7000 ()

	ldh a,[rP1]              ;;
	and $03                  ;;
	cp  $03                  ;;
	jr  nz,.leave            ;; if Left+Right / B+A are pressed, leave

	ld  a,P1F_GET_DPAD       ;;
	ldh [rP1],a              ;;

	ldh a,[rP1]              ;;
	ldh a,[rP1]              ;;

	ld  a,P1F_GET_NONE       ;;
	ldh [rP1],a              ;;

	ld  a,P1F_GET_BTN        ;;
	ldh [rP1],a              ;;

	ldh a,[rP1]              ;;
	ldh a,[rP1]              ;;
	ldh a,[rP1]              ;;
	ldh a,[rP1]              ;;
	ldh a,[rP1]              ;;
	ldh a,[rP1]              ;;

	ld  a,P1F_GET_NONE       ;;
	ldh [rP1],a              ;;

	ldh a,[rP1]              ;;
	ldh a,[rP1]              ;;
	ldh a,[rP1]              ;;

	ldh a,[rP1]              ;;
	and $03                  ;;
	cp  $03                  ;;
	jr  nz,.leave            ;; if Left+Right / B+A are pressed, leave

	ld  a,$0A                ;;
	ld  [$C47C],a            ;;

	ld  b,$1F                ;;
	ld  hl,$5040             ;;
	rst $10                  ;; =RST10 (31, $5040) ;; Call FUN_ROM31_5040

	call Wait7000            ;; =Wait7000 ()
	sub a                    ;; return 0
	ret

.leave:
	ld  a,$0A                ;;
	ld  [$C47C],a            ;;

	ld  b,$1F                ;;
	ld  hl,$5040             ;;
	rst $10                  ;; =RST10 (31, $5040) ;; Call FUN_ROM31_5040

	call Wait7000            ;; =Wait7000 ()

	scf                      ;; carry = true
	ret


;---------------------------------- TODO:

;---------------------------------- TODO:

SECTION "06A8", ROM0[$06A8]
FUN_06A8:
	ret
	
SECTION "0705", ROM0[$0705]
FUN_0705:
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

SECTION "0BA7", ROM0[$0BA7]
FUN_0BA7:
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



INCLUDE "src/Bank0/unknown/unknown2.inc"     ;; ROM0[$0355]

INCLUDE "src/Bank0/Wait7000.inc"             ;; ROM0[$05D1]

INCLUDE "src/Bank0/Wait1750_X.inc"           ;; ROM0[$0692]

INCLUDE "src/Bank0/InterruptLCD.inc"         ;; ROM0[$078D]

INCLUDE "src/Bank0/MemInitial.inc"           ;; ROM0[$08D0]
INCLUDE "src/Bank0/VRAMClear.inc"            ;; ROM0[$0930]
INCLUDE "src/Bank0/Memset.inc"               ;; ROM0[$0949]

INCLUDE "src/Bank0/CopyData.inc"             ;; ROM0[$1679]

INCLUDE "src/Bank0/unknown/unknown1.inc"     ;; ROM0[$3290]


INCLUDE "src/Bank2/unknown3.inc"       ;; ROMX[$3290], BANK[2]

;---------------------------------- TODO:

SECTION "5040", ROMX[$5040], BANK[31]


;; FUN_ROM31_5040 ()
;; 
FUN_ROM31_5040:    ;; 31,5040
	ld  a,[$C524]            ;;
	or  a                    ;;
	ret z                    ;; if [$C524] == 0, return

	ld  a,[$C47C]            ;;
	cp  $FF                  ;;
	jr  nz,.skip_1           ;; if [$C47C] != $FF, skip
	
	ld  hl,$C47F             ;;
	jr  .continue            ;;

.skip_1:           ;; 31,5051
	ld  l,a                  ;;
	ld  h,$00                ;; HL  = $00[$C47C]
	add hl,hl                ;; HL += HL
	ld  de,$5094             ;;
	add hl,de                ;; HL += $5094
	ld  e,[hl]               ;;
	inc hl                   ;; HL++
	ld  d,[hl]               ;;
	push de                  ;;
	pop hl                   ;; 

.continue:         ;; 31,505E
	ld  a,[hl]               ;;
	and $07                  ;; Take the first u8 at [hl] and check if 7
	ret z                    ;; if [HL] & 7 != 0, return

	ld  b,a                  ;;
	ld  c,$00                ;;

.loop:             ;; 31,5065
	push bc                  ;;

	ld  a,$00                ;;
	ldh [c],a                ;;
	ld  a,P1F_GET_NONE       ;;
	ldh [c],a                ;; does something with P1

	ld  b,$10                ;;

.outer_loop:       ;; 31,506E
	ld  e,$08                ;;
	ld  a,[hl+]              ;;
	ld  d,a                  ;; 

.inner_loop:       ;; 31,5072
	bit 0,d                  ;;
	ld  a,P1F_GET_BTN        ;;
	jr  nz,.skip_2           ;; if bit 0 of D != 0, skip loading A

	ld  a,P1F_GET_DPAD       ;;

.skip_2:           ;; 31,507A
	ldh [c],a                ;;
	ld  a,P1F_GET_NONE       ;;
	ldh [c],a                ;;

	rr  d                    ;; rotate right
	dec e                    ;;
	jr  nz,.inner_loop       ;; if E != 0, loop

	dec b                    ;;
	jr  nz,.outer_loop       ;; if B != 0, loop

	ld  a,P1F_GET_DPAD       ;;
	ldh [c],a                ;;
	ld  a,P1F_GET_NONE       ;;
	ldh [c],a                ;;

	pop bc                   ;;

	dec b                    ;;
	ret z                    ;; if b == 0, return

	call Wait7000            ;;

	jr .loop                 ;;


;; Pointers to the next group
SECTION "5094", ROMX[$5094], BANK[31]
		dw  $513E
		dw  $514E
		dw  $50BE
		dw  $50CE
		dw  $50DE
		dw  $50EE
		dw  $50FE
		dw  $510E
		dw  $511E
		dw  $512E
		dw  $515E
		dw  $516E
		dw  $517E
		dw  $518E
		dw  $519E
		dw  $51AE
		dw  $51BE
		dw  $51CE
		dw  $51DE
		dw  $51EE
		dw  $51FE

;; TODO: Unknown
SECTION "50BE", ROMX[$50BE], BANK[31]
		db  $79, $5D, $08, $00, $0B, $8C, $D0, $F4, $60, $00, $00, $00, $00, $00, $00, $00
		db  $79, $52, $08, $00, $0B, $A9, $E7, $9F, $01, $C0, $7E, $E8, $E8, $E8, $E8, $E0
		db  $79, $47, $08, $00, $0B, $C4, $D0, $16, $A5, $CB, $C9, $05, $D0, $10, $A2, $28
		db  $79, $3C, $08, $00, $0B, $F0, $12, $A5, $C9, $C9, $C8, $D0, $1C, $A5, $CA, $C9
		db  $79, $31, $08, $00, $0B, $0C, $A5, $CA, $C9, $7E, $D0, $06, $A5, $CB, $C9, $7E
		db  $79, $26, $08, $00, $0B, $39, $CD, $48, $0C, $D0, $34, $A5, $C9, $C9, $80, $D0
		db  $79, $1B, $08, $00, $0B, $EA, $EA, $EA, $EA, $EA, $A9, $01, $CD, $4F, $0C, $D0
		db  $79, $10, $08, $00, $0B, $4C, $20, $08, $EA, $EA, $EA, $EA, $EA, $60, $EA, $EA
		db  $B9, $01, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00
		db  $B9, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00
		db  $89, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00
		db  $89, $01, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00
		db  $59, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00
		db  $A9, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00
		db  $51, $00, $00, $01, $00, $02, $00, $03, $00, $C0, $00, $00, $00, $00, $00, $00
		db  $A1, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00
		db  $99, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00
		db  $99, $01, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00
		db  $C9, $01, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00
		db  $71, $01, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00
		db  $B9, $02, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00

SECTION "End", ROMX[$7FFF], BANK[255]
	db  $00