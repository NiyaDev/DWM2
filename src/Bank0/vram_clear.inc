
SECTION "vram_clear", ROM0[$0930]

;; If UNK_2 equals 0  ;  Clears memory at $9800-$9FFF [VRAM]
;; else               ;  Sets memory at $9800-$9BFF [VRAM] to $C3
vram_clear:
	ld  hl,_SCRN0
	ld  bc,$0800
	
	;; if UNK_2 is 0, skip
	ld  a,[UNK_D066]
	or  a
	jr  z,.skip

	;; Set UNK_2 to 0
	xor a
	ld  [UNK_D066],a

	ld  bc,$0400
	ld  a,$C3

.skip:
	call memset
	ret