
SECTION "06A8", ROM0[$06A8]

;; 
;; Input: A
FUN_06A8: ;;06A8
	ld  [UNK_C47C],a

	;; If [$C524] == false, return
	ld  a,[$C524]
	or  a
	ret z

	push bc

	;; Disable LCD and clear 8 bytes of hram
	call disable_lcd
	call clear_8_hram

	;; Set scrolling to 0
	xor a
	ldh [rSCX],a
	ldh [rSCY],a

	;; Clear memory [$8800]->[$9800]
	push de
	ld  hl,$8800
	ld  bc,$1000
	xor a
	call memset
	pop de

	;; Set [rBGP] to $E4
	ld  a,$E4
	ldh  [rBGP],a

	pop bc

	ld  hl,$8800
	call FUN_0C5A

	;; Sets 20 bytes every 32 bytes to $80-$94, 13 times
	;; [$9800]->[$99A0] VRAM
	;; TODO: look into what different parts of VRAM do
	ld  hl,$9800
	ld  de,$000C
	ld  a,$80
	ld  c,$0D
.LAB_06DD:
	ld  b,$14
.LAB_06DF:
	ld  [hl+],a
	inc a
	dec b
	jr  nz,.LAB_06DF

	add hl,de
	dec c
	jr  nz,.LAB_06DD

	;; [rLCDC] and [UNK_C5EC] = $81
	ld  a,$81
	ldh [rLCDC],a
	ld  [UNK_C5EC],a

	;; Wait 5 times (~.075 seconds)
	ld  bc,$0005
	call wait_1750_x

	;; Long call FUN_ROM31_5040
	ld  hl,$5040
	ld  b,31
	rst $10

	;; Wait 6 times (~.09 seconds)
	ld  bc,$0006
	call wait_1750_x

	call disable_lcd

	ret