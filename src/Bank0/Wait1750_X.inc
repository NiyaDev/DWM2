
SECTION "wait_1750_x", ROM0[$0692]

;; Wait for 1750 loops a number of times equal to counter.
;; Each loop has a wait time of .015 seconds each
wait_1750_x: ;;0692
	;; if [$C524] == 0, return
	ld  a,[$C524]
	or  a
	ret z

.repeat:
	ld  de,$06D6

.loop: ;; 36 cycles per loop
	nop
	nop
	nop

	;; if DE != 0, loop
	dec de
	ld  a,d
	or  e
	jr  nz,.loop

	;; if BC != 0, repeat
	dec bc
	ld  a,b
	or  c
	jr  nz,.repeat
	ret