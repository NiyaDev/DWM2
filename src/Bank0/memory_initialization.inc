
SECTION "memory_initialization", ROM0[$08D0]

;; Clears out Most of RAM, HRAM and banks 0 and 2 of SRAM
memory_initialization:
	;; Skip if DMG
	ld  a,[IsGBC]
	or  a
	jr  z,.Skip

	;; Clear GBC variables
	xor a
	ldh [rVBK],a
	ldh [rSVBK],a
	ldh [rHDMA1],a
	ldh [rHDMA2],a
	ldh [rHDMA3],a
	ldh [rHDMA4],a
	ldh [rHDMA5],a
	ldh [rBCPS],a
	ldh [rOCPS],a
	ld  a,[IsGBC]

.Skip:
	push af

	;; Clears memory at $C000-$DE00 [RAM]
	ld  hl,_RAM
	ld  bc,$1E00
	ld  a,0
	call memset

	;; Clears memory at $FF8A-$FFFE [HRAM]
	ld  hl,_HRAMP
	ld  bc,$0074
	ld  a,0
	call memset

	pop af
	ld  [IsGBC],a

	;; Enables writing to Cart RAM
	ld  a,CART_SRAM_ENABLE
	ld  [rRAMG],a

	;; Selects cart RAM bank 2
	ld  a,2
	ld  [rRAMB],a

	;; Clears memory at $A000-$DFFF [SRAM bank 2]
	xor a
	ld  hl,_SRAM
	ld  bc,$2000
	call memset

	;; Selects Cart RAM bank 0
	ld  a,0
	ld  [rRAMB],a

	;; Clears memory at $A000-$DFFF [SRAM bank 0]
	xor a
	ld  hl,_SRAM
	ld  bc,$2000
	call memset

	;; Disable writing to Cart RAM
	ld  a,CART_SRAM_DISABLE
	ld  [rRAMG],a
	ret