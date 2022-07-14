
SECTION "07F1", ROM0[$07F1]

;; Loops until LCDC is in V-Blank and OAM is being used
FUN_07F1: ;;07F1
	ldh a,[rSTAT]
	and STATF_OAM | STATF_BUSY
	jr  nz,FUN_07F1

	ld  a,[UNK_C5EC]
	ldh [rLCDC],a
	ret