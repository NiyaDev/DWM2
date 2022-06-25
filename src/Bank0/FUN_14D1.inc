
SECTION "FUN_14D1", ROM0[$14D1]


;;
FUN_14D1:          ;;14D1
	ld  a,[$C58A]
	or  a
	jp  z,.LAB_1575

	ld  a,$08
	call set_enabled_interrupts

	ld  a,[$C580]
	set 7,a
	res 6,a
	ld  [$C57F],a

	ld  a,[$C57F]
	bit 1,a
	jr  nz,.LAB_14F6
	ld  hl,$6000

.LAB_14F1:
	dec hl
	ld  a,h
	or  l
	jr  nz,.LAB_14F1

.LAB_14F6:
	ei

	ld  a,[$C581]
	cp  $05
	jr  nz,.LAB_150D

	call FUN_15C2

	call FUN_07D1

	ldh a,[rSB]
	cp  $F5
	call nz,FUN_15C2

	jr  .LAB_1558

.LAB_150D:
	call FUN_1583

	cp  $02
	jr  z,.LAB_1517

	call FUN_07D1

.LAB_1517:
	ldh  a,[rSB]
	cp  $70
	jr  z,.LAB_1524

	cp  $71
	jr  z,.LAB_1524

	call FUN_1583

.LAB_1524:
	ld  b,a
	ld  a,[$C581]
	cp  $05
	jr  z,.LAB_1558

	ld  a,[$C57F]
	bit 1,a
	jr  nz,.LAB_1545

	ld  a,[IsGBC]
	and a
	jr  nz,.LAB_1558

	ld  a,b
	bit 0,a
	jr  z,.LAB_1558

	ld  a,[$C57F]
	set 1,a
	jr  .LAB_1555

.LAB_1545:
	ld  a,[IsGBC]
	and a
	jr  z,.LAB_1558

	ld  a,b
	bit 0,a
	jr  nz,.LAB_1558

	ld  a,[$C57F]
	res 1,a

.LAB_1555:
	ld  [$C57F],a

.LAB_1558:
	di
	ld  a,[$C580]
	res 7,a
	ld  [$C580],a

	ld  a,[$C580]
	res 0,a
	res 1,a
	ld  [$C580],a

	ld  a,[$C57F]
	bit 1,a
	ld  a,$F8
	call nz,FUN_08BA

.LAB_1575:
	xor a
	ld  [$C582],a

	ld  hl,$C55E
	ld  b,$0E

.LAB_157E:
	ld  [hl+],a
	dec b
	jr  nz,.LAB_157E
	ret