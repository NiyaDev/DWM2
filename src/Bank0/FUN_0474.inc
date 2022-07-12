
SECTION "0474", ROM0[$0474]

;; 
FUN_0474: ;;0474
	;; Sets [UNK_FFB1] to 0
	xor a
	ldh [UNK_FFB1],a

	call FUN_252D
	call FUN_048A

	;; If [UNK_C56C] == 0 || ([UNK_C56C] & $80) == true, call FUN_0BB4
	ld  a,[UNK_C56C]
	or  a
	jr  z,.skip
	bit 7,a
	ret z

.skip:
	call FUN_0BB4

	ret