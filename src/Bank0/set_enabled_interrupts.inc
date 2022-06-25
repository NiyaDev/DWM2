
SECTION "set_enabled_interrupts", ROM0[$07D8]


;;
set_enabled_interrupts: ;;07D8
	ld  b,a

	xor a
	ldh [rIF],a

	ld  a,b
	ldh [rIE],a

	ret