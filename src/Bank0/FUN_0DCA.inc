
SECTION "FUN_0DCA", ROM0[$0DCA]


;; 
FUN_0DCA:          ;;0DCA
	ld  hl,$C56F
	ld  a,[$C5E9]
	ld  [hl+],a
	ld  a,[$C5EA]
	ld  [hl+],a
	ld  a,[$C5EB]
	ld  [hl],a
	jr  .useless_jump

.useless_jump:     ;;0DDB
	xor a
	ld  hl,$C572
	ld  [hl+],a
	ld  [hl+],a
	ld  [hl+],a
	ld  [hl+],a
	ld  [hl],a

	ld  [$C56C],a
	ld  a,$07
	ld  [$C56D],a
	ld  a,$1F
	ld  [$C56E],a
	ret