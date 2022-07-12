
SECTION "04ED", ROM0[$04ED]

;; TODO: figure this out
;; Input: A, [UNK_C604], [UNK_C605]
FUN_04ED: ;;04ED
	;; Return if ([UNK_C604] | [UNK_C605]) == false
	ld  hl,UNK_C604
	ld  b,[hl]
	inc hl
	or  a,[hl]
	ret z

	;; If [UNK_C604] == 0
	ld  a,[UNK_C604]
	or  a
	jr  z,.LAB_0511

	;; [UNK_C604] -= 1
	dec a
	ld  [UNK_C604],a
	
	ldh a,[rSCY]
	ld  b,a

	;; If (([UNK_C604] * 2) & $08) == true, XOR (([UNK_C604] * 2) & $07) with $07
	ld  a,[UNK_C604]
	add a
	ld  c,a
	and $07
	bit 3,c
	jr  nz,.LAB_050E

	xor $07

.LAB_050E:
	add b
	ldh  [rSCY],a

.LAB_0511:
	;; If [UNK_C605] == 0, jump
	ld  a,[UNK_C605]
	or  a
	jr  z,.LAB_0530

	;; [UNK_C605] -= 1
	dec a
	ld  [UNK_C605],a

	ldh a,[rSCX]
	ld  b,a

	;; If (([UNK_C605] * 2) & $08) == true, XOR (([UNK_C605] * 2) & $07) with $07
	ld  a,[UNK_C605]
	add a
	ld  c,a
	and $07
	bit 3,c
	jr  nz,.LAB_052B

	xor $07

.LAB_052B:
	sub $04
	add b
	ldh [rSCX],a

.LAB_0530:
	ret