
SECTION "FUN_0646", ROM0[$0646]

;; Does some joypad reading
;; TODO: step through
FUN_0646:
	;; Loads [rP1] into C and 4 into B
	ldh a,[rP1]
	ld  b,4
	ld  c,a
	jr  .skip

.loop: ;064D
	;; If up or select pressed, return.
	ldh a,[rP1]
	cp  c
	ret z

.skip: ;0651
	;; Complement, AND $03, then shift left A
	cpl
	and $03
	sla a

	;; Add A to [$C474] in HL
	ld  d,0
	ld  e,a
	ld  hl,$C474
	add hl,de

	;; Set [rP1] to DPAD
	ld  a,P1F_GET_DPAD
	ldh [rP1],a


REPT 2
	ldh a,[rP1]
ENDR


	;; Complement, AND $0F, then swap bits of A
	cpl 
	and $0F
	swap a

	;; Store A into D, then reset [rP1]
	ld  d,a
	ld  a,P1F_GET_NONE
	ldh [rP1],a

	;; Set [rP1] to  BTN
	ld  a,P1F_GET_BTN
	ldh [rP1],a


REPT 6
	ldh a,[rP1]
ENDR


	;; Complement, AND $0F, then OR A with D
	cpl
	and $0F
	or  d

	;; Store A into D, then [HL+]
	ld  d,a
	ld  a,[hl+]

	;; XOR then AND A with D
	xor d
	and d

	;; Store A into [HL-]
	ld  [hl-],a

	;; Grab D into A and sstore into [HL]
	ld  a,d
	ld  [hl],a

	;; Reset [rP1]
	ld  a,P1F_GET_NONE
	ldh [rP1],a

	dec b
	jr  nz,.loop

	ret