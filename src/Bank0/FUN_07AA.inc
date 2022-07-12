
SECTION "FUN_07AA", ROM0[$07AA]


;;
FUN_07AA:          ;;07AA
	ld  hl,$C5EC
	set 7,[hl]
	ld  a,[hl]
	ldh [rLCDC],a

	ld  a,[$C524]
	or  a
	ret z

	ld  a,$01
	ld  [$C47C],a
	
	ld  b,$1F
	ld  hl,$5040
	rst $10

	call wait_7000

	ret