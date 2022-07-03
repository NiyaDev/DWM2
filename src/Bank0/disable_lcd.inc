
SECTION "disable_lcd", ROM0[$0796]

;; Wait until VBlank and then turns off LCD
disable_lcd:
	;; if LCD operation == false, return
	ld  hl,rLCDC
	bit 7,[hl]
	ret z

.wait:
	;; Waits until vblank
	ldh a,[rLY]
	cp  $91
	jr  nz,.wait

	;; Turn off screen
	res 7,[hl]

	;; Reset bit 7 of $C5EC (Unknown variable)
	ld  hl,UNK_C5EC
	res 7,[hl]
	ret