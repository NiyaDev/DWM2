
SECTION "FUN_3290", ROM0[$3290]

;; Reset audio?
FUN_3290: ;;3290
	ld  bc,$0000
	call FUN_32DB

	;; Preparing audio
	;; Turns on all channels
	ld  a,%10000000
	ldh [rNR52],a

	;; Clears sound output terminal
	xor a
	ldh [rNR51],a
	ld  [UNK_DD09],a

	;; Maxes volume while turning off output
	ld  a,%01110111
	ldh [rNR50],a

	;; Sets first every 16 words to $FFFF from $DC00-$DCAA
	;; [$DC00], [$DC22], [$DC44], [$DC66], [$DC88], and [$DCAA]
	ld  hl,$DC00
	ld  de,$0020
	ld  b,$06
	ld  a,$FF
.loop1: ;;32AE
	ld  [hl+],a
	ld  [hl+],a
	add hl,de
	dec b
	jr  nz,.loop1

	;; Sets the memory from $DCC0-$DD08 to 0
	ld  hl,$DCC0
	ld  b,$48
	xor a
.loop2: ;;32BA
	ld  [hl+],a
	dec b
	jr  nz,.loop2

	;; Sets two variables to $00
	xor a
	ld  [$DD15],a
	ld  [$DD19],a
	ret



;---------------------------------- TODO:

SECTION "FUN_32C6", ROM0[$32C6]

;; Sets a variable to $00 then sets another to a seperate variable
;; NOTE: This function hasn't been called
;;       It was found by disassembling between functions
FUN_32C6: ;;32C6
	xor a
	ld  [$DD15],a
	ld  a,[$DD16]
	ld  [$DD09],a
	ret
;---------------------------------- TODO:

SECTION "FUN_32D1", ROM0[$32D1]

;; Sets one variable to $04 and another to $00
;; NOTE: This function hasn't been called
;;       It was found by disassembling between functions
FUN_32D1: ;;2D1
	ld  a,$04
	ld  [$DD15],a
	xor a
	ld  [$DD09],a
	ret
;---------------------------------- TODO:


SECTION "FUN_32DB", ROM0[$32DB]

; Sets [$DD12] to input B, [$DD13] to input C, and [$DD14] to 0.
FUN_32DB: ;;32DB
	ld  a,b
	ld  [UNK_DD12],a

	ld  a,c
	ld  [UNK_DD13],a

	xor a
	ld  [UNK_DD14],a
	ret