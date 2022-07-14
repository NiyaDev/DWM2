
SECTION "AREA_07C6", ROM0[$07C6]

;; Immediately returns
FUN_07C6: ;;07C6
	ret
	

;;
FUN_07C7: ;;07C7
	;; Clears interrupt flags
	xor a
	ldh [rIF],a

	;; Sets enabled interrupts to 
	ldh a,[rIE]
	and $E0 | IEF_HILO | IEF_TIMER | IEF_STAT | IEF_VBLANK
	ldh [rIE],a

	ret