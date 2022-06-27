
SECTION "256A", ROM0[$256A]


;;
FUN_256A:
	push af
	push hl
	push de

	ldh a,[rSVBK]
	ld  d,a

	xor a
	ldh [rSVBK],a

	push de

	ld  a,[$C5E1]
	and $03
	rst $00

	;; If A=0
	add d
	dec h
	;; If A=1
	adc c
	dec h
	;; If A=2
	adc e
	dec h
	;; If A=3
	xor d
	dec h

	pop af

	ldh [rSVBK],a

	pop de
	pop hl
	pop af

	reti