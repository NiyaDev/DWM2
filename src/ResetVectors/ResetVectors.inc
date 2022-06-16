
SECTION "RST", ROM0[$0000]


;; RST00 (A: param_1, HL: pointer)
;; TODO: Still need an example of it being used
RST00:
	pop hl                 ;;
	push de                ;;

	ld  e,a                ;;
	ld  d,$00              ;;
	sla e                  ;;
	rl  d                  ;;
	add hl,de              ;;
	pop de                 ;;

	ld  a,[hl+]            ;;
	ld  h,[hl]             ;;
	ld  l,a                ;;


;; HLJump (HL: pointer)
HLJump:
	jp  hl                 ;;
	nop                    ;;


;; RST10 (B: bankNum, HL: pointer)
RST10:
	ld  a,[$4000]          ;;
	push af                ;; Pushes the number of the current ROM bank
	ld  a,b                ;;
	ld  [$2100],a          ;; Sets the lower 8-bits of ROM bank to =Bank
	call HLJump            ;; =HLJump()
	pop af                 ;;
	ld [$2100],a           ;; Resets the ROM bank to the original
	ret


;; Filler
RST20:
	db $00,$00,$00,$00,$00,$00,$00,$00
RST28:
	db $00,$00,$00,$00,$00,$00,$00,$00
RST30:
	ret
	db $00,$00,$00,$00,$00,$00,$00
RST38:
	ret
	db $00,$00,$00,$00,$00,$00,$00