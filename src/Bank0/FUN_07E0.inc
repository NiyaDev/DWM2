
SECTION "07E0", ROM0[$07E0]

;; Copies a few values from HRAM to screen X/Y and Window X/Y
FUN_07E0: ;;07E0
	ldh a,[UNK_FFA1_SH]
	ldh [rSCX],a
	ldh a,[UNK_FFA5_SH]
	ldh [rSCY],a
	ldh a,[UNK_FF9F_SH]
	ldh [rWX],a
	ldh a,[UNK_FFA0_SH]
	ldh [rWY],a
	ret