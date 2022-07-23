
SECTION "0C5A", ROM0[$0C5A]

;; Loops until [UNK_FFD6] is false, then sets it to true, calls a function then resets it to false.
FUN_0C5A: ;;0C5A
	;; If [UNK_FFD6] != 0, loop
	ldh a,[UNK_FFD6_SH]
	or  a
	jr  nz,FUN_0C5A

	;; Set [UNK_FFD6] to 1 and call FUN_0C69
	inc a
	ldh [UNK_FFD6_SH],a
	call FUN_0C69

	;; Set [UNK_FFD6] to 0
	xor a
	ldh [UNK_FFD6_SH],a

	ret