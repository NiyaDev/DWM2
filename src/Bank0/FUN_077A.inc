
SECTION "FUN_077A", ROM0[$077A]


;;
FUN_077A: ;;077A
	push af

	;; Call FUN_14D1 if [UNK_C58A] != 0
	ld  a,[UNK_C58A]
	or  a
	jr  z,.LAB_0784
	
	call FUN_14D1

.LAB_0784:
	call FUN_07AA

	pop af

	call set_enabled_interrupts

	ei

	ret