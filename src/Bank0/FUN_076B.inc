	
SECTION "FUN_076B", ROM0[$076B]


;; 
FUN_076B:          ;;076B
	push hl
	push bc

	xor a
	ld  hl,$C47F
	ld  c,$10

.LAB_0773:
	ld  [hl+],a
	dec c
	jr  nz,.LAB_0773

	pop bc
	pop hl

	ret