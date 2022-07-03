
SECTION "set_interrupts", ROM0[$078D]

;; 
set_interrupts:
	;; Clear interrupt flags
	xor  a
	ldh  [rIF],a

	;; Disable all but STAT
	ldh  a,[rIE]
	and  %11100010
	ldh  [rIE],a

	;; Falls into disable_lcd