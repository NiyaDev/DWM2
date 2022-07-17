
SECTION "0A17", ROM0[$0A17]

;; Joypad stuff
;; TODO: 0A61
FUN_0A17: ;;0A17
	;; If false, alternate version
	ld  a,[UNK_C524]
	or  a
	jr  z,.LAB_0A39

	call FUN_0646

	;; Copy [UNK_C55E] to [UNK_C55F]
	ld  a,[UNK_C55E]
	ld  [UNK_C55F],a

	;; Copy [UNK_C474] to [UNK_C55E]
	ld  a,[UNK_C474]
	ld  [UNK_C55E],a

	;; Copy [UNK_C560] to [UNK_C561]
	ld  a,[UNK_C560]
	ld  [UNK_C561],a

	;; Copy [UNK_C476] to [UNK_C560]
	ld  a,[UNK_C476]
	ld  [UNK_C560],a

	ret

.LAB_0A39:
	xor a
	ld  [UNK_C55D],a

	call get_input

	;; Copy [UNK_C55E] to [UNK_C55F]
	ld  a,[UNK_C55E]
	ld  [UNK_C55F],a

	;; Copy output of FUN_0A61 into [UNK_C55E]
	ld  a,b
	ld  [UNK_C55E],a

	;; Clear [rP1]
	ld  a,P1F_GET_NONE
	ldh [rP1],a

	ret