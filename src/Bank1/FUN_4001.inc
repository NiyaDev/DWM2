
SECTION "FUN_4001", ROMX[$4001], BANK[1]


;;
FUN_4001:          ;;4001
	ld  hl,$8800
	ld  DE,$1007
	call FUN_2E98

	ld  hl,$9000
	ld  de,$1007
	call FUN_2E98

	xor a
	ld  [$C5F8],a
	ld  [$C5F9],a
	ld  [$C5FA],a
	ld  [$C5FB],a
	ld  [$C5FC],a
	ld  [$C5FD],a
	ld  [$C5FE],a
	ld  [$C5FF],a

	xor a
	ld  [$C5F6],a
	ld  [$C5F7],a

	call FUN_ROM1_4045

	ld  a,$FC
	call FUN_0DF2

	ld  a,$03
	ld  [$C5EC],a
	ld  a,$01
	jp  FUN_077A