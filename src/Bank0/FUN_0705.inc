
SECTION "FUN_0705", ROM0[$0705]

;; Seems to do the same thing as FUN_06A8, but with bank switching involved
;; Input: A, BC, DE, H
FUN_0705:
	ld  [UNK_C47C],a

	;; if [UNK_C524 == 0, return
	ld  a,[UNK_C524]
	or  a
	ret z

	push hl
	push bc

	call disable_lcd
	call clear_8_hram

	;; Set scrolling to 0
	xor a
	ldh [rSCX],a
	ldh [rSCY],a

	;; Set [rBGP] to $E4
	ld  a,$E4
	ldh [rBGP],a

	pop bc
	pop hl

	;; Save current bank
	;; usually uses $4100, for some reson this one doesn't
	ld  a,[$4000]
	push af

	;; Sets bank to input:H
	push bc
	ld  a,h
	ld  [rROMB0],a
	pop bc

	;; Copies [DE] into [HL] input:BC times
	ld  hl,$8800
.LAB_072D:
	ld  a,[de]
	ld  [hl+],a
	inc de
	dec bc
	ld  a,b
	or  c
	jr  nz,.LAB_072D

	;; Sets 20 bytes every 32 bytes to $80-$94, 13 times
	;; [$9800]->[$99A0] VRAM
	ld  hl,$9800
	ld  de,$000C
	ld  a,$80
	ld  c,$0D
.LAB_073F:
	ld  b,$14
.LAB_0741:
	ld  [hl+],a
	inc a
	dec b
	jr  nz,.LAB_0741

	add hl,de
	dec c
	jr  nz,.LAB_073F

	;; [rLCDC] and [UNK_C5EC] = $81
	ld  a,$81
	ldh [rLCDC],a
	ld  [UNK_C5EC],a
	
	;; Wait 5 times (~.075 seconds)
	ld  bc,5
	call wait_1750_x
	
	;; Long call FUN_ROM31_5040
	ld  hl,$5040
	ld  b,31
	rst $10

	;; Wait 6 times (~.09 seconds)
	ld  bc,6
	call wait_1750_x

	call disable_lcd

	;; Sets bank back to start
	pop af
	ld  [rROMB0],a
	ret

