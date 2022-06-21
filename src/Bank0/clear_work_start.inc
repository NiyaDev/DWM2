
SECTION "clear_work_start", ROM0[$0BA7]


;; Clears first 160 bytes of work RAM
clear_work_start:  ;;0BA7
	xor a                    ;;
	ldh [$FFB1],a            ;;

	ld  hl,$C000             ;;
	ld  b,$A0                ;;

.loop:             ;;0BAF
	ld  [hl+],a              ;;
	dec b                    ;;
	jr  nz,.loop             ;;

	ret            ;;0BB3