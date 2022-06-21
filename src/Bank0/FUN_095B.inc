
SECTION "FUN_095B", ROM0[$095B]


;;
FUN_095B:          ;;095B
	push hl

	ld  a,[$C5E8]
	inc a
	and $7F
	ld  [$C5E8],a
	ld  hl,$0973
	add l
	ld  l,a

	jr  nc,.no_inc
	inc h

.no_inc:           ;;096A
	ld  a,[hl]
	ld  [$C5E7],a

	pop hl
	ret