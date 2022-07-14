
SECTION "copy_bg_palette", ROM0[$0829]

;; If bit 7 of [UNK_C526] is zero, it copies background palette data from address $00-$40
;; Else it just copies the 8 bytes from the offset provided by FUN_0897
;; Though, oddly, it doesn't turn on auto-increment unless it does the full $40
copy_bg_palette: ;;0829
	;; If bit 7 of [UNK_C526] == 0, jump
	ld  a,[UNK_C526]
	bit 7,a
	jr  z,.long_loop

	;; Save [UNK_C526] into [rBCPS]
	;; Add $C49F to output of FUN_0897
	ldh [rBCPS],a
	call FUN_0897
	ld  a,l
	add BCPD_MEM_LOWER
	ld  l,a
	ld  a,h
	adc BCPD_MEM_UPPER
	ld  h,a

	;; Set to loop 8 times
	ld  b,$08
	jr  .skip


.long_loop:
	di

	call FUN_120A

	;; Set [rBCPS] to auto increment address
	ld  a,BCPSF_AUTOINC
	ldh [rBCPS],a

	ei

	;; Set to loop 64 times
	ld  b,BCPD_MEM_LENGTH
	ld  hl,BCPD_MEM_START

.skip:
	ld  c,rBCPD_SH
.loop:
	di

	call FUN_120A

	;; Copy what's in hl into [rBCPD]
	ld  a,[hl+]
	ldh [c],a

	ei

	dec b
	jr  nz,.loop

	ret