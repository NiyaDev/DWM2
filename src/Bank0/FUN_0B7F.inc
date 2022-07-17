	
SECTION "FUN_0B7F", ROM0[$0B7F]

;; Sets three bytes in seperate locations to $D2,$D2,$E2
;; Seems to be RAM storage for palette data for background, and both objects
FUN_0B7F: ;;0B7F
	ld  hl,UNK_C5E9
	ld  a,$D2
	ld  [hl+],a

	ld  a,$D2
	ld  [hl+],a

	ld  a,$E2
	ld  [hl],a

	ld  hl,$D040
	ld  a,[UNK_C5E9]
	ld  [hl+],a

	ld  a,[UNK_C5EA]
	ld  [hl+],a

	ld  a,[UNK_C5EB]
	ld  [hl],a
	ret