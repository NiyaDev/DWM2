
SECTION "intr_vblank", ROM0[$0040]

;; 
intr_vblank:
	di
	jp  FUN_03A4



SECTION "intr_stat", ROM0[$0048]

;; 
intr_stat:
	jp  stat_interrupt



SECTION "intr_serial", ROM0[$0058]

;; 
intr_serial:
	jp  FUN_255B
	reti