
SECTION "Wait7000", ROM0[$05D1]


;; Wait7000 ()
;; Wait for 7000 loops
;; Total wait time of .0615 seconds
Wait7000:          ;; $05D1
	ld  a,[$C524]            ;;
	or  a                    ;;
	ret z                    ;; if [$C524] == 0, return

	ld  de,$1B58             ;;

.loop: ;; 36 cycles per loop
	nop                      ;;
	nop                      ;;
	nop                      ;;

	dec de                   ;;
	ld  a,d                  ;;
	or  e                    ;;
	jr  nz,.loop             ;; while de != 0, loop
	ret

