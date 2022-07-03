
SECTION "RST00", ROM0[$0000]

;; Copies a pointer located at the return address + A*2.
;; Then it jumps to it.
RST00:
	;; Grabs return address and saves DE
	pop hl
	push de

	;; Copies A into DE and doubles it
	ld  e,a
	ld  d,$00
	sla e
	rl  d

	;; Adds to return address and grabs DE
	add hl,de
	pop de

	;; Grabs pointer at HL and jumps to it
	ld  a,[hl+]
	ld  h,[hl]
	ld  l,a



SECTION "hl_jump", ROM0[$000E]

;; Jumps to HL
hl_jump:
	jp  hl
	nop



SECTION "RST10", ROM0[$0010]

;; Loads the RAM bank specified in B, then calls function in HL
RST10:
	;; Pushes the number of the current ROM bank
	ld  a,[$4000]
	push af

	;; Sets the lower 8-bits of ROM bank to B
	ld  a,b
	ld  [rROMB0],a

	;; Calls [HL] as a function so the return address is here
	call hl_jump

	;; Resets the ROM bank to the original
	pop af
	ld [$2100],a
	ret



SECTION "RST30", ROM0[$0030]
	ret
SECTION "RST38", ROM0[$0038]
	ret