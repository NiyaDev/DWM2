
SECTION "04ED", ROM0[$04ED]


;;
FUN_04ED:
	ld  hl,$C604
	ld  b,[hl]
	inc hl
	or a, [hl]
	ret z

	ld  a,[$C604]
	or  a
	jr  z,.LAB_0511

	dec a
	ld  [$C604],a
	
	ldh a,[rSCY]
	ld  b,a
	ld  a,[$C604]
	add a
	ld  c,a
	and $07
	bit 3,c
	jr  nz,.LAB_050E

	xor $07

.LAB_050E:
	add b
	ldh  [rSCY],a

.LAB_0511:
	ld  a,[$C605]
	or  a
	jr  z,.LAB_0530

	dec a
	ld  [$C605],a
	ldh a,[rSCX]
	ld  b,a
	ld  a,[$C605]
	add a
	ld  c,a
	and $07
	bit 3,c
	jr  nz,.LAB_052B

	xor $07

.LAB_052B:
	sub $04
	add b
	ldh [rSCX],a

.LAB_0530:
	ret