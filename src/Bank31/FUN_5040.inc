
SECTION "5040", ROMX[$5040], BANK[31]


;; FUN_ROM31_5040 ()
;; TODO: I still have no idea what this is, but i'm just throwing to the side for now.
;;       It does something. What? I don't know. 
FUN_ROM31_5040:    ;; 31,5040
	ld  a,[$C524]            ;;
	or  a                    ;;
	ret z                    ;; if [$C524] == 0, return

	ld  a,[$C47C]            ;;
	cp  $FF                  ;;
	jr  nz,.skip_1           ;; if [$C47C] != $FF, skip
	
	ld  hl,$C47F             ;;
	jr  .continue            ;;

.skip_1:           ;; 31,5051
	ld  l,a                  ;;
	ld  h,$00                ;; HL  = $00[$C47C]
	add hl,hl                ;; HL += HL
	ld  de,$5094             ;;
	add hl,de                ;; HL += $5094
	ld  e,[hl]               ;;
	inc hl                   ;; HL++
	ld  d,[hl]               ;;
	push de                  ;;
	pop hl                   ;; 

.continue:         ;; 31,505E
	ld  a,[hl]               ;;
	and $07                  ;; Take the first u8 at [hl] and check if 7
	ret z                    ;; if [HL] & 7 == 0, return

	ld  b,a                  ;;
	ld  c,$00                ;;

.loop:             ;; 31,5065
	push bc                  ;;

	ld  a,$00                ;;
	ldh [c],a                ;;
	ld  a,P1F_GET_NONE       ;;
	ldh [c],a                ;; does something with P1

	ld  b,$10                ;;

.outer_loop:       ;; 31,506E
	ld  e,$08                ;;
	ld  a,[hl+]              ;;
	ld  d,a                  ;; 

.inner_loop:       ;; 31,5072
	bit 0,d                  ;;
	ld  a,P1F_GET_BTN        ;;
	jr  nz,.skip_2           ;; if bit 0 of D != 0, skip loading A

	ld  a,P1F_GET_DPAD       ;;

.skip_2:           ;; 31,507A
	ldh [c],a                ;;
	ld  a,P1F_GET_NONE       ;;
	ldh [c],a                ;;

	rr  d                    ;; rotate right
	dec e                    ;;
	jr  nz,.inner_loop       ;; if E != 0, loop

	dec b                    ;;
	jr  nz,.outer_loop       ;; if B != 0, loop

	ld  a,P1F_GET_DPAD       ;;
	ldh [c],a                ;;
	ld  a,P1F_GET_NONE       ;;
	ldh [c],a                ;;

	pop bc                   ;;

	dec b                    ;;
	ret z                    ;; if b == 0, return

	call Wait7000            ;;

	jr .loop                 ;;


;; Pointers to the next group
SECTION "5094", ROMX[$5094], BANK[31]
		dw  $513E
		dw  $514E
		dw  $50BE
		dw  $50CE
		dw  $50DE
		dw  $50EE
		dw  $50FE
		dw  $510E
		dw  $511E
		dw  $512E
		dw  $515E
		dw  $516E
		dw  $517E
		dw  $518E
		dw  $519E
		dw  $51AE
		dw  $51BE
		dw  $51CE
		dw  $51DE
		dw  $51EE
		dw  $51FE

;; TODO: Unknown
SECTION "50BE", ROMX[$50BE], BANK[31]
		db  $79, $5D, $08, $00, $0B, $8C, $D0, $F4, $60, $00, $00, $00, $00, $00, $00, $00
		db  $79, $52, $08, $00, $0B, $A9, $E7, $9F, $01, $C0, $7E, $E8, $E8, $E8, $E8, $E0
		db  $79, $47, $08, $00, $0B, $C4, $D0, $16, $A5, $CB, $C9, $05, $D0, $10, $A2, $28
		db  $79, $3C, $08, $00, $0B, $F0, $12, $A5, $C9, $C9, $C8, $D0, $1C, $A5, $CA, $C9
		db  $79, $31, $08, $00, $0B, $0C, $A5, $CA, $C9, $7E, $D0, $06, $A5, $CB, $C9, $7E
		db  $79, $26, $08, $00, $0B, $39, $CD, $48, $0C, $D0, $34, $A5, $C9, $C9, $80, $D0
		db  $79, $1B, $08, $00, $0B, $EA, $EA, $EA, $EA, $EA, $A9, $01, $CD, $4F, $0C, $D0
		db  $79, $10, $08, $00, $0B, $4C, $20, $08, $EA, $EA, $EA, $EA, $EA, $60, $EA, $EA
		db  $B9, $01, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00
		db  $B9, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00
		db  $89, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00
		db  $89, $01, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00
		db  $59, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00
		db  $A9, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00
		db  $51, $00, $00, $01, $00, $02, $00, $03, $00, $C0, $00, $00, $00, $00, $00, $00
		db  $A1, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00
		db  $99, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00
		db  $99, $01, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00
		db  $C9, $01, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00
		db  $71, $01, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00
		db  $B9, $02, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00
