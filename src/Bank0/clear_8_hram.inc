
SECTION "clear_8_hram", ROM0[$0B9B]

;; Clears [UNK_FFA1]-[UNK_FFA8] of high RAM
clear_8_hram: ;;0B9B
	xor a
	ld  hl,UNK_FFA1
	call clear_4_hram

;; clear_4_hram(A: val, HL: ptr)
clear_4_hram: ;;0BA2
	ld  [hl+],a
	ld  [hl+],a
	ld  [hl+],a
	ld  [hl+],a
	ret