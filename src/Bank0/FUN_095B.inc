
SECTION "FUN_095B", ROM0[$095B]

;; Loads a byte from ROM after this function based on a offset of [UNK_C5E8]
FUN_095B: ;;095B
	push hl

	;; [UNK_C5E8] == ([UNK_C5E8] + 1) & $7F
	ld  a,[UNK_C5E8]
	inc a
	and $7F
	ld  [UNK_C5E8],a

	;; Add [UNK_C5E8] to $0973
	ld  hl,$0973
	add l
	ld  l,a
	jr  nc,.no_inc
	inc h

.no_inc: ;;096A
	;; Load byte from [$0973 + [UNK_C5E8]] and store in [UNK_C5E7]
	ld  a,[hl]
	ld  [UNK_C5E7],a

	pop hl
	ret


LAB_0973:
	db $7B, $FE, $22, $DC, $18, $C4, $6D, $FB, $CD, $27, $A0, $09, $6E, $38, $8A, $04
	db $7C, $56, $97, $5A, $A8, $4D, $78, $B5, $6C, $AA, $03, $1A, $4A, $0D, $26, $82
	db $AD, $02, $A1, $B9, $A3, $6B, $D8, $0C, $4C, $AE, $19, $45, $5B, $9C, $16, $07
	db $89, $51, $90, $29, $F5, $62, $F7, $CB, $F1, $53, $FF, $14, $65, $D0, $87, $35
	db $3E, $4E, $4F, $83, $0E, $C9, $7F, $5D, $FC, $E6, $BA, $01, $F8, $00, $F4, $0A
	db $E5, $A9, $8D, $D1, $E8, $DB, $DE, $81, $95, $72, $08, $9A, $C7, $49, $C8, $23
	db $39, $37, $E0, $91, $C3, $33, $9B, $5F, $BE, $41, $EE, $74, $E2, $0B, $47, $7E
	db $BF, $60, $BB, $20, $61, $05, $B2, $94, $B6, $E4, $3A, $21, $1E, $B4, $8C, $CE

