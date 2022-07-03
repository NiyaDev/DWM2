
SECTION "FUN_42FA", ROMX[$42FA], BANK[2]

;; If GBC, copies data from UNK_DATA_4322 to two places in WRAM
FUN_ROM2_42FA:
	;; Check if GBC
	ld  a,[IsGBC]
	or  a
	ret z

	;; Copy UNK_DATA_4322 to [$C49F-$C4A6]
	ld  hl,$C49F
	ld  de,UNK_DATA_4322
	ld  bc,$0008
	call memcpy

	ld  a,$7F
	ld  [UNK_C526],a

	;; Copy UNK_DATA_4322 to [$C4DF-$C4E6]
	ld  hl,$C4DF
	ld  de,UNK_DATA_4322
	ld  bc,$0008
	call memcpy

	ld  a,$7F
	ld  [UNK_C527],a

	ret


UNK_DATA_4322: db $00, $7C, $FF, $7F, $E0, $01, $00, $00