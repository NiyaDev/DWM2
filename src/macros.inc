
;; Call FUN_ROM31_5040
MACRO long_call_rom31_5040
	ld  a,\1
	ld  [UNK_C47C],a
	ld  b,bank(FUN_ROM31_5040)
	ld  hl,FUN_ROM31_5040
	rst $10
	call wait_7000
ENDM