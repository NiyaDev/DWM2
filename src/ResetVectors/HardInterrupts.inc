
SECTION "HardwareInterrupts", ROM0[$0040]


;; TODO:
intr_vblank:
	di
	jp  FUN_03A4
	db $00,$00,$00,$00

;; TODO:
intr_stat:
	jp  stat_interrupt
	db $00,$00,$00,$00,$00

intr_timer:
	db $00,$00,$00,$00,$00,$00,$00,$00

;; TODO:
intr_serial:
	jp  FUN_255B
	reti
	db $00,$00,$00,$00

intr_joypad:
	db $00,$00,$00,$00,$00,$00,$00,$00