
SECTION "memcpy_banked", ROM0[$0B2B]

;; Copies data from src to dest
;; Input - B:bank C:count DE:src HL:dest
memcpy_banked: ;;0B2B
	;; Save current bank
	ld  a,[$4000]
	push af

	;; Set bank to input
	ld  a,b
	ld  [rROMB0],a

.LAB_0B33:
	di

.LAB_0B34:
	;; wait until ([rSTAT] & STATF_BUSY) != STATF_BUSY
	ldh a,[rSTAT]
	bit 1,a
	jr  nz,.LAB_0B34

	;; Copy byte from src to dest
	ld  a,[de]
	ld  [hl+],a
	inc de

	ei

	;; repeat for count
	dec c
	jr  nz,.LAB_0B33

	;; Restore original bank
	pop af
	ld  [rROMB0],a

	ret