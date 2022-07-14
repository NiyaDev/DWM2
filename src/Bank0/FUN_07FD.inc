
SECTION "07FD", ROM0[$07FD]

;; Loads the background and object palettes from memory
FUN_07FD: ;;07FD
	ld  hl,UNK_C5E9

	ld  a,[hl+]
	ldh [rBGP],a

	ld  a,[hl+]
	ldh [rOBP0],a

	ld  a,[hl]
	ldh [rOBP1],a

	ret