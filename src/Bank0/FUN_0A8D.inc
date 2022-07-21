
SECTION "0A8D", ROM0[$0A8D]

;; 
FUN_0A8D: ;;0A8D

	;; If [UNK_C58A] == 0 and [UNK_C55D] == 0, clear [UNK_C560] & [UNK_C561]
	ld  a,[UNK_C58A]
	or  a
	jr  nz,.skip_clear
	ld  a,[UNK_C55D]
	or  a
	jr  nz,.skip_clear

	xor a
	ld  [UNK_C560],a
	ld  [UNK_C561],a

.skip_clear:
	;; Clear [UNK_C563]
	xor a
	ld  [UNK_C563],a

	;; [UNK_C562] = (([UNK_C55E] ^ [UNK_C55F]) & [UNK_C55E]).
	ld  hl,UNK_C55E
	ld  a,[hl]
	inc hl
	xor [hl]
	dec hl
	and [hl]
	ld  [UNK_C562],a

	;; If [UNK_C55E] == 0, jump
	ld  hl,UNK_C55E
	ld  a,[hl+]
	or  a
	jr  z,.LAB_0AB9

	;; If [UNK_C55E] == [UNK_C55F], jump
	cp  [hl]
	jr  z,.LAB_0AC6

.LAB_0AB9:
	;; Store [UNK_C562] into [UNK_C563]
	ld  a,[UNK_C562]
	ld  [UNK_C563],a

	;; Store $14 into [UNK_C564]
	ld  a,$14
	ld  [UNK_C564],a

	jr  .LAB_0AD6


.LAB_0AC6:
	;; If [UNK_C564] != 0, jump
	ld  hl,UNK_C564
	ld  a,[hl]
	or  a
	jr  nz,.LAB_0AD5

	;; [UNK_C564] = $06
	ld  [hl],$06

	;; Store [UNK_C55E] into [UNK_C563]
	ld  a,[UNK_C55E]
	ld  [UNK_C563],a

.LAB_0AD5:
	dec [hl]

.LAB_0AD6:
	;; Clear [UNK_C567]
	xor a
	ld  [UNK_C567],a

	;; [UNK_C566] = (([UNK_C560] ^ [UNK_C561]) & [UNK_C560]).
	ld  hl,UNK_C560
	ld  a,[hl]
	inc hl
	xor [hl]
	dec hl
	and [hl]
	ld  [UNK_C566],a

	;; If [UNK_C560] == 0, jump
	ld  hl,UNK_C560
	ld  a,[hl+]
	or  a
	jr  z,.LAB_0AEF

	;; If [$C560] == [$C561], jump
	cp [hl]
	jr  z,.LAB_0AFC

.LAB_0AEF:
	;; Store [UNK_C566] into [UNK_C567]
	ld  a,[UNK_C566]
	ld  [UNK_C567],a

	;; Store $14 into [UNK_C568]
	ld  a,$14
	ld  [UNK_C568],a

	jr .leave


.LAB_0AFC
	;; If [UNK_C568] != 0, jump
	ld  hl,UNK_C568
	ld  a,[hl]
	or  a
	jr  nz,.LAB_0B0B

	;; Store $06 into [UNK_C568]
	ld  [hl],$06

	;; Store [UNK_C560] into [UNK_C567]
	ld  a,[UNK_C560]
	ld  [UNK_C567],a

.LAB_0B0B:
	dec [hl]

.leave:
	ret