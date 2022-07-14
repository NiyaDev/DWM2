
SECTION "07D1", ROM0[$07D1]

;; Waits until bit 7 of [rSC] Serial I/O control is 1
FUN_07D1: ;;07D1
	ldh a,[rSC]
	bit 7,a
	jr  nz,FUN_07D1

	ret