
SECTION "FUN_07AA", ROM0[$07AA]

;;
FUN_07AA: ;;07AA
	;; Set bit 7 of UNK_C5EC, then loaded into rLCDC
	ld  hl,$C5EC
	set 7,[hl]
	ld  a,[hl]
	ldh [rLCDC],a

	;; If UNK_C524 == false, return
	ld  a,[UNK_C524]
	or  a
	ret z

	;; Long call FUN_ROM31_5040
	ld  a,1
	ld  [UNK_C47C],a
	ld  b,31
	ld  hl,$5040
	rst $10
	call wait_7000

	ret