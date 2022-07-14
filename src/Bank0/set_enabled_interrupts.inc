
SECTION "set_enabled_interrupts", ROM0[$07D8]

;; Sets enabled interrupts to the input in A
set_enabled_interrupts: ;;07D8
	ld  b,a

	;; Clears interrupt flags
	xor a
	ldh [rIF],a

	;; Sets enabled interrupts
	ld  a,b
	ldh [rIE],a

	ret