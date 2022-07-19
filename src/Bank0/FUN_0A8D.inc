
SECTION "0A8D", ROM0[$0A8D]

;; 
;; TODO: Finish going through
FUN_0A8D: ;;0A8D

	;; If [$C58A] == 0 and [$C55D] == 0, clear [$C560] & [$C561]
	ld  a,[$C58A]
	or  a
	jr  nz,.LAB_0AA0
	ld  a,[$C55D]
	or  a
	jr  nz,.LAB_0AA0

	xor a
	ld  [$C560],a
	ld  [$C561],a

.LAB_0AA0:
	xor a
	ld  [$C563],a

	;; Load [$C55E] into A
	ld  hl,$C55E
	ld  a,[hl]

	;; XOR A with [$C55F]
	inc hl
	xor [hl]

	;; AND A with [$C55E]
	dec hl
	and [hl]

	;; Save A into [$C562]
	ld  [$C562],a

	;; If [$C55E] == 0, jump
	ld  hl,$C55E
	ld  a,[hl+]
	or  a
	jr  z,.LAB_0AB9

	;; If [$C55E] == [$C55F], jump
	cp  [hl]
	jr  z,.LAB_0AC6

.LAB_0AB9:
	;; Store [$C562] into [$C563]
	ld  a,[$C562]
	ld  [$C563],a

	;; Store $14 into [$C564]
	ld  a,$14
	ld  [$C564],a

	jr  .LAB_0AD6


.LAB_0AC6:
	;; If [$C564] != 0, jump
	ld  hl,$C564
	ld  a,[hl]
	or  a
	jr  nz,.LAB_0AD5

	;; [$C564] = $06
	ld  [hl],$06

	;; Store [$C55E] into [$C563]
	ld  a,[$C55E]
	ld  [$C563],a

.LAB_0AD5:
	dec [hl]

.LAB_0AD6:
	;; Clear [$C567]
	xor a
	ld  [$C567],a

	ld  hl,$C560
	ld  a,[hl]

	inc hl
	xor [hl]
	dec hl

	and [hl]
	ld  [$C566],a

	ld  hl,$C560
	ld  a,[hl+]
	or  a
	jr  z,.LAB_0AEF

	cp [hl]
	jr  z,.LAB_0AFC

.LAB_0AEF:
	ld  a,[$C566]
	ld  [$C567],a

	ld  a,$14
	ld  [$C568],a

	jr .LAB_0B0C


.LAB_0AFC
	ld  hl,$C568
	ld  a,[hl]
	or  a
	jr  nz,.LAB_0B0B

	ld  [hl],$06

	ld  a,[$C560]
	ld  [$C567],a

.LAB_0B0B:
	dec [hl]

.LAB_0B0C:

	ret