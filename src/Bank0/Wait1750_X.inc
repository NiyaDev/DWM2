
SECTION "Wait1750_X", ROM0[$0692]

;; Wait1750_X (BC: counter)
;; Wait for 1750 loops a number of times equal to counter.
;; Each loop has a wait time of .015 seconds each
Wait1750_X:        ;; $0692
	ld  a,[$C524]            ;;
	or  a                    ;;
	ret z                    ;; if [$C524] == 0, return

.repeat:
	ld  de,$06D6             ;;

.loop: ;; 36 cycles per loop
	nop                      ;;
	nop                      ;;
	nop                      ;;

	dec de                   ;;
	ld  a,d                  ;;
	or  e                    ;; 
	jr  nz,.loop             ;; if DE != 0, loop

	dec bc                   ;;
	ld  a,b                  ;;
	or  c                    ;;
	jr  nz,.repeat           ;; if BC != 0, repeat
	ret