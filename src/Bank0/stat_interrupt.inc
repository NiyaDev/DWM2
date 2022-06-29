
SECTION "stat_interrupt", ROM0[$256A]


;;
stat_interrupt:     ;;256A
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


	dw .exit, .second_exit, .intx_start, .inty_start


.exit:             ;;2582
	pop af
	ldh [rSVBK],a

	pop de
	pop hl
	pop af
	reti 

.second_exit:      ;;2589
	jr .exit

.intx_start:       ;;258B
	ldh  a,[rLY]

	ld  hl,$C0F0
	add l
	ld  l,a
	jr  nc,.intx_skip_inc

	inc h

.intx_skip_inc:    ;;2595
	ld  a,[hl]
	ldh [rSCX],a

	ldh a,[rLYC]
	add 2
	cp  $90
	jr  c,.intx_leave

	ldh a,[$FFA1]
	ldh [rSCX],a

	ld  a,0

.intx_leave:       ;;25A6
	ldh [rLYC],a
	jr  .exit

	
.inty_start:       ;;25AA
	ldh a,[rLY]
	ld  hl,$C0F0
	add l
	ld  l,a
	jr  nc,.inty_skip_inc

	inc h

.inty_skip_inc:    ;;25B4
	ld  a,[hl]
	ldh [rSCY],a

	ldh a,[rLYC]
	add 2
	cp  $81
	jr  c,.inty_leave

	ldh a,[$FFA5]
	ldh [rSCY],a

	ld  a,0

.inty_leave        ;;25C5
	ldh [rLYC],a

	jr  .exit