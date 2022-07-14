
SECTION "copy_obj_palette", ROM0[$085C]

;; If bit 7 of [UNK_C527] is zero, it copies object palette data from address $00-$40
;; Else it just copies the 8 bytes from the offset provided by FUN_0897
;; Though, oddly, it doesn't turn on auto-increment unless it does the full $40
copy_obj_palette: ;;085C
	;; If bit 7 of [UNK_C527] == 0, jump
	ld  a,[UNK_C527]
	bit 7,a
	jr  z,.long_loop

	;; Save [UNK_C526] into [rBCPS]
	;; Add $C4DF to output of FUN_0897
	ldh [rOCPS],a
	call FUN_0897
	ld  a,l
	add OCPD_MEM_LOWER
	ld  l,a
	ld  a,h
	adc OCPD_MEM_UPPER
	ld  h,a

	;; Copy hl to de
	ld  e,l
	ld  d,h

	;; Set to loop 8 times
	ld  b,$08
	jr  .skip


.long_loop:
	di

	call FUN_120A

	;; Set [rOCPS] to auto increment address
	ld  a,OCPSF_AUTOINC
	ldh [rOCPS],a

	ei

	;; Set to loop 64 times
	ld  b,OCPD_MEM_LENGTH
	ld  de,OCPD_MEM_START

.skip:
	ld  hl,rOCPD

.loop:
	ld  a,[de]
	inc de
	ld  c,a

	di

.wait:
	ldh a,[rSTAT]
	bit 1,a
	jr  nz,.wait

	ld  [hl],c

	ei

	dec b
	jr  nz,.loop

	ret