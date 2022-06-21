
SECTION "FUN_05E2", ROM0[$05E2]


;; FUN_05E2 ()
FUN_05E2:          ;; $05E2
	ld  a,$0B                ;;
	ld  [$C47C],a            ;; [$C47C] = $0B

	ld  b,$1F                ;;
	ld  hl,$5040             ;;
	rst $10                  ;; =RST10 (31, $5040) ;; Call FUN_ROM31_5040

	call Wait7000            ;; =Wait7000 ()

	ldh a,[rP1]              ;;
	and $03                  ;;
	cp  $03                  ;;
	jr  nz,.leave            ;; This is always true
	                         ;; when forced false, the game plays normally
							 ;; except loading loses it's fade transition

	ld  a,P1F_GET_DPAD       ;;
	ldh [rP1],a              ;;

	ldh a,[rP1]              ;;
	ldh a,[rP1]              ;;

	ld  a,P1F_GET_NONE       ;;
	ldh [rP1],a              ;;

	ld  a,P1F_GET_BTN        ;;
	ldh [rP1],a              ;;

	ldh a,[rP1]              ;;
	ldh a,[rP1]              ;;
	ldh a,[rP1]              ;;
	ldh a,[rP1]              ;;
	ldh a,[rP1]              ;;
	ldh a,[rP1]              ;;

	ld  a,P1F_GET_NONE       ;;
	ldh [rP1],a              ;;

	ldh a,[rP1]              ;;
	ldh a,[rP1]              ;;
	ldh a,[rP1]              ;;

	ldh a,[rP1]              ;;
	and $03                  ;;
	cp  $03                  ;;
	jr  nz,.leave            ;; if Left+Right / B+A are pressed, leave

	ld  a,$0A                ;;
	ld  [$C47C],a            ;;

	ld  b,$1F                ;;
	ld  hl,$5040             ;;
	rst $10                  ;; =RST10 (31, $5040) ;; Call FUN_ROM31_5040

	call Wait7000            ;; =Wait7000 ()
	sub a                    ;; return 0
	ret

.leave:
	ld  a,$0A                ;;
	ld  [$C47C],a            ;;

	ld  b,$1F                ;;
	ld  hl,$5040             ;;
	rst $10                  ;; =RST10 (31, $5040) ;; Call FUN_ROM31_5040

	call Wait7000            ;; =Wait7000 ()

	scf                      ;; carry = true
	ret

