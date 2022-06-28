
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


	dw .LAB_2582, .LAB_2589, .LAB_258B, .LAB_25AA


.LAB_2582:
	pop af
	ldh [rSVBK],a

	pop de
	pop hl
	pop af
	reti 

.LAB_2589:
	jr .LAB_2582

.LAB_258B:
	ldh  a,[rLY]

	ld  hl,$C0F0
	add l
	ld  l,a
	jr  nc,.LAB_2595

	inc h

.LAB_2595:
	ld  a,[hl]
	ldh [rSCX],a

	ldh a,[rLYC]
	add 2
	cp  $90
	jr  c,.LAB_25A6

	ldh a,[$FFA1]
	ldh [rSCX],a

	ld  a,0

.LAB_25A6:
	ldh [rLYC],a
	jr  .LAB_2582

	
.LAB_25AA:
	ldh a,[rLY]
	ld  hl,$C0F0
	add l
	ld  l,a
	jr  nc,.LAB_25B4

	inc h

.LAB_25B4:
	ld  a,[hl]
	ldh [rSCY],a

	ldh a,[rLYC]
	add 2
	cp  $81
	jr  c,.LAB_25C5

	ldh a,[$FFA5]
	ldh [rSCY],a

	ld  a,0

.LAB_25C5
	ldh [rLYC],a

	jr  .LAB_2582