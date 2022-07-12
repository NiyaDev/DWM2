
SECTION "wait_7000", ROM0[$05D1]

;; Wait for 7000 loops
;; Total wait time of .0615 seconds
wait_7000: ;;05D1
	ld  a,[UNK_C524]
	or  a
	ret z

	ld  de,$1B58

.loop: ;; 36 cycles per loop
	nop
	nop
	nop

	;; while de != 0, loop
	dec de
	ld  a,d
	or  e
	jr  nz,.loop
	ret

