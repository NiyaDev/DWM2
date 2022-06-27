
SECTION "255B", ROM0[$255B]


;;
FUN_255B:
	push af
	push bc
	push de
	push hl

	ld  hl,$4001
	ld  b,27
	rst $10

	pop hl
	pop de
	pop bc
	pop af

	reti