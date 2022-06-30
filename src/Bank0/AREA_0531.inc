
SECTION "AREA_0531", ROM0[$0531]
;; None of this has ever been called so far.


;; 
FUN_0531:
	call FUN_0BCC
	ret

;;
FUN_0535:
	ld  a,[$C58A]
	or  a
	ret z

	ld  a,[$C58D]
	add $01
	ld  [$C58D],a

	ld  a,[$C58E]
	adc $00
	ld  [$C58E],a
	or  a
	jp  nz,Start.initialize

	ld  a,[$C57F]
	bit 1,a
	ret nz

	ld  a,[$C581]
	cp  $05
	jr  nz,.LAB_0563

	ld  a,[$C5ED]
	bit 1,a
	ret nz
	jr  .LAB_057C


.LAB_0563:
	ld  a,[$C5ED]
	bit 1,a
	jr  nz,.LAB_0574

	bit 2,a
	jr  nz,.LAB_0574

	bit 7,a
	jr  nz,.LAB_0574

	jr  .LAB_057C


.LAB_0574:
	xor a
	ld  [$C56A],a
	ld  [$C56B],a
	ret


.LAB_057C:
	ld  a,[$C55E]
	ld  [$C56A],a

	ld  a,[$C55F]
	ld  [$C56B],a

	call FUN_0A17

	ld  a,[$C594]
	cp  $FF
	jr  z,.LAB_059D

	ld  a,0
	ld  [$C582],a

	ld  a,[$C594]
	jp  FUN_08AD


.LAB_059D:
	ld  hl,$C592
	ld  a,[hl+]
	or  [hl]
	jr  z,.LAB_05C7

	ld  a,[$C595]
	ld  l,a
	ld  a,[$C596]
	ld  h,a

	push hl

	ld  a,[$C595]
	add $01
	ld  [$C595],a

	ld  a,[$C596]
	adc 0
	ld  [$C596],a

	pop hl

	ld  a,0
	ld  [$C582],a

	ld  a,[hl]
	jp  FUN_08AD


.LAB_05C7:
	ld  a,0
	ld  [$C582],a

	ld  a,$F0
	jp  FUN_08AD