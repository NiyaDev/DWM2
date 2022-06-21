
SECTION "FUN_0705", ROM0[$0705]


;; FUN_0705 (A: value, BC: counter, DE: ptr, H: bank)
FUN_0705:
	ld  [$C47C],a            ;; [$C47C] = [value]

	ld  a,[$C524]            ;;
	or  a                    ;;
	ret z                    ;; if [$C524] == 0, return


	push hl                  ;;
	push bc                  ;;

	call DisableLCD          ;; =DisableLCD ()

	call FUN_0B9B            ;; TODO:

	xor a                    ;;
	ldh [rSCX],a             ;;
	ldh [rSCY],a             ;;
	ld  a,$E4                ;;
	ldh [rBGP],a             ;;

	pop bc                   ;;
	pop hl                   ;;


	ld  a,[$4000]            ;; usually uses $4100, for some reson this one doesn't
	push af                  ;; Save current bank

	push bc                  ;;
	ld  a,h                  ;;
	ld  [rROMB0],a           ;; Sets bank to [bank]
	pop bc                   ;;

	ld  hl,$8800             ;;

.LAB_072D:
	ld  a,[de]               ;;
	ld  [hl+],a              ;; [HL] = [DE]
	inc de                   ;;
	dec bc                   ;;
	ld  a,b                  ;;
	or  c                    ;;
	jr  nz,.LAB_072D         ;; if BC != 0, loop

	ld  hl,$9800             ;;
	ld  de,$000C             ;;
	ld  a,$80                ;;
	ld  c,$0D                ;;

.LAB_073F:
	ld  b,$14                ;;

.LAB_0741:
	ld  [hl+],a              ;;
	inc a                    ;;
	dec b                    ;;
	jr  nz,.LAB_0741         ;; if B != 0, loop

	add hl,de                ;;
	dec c                    ;;
	jr  nz,.LAB_073F         ;; if C != 0, loop

	ld  a,$81                ;;
	ldh [rLCDC],a            ;;
	ld  [$C5EC],a            ;;
	
	ld  bc,$0005             ;;
	call Wait1750_X          ;; =Wait1750_X (5)
	
	ld  hl,$5040             ;;
	ld  b,$1F                ;;
	rst $10                  ;; =RST10 (31, $5040) ;; Call FUN_ROM31_5040

	ld  bc,$0006             ;;
	call Wait1750_X          ;; =Wait1750_X (6)

	call DisableLCD          ;; =DisableLCD ()

	pop af                   ;;
	ld  [rROMB0],a           ;; Sets bank back to start
	ret

