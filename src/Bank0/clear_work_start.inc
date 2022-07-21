
SECTION "clear_work_start", ROM0[$0BA7]

;; Clears first 160 bytes of work RAM
clear_work_start: ;;0BA7
	xor a
	ldh [UNK_FFB1],a

	ld  hl,UNK_C000
	ld  b,160

.loop: ;;0BAF
	ld  [hl+],a
	dec b
	jr  nz,.loop

	ret