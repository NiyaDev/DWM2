
SECTION "09F3", ROM0[$09F3]

;; Loads a couple values, shifts them around and does a little mat, then saves them
FUN_09F3: ;;09F3
	push hl
	push bc

	ld  a,[UNK_CD03]
	ld  l,a

	ld  a,[UNK_CD04]
	ld  h,a

	;; Save HL
	ld  c,l
	ld  b,h

	;; Shift L left twice and move carry into H
	sla l
	rl  h
	sla l
	rl  h

	;; Add new and old values
	add hl,bc

	;; Add $0B to L
	ld  a,$0B
	add l

	;; Save [UNK_CD03]
	ld  [UNK_CD03],a

	;; Save [UNK_CD04]
	ld  a,h
	adc 0
	ld  [UNK_CD04],a

	pop bc
	pop hl
	ret