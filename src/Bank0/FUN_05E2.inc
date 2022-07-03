
SECTION "FUN_05E2", ROM0[$05E2]

;; 
FUN_05E2: ;;05E2
	long_call_rom31_5040 11

	;; Checks if L/R + B/A are pressed
	;; This seems to always be true
	;; when forced false, the game plays normally
	;; except loading loses it's fade transition
	ldh a,[rP1]
	and P1F_1|P1F_0
	cp  P1F_1|P1F_0
	jr  nz,.leave

	;; Sets rP1 to DPAD
	ld  a,P1F_GET_DPAD
	ldh [rP1],a

	
REPT 2
	ldh a,[rP1]
ENDR


	;; Sets rP1 to NONE
	ld  a,P1F_GET_NONE
	ldh [rP1],a

	;; Sets rP1 to BTN
	ld  a,P1F_GET_BTN
	ldh [rP1],a


REPT 6
	ldh a,[rP1]
ENDR


	;; Sets rP1 to NONE
	ld  a,P1F_GET_NONE
	ldh [rP1],a


REPT 3
	ldh a,[rP1]
ENDR


	;; If Left+Right / B+A are pressed, leave? It's set to NONE so i don't know
	ldh a,[rP1]
	and P1F_1|P1F_0
	cp  P1F_1|P1F_0
	jr  nz,.leave

	long_call_rom31_5040 10

	;; Return false
	sub a
	ret

.leave:
	long_call_rom31_5040 10

	;; Return true
	scf
	ret

