
SECTION "048A", ROM0[$048A]


;;
FUN_048A:
	ld  a,[$C5DF]
	or  a
	ret nz

	ld  a,[$C58A]
	or  a
	jr  nz,.LAB_049E

	ld  a,[$C56C]
	or  a
	jr  z,.LAB_049E

	bit 7,a
	ret z

.LAB_049E:
	ld  a,[$C5DB]
	rst $00

	
	dw .LAB_04B4, .LAB_04BB, .LAB_04C2, .LAB_04C9, .LAB_04CA, .LAB_04D1, .LAB_04D8, .LAB_04DF, .LAB_04E6

	
.LAB_04B4:
	ld  hl,$4AD4
	ld  b,1
	rst $10

	ret


.LAB_04BB:
	ld  hl,$4AD8
	ld  b,2
	rst $10

	ret


.LAB_04C2:
	ld  hl,$4015
	ld  b,3
	rst $10

	ret


.LAB_04C9:
	ret


.LAB_04CA:
	ld  hl,$40A5
	ld  b,49
	rst $10

	ret


.LAB_04D1:
	ld  hl,$4F7B
	ld  b,7
	rst $10

	ret


.LAB_04D8:
	ld  hl,$4117
	ld  b,$24
	rst $10

	ret


.LAB_04DF:
	ld  hl,$4F70
	ld  b,160
	rst $10

	ret


.LAB_04E6:
	ld  hl,$40A2
	ld  b,242
	rst $10

	ret