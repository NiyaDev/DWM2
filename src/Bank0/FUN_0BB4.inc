
SECTION "0BB4", ROM0[$0BB4]

;; This is weird.
;; Looks like if [UNK_FFB1] != 40 it clears every fourth byte a number of times equal to [UNK_FFB1] - 40.
;; Considering it increments B, it might mean [UNK_FFB1] needs to be LESS than 40 for this to work.
FUN_0BB4: ;;0BB4
	;; If [UNK_FFB1] == $28, return
	ldh a,[UNK_FFB1_SH]
	cp  $28
	ret z

	;; HL = ([UNK_FFB1] << 2) + $C000
	ld  l,a
	sla l
	sla l
	ld  h,$C0

	;; B = [UNK_FFB1] - 40
	sub $28
	ld  b,a

	;; A = 0
	xor a

.LAB_0BC4:
	;; Clear every fourth byte
	ld  [hl+],a

	inc l
	inc l
	inc l

	inc b
	jr  nz,.LAB_0BC4

	ret