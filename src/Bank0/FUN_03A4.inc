
SECTION "FUN_03A4", ROM0[$03A4]


;; FUN_03A4 ()
FUN_03A4:          ;; $03A4
	push af
	push bc
	push de
	push hl

	ldh a,[rSVBK]
	ld  b,a
	ld  a,$00
	ldh [rSVBK],a

	push bc

	ldh  a,[rVBK]

	push af

	ld  hl,$C5ED
	bit 0,[hl]
	jp  nz,.LAB_046B

	set 0,[hl]

	call DMATransfer

	ld  a,[IsGBC]
	or  a
	jr  z,.LAB_03EA

	ld  a,[$C56C]
	or  a
	jr  nz,.LAB_03EA

	ld  hl,$C526
	ld  a,[hl]
	inc hl
	or  [hl]
	jr  z,.LAB_03EA

	ld  a,[$C526]
	or  a
	call nz,FUN_0829

	xor a
	ld  [$C526],a
	ld  a,[$C527]
	or  a
	call nz,FUN_085C

	xor a
	ld  [$C527],a

.LAB_03EA:
	call FUN_0BCC
	call FUN_07FD
	call FUN_07E0
	call FUN_04ED
	call FUN_07F1

	ld  a,[$C58A]
	and a
	jr  nz,.LAB_042E

	ei

	call FUN_0A17
	call FUN_0A8D
	call FUN_33E8
	call FUN_09F3
	call FUN_131A
	call FUN_0474

	ld  a,[$C52B]
	or  a
	call nz,FUN_2620

	call FUN_0F4E

	ld  a,[$C5F0]
	add 1
	ld  [$C5F0],a
	ld  a,[$C5F1]
	adc 0
	ld  [$C5F1],a
	jr  .LAB_043A

.LAB_042E:
	call FUN_33E8

	ei

	call FUN_131A
	call FUN_0474

	jr  .LAB_043A

.LAB_043A:
	ld  a,[$C56C]
	or  a
	jr  nz,.LAB_0456

	ld  a,[$C55E]
	and $0F
	cp  $0F
	jr  nz,.LAB_0450

	ld  a,[$C58A]
	or  a
	jp  z,Start.initialize

.LAB_0450:
	ld  a,[$C58A]
	or  a
	jr  nz,.LAB_0456

.LAB_0456:
	ld  hl,$C5ED
	res 0,[hl]

.LAB_045B:
	pop af

	ldh [rVBK],a
	ldh a,[rLY]

	ld  [$C5D7],a

	pop af

	ldh [rSVBK],a

	pop hl
	pop de
	pop bc
	pop af
	reti

.LAB_046B:
	call FUN_07F1
	call FUN_33E8

	ei

	jr  .LAB_045B