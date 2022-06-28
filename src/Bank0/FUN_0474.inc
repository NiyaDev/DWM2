
SECTION "0474", ROM0[$0474]


;;
FUN_0474:
	xor a
	ldh [$FFB1],a

	call FUN_252D

	call FUN_048A

	ld  a,[$C56C]
	or  a
	jr  z,.skip

	bit 7,a
	ret z

.skip:
	call FUN_0BB4

	ret