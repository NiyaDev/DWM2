
SECTION "SetInterrupts", ROM0[$078D]


;; SetInterrupts ()
;; Sets which interrupts are enabled
;; then waits for LY == 91 and disables LCD
SetInterrupts:
	xor  a                 ;;
	ldh  [rIF],a           ;;
	ldh  a,[rIE]           ;;
	and  $E2               ;;
	ldh  [rIE],a           ;; Disable Trans, Serial, Timer, and V-Blank interrupts, but enable LCDC

DisableLCD:
	ld  hl,$FF40           ;;
	bit $7,[hl]            ;;
	ret z                  ;; if LCD operation == false, return

.wait:
	ldh a,[rLY]            ;;
	cp  $91                ;;
	jr  nz,.wait           ;; if rLY != 91, loop

	res 7,[hl]             ;; Turn off screen
	ld  hl,$C5EC           ;;
	res 7,[hl]             ;; Reset bit 7 of $C5EC (Unknown variable)
	ret