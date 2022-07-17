
SECTION "get_input", ROM0[$0A61]

;; Grabs button input from both dpad and buttons and outputs them in B 
;; bits 4-7: DPAD
;; bits 0-3: BTNS
get_input: ;;0A61
	;; Set input to Dpad
	ld  a,P1F_GET_DPAD
	ldh [rP1],a

REPT 2
	ldh a,[rP1]
ENDR

	;; Isolate input
	cpl
	and $0F

	swap a
	ld  b,a

	;; Set input to buttons
	ld  a,P1F_GET_BTN
	ldh [rP1],a

REPT 10
	ldh a,[rP1]
ENDR

	;; Isolate input
	cpl
	and $0F

	or  b
	ld  b,a

	ret