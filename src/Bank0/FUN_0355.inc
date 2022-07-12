
SECTION "FUN_0355", ROM0[$0355]

;; Long calls function based on input
;; Input: [UNK_C5DB]
FUN_0355: ;;0355
	ld  a,[UNK_C5DB]
	rst $00


	dw .LAB_036B, .LAB_0372, .LAB_0379, .LAB_0380, .LAB_0381, .LAB_0388, .LAB_038F, .LAB_0396, .LAB_039D


.LAB_036B:
	ld  hl,$4001
	ld  b,1
	rst $10

	ret

.LAB_0372:
	ld  hl,$45C6
	ld  b,2
	rst $10

	ret
	
.LAB_0379:
	ld  hl,$4001
	ld  b,3
	rst $10

	ret

.LAB_0380:
	ret 

.LAB_0381:
	ld  hl,$4001
	ld  b,49
	rst $10

	ret

.LAB_0388:
	ld  hl,$486E
	ld  b,7
	rst $10

	ret

.LAB_038F:
	ld  hl,$4001
	ld  b,36
	rst $10

	ret

.LAB_0396:
	ld  hl,$4ECF
	ld  b,160
	rst $10

	ret

.LAB_039D:
	ld  hl,$4001
	ld  b,242
	rst $10

	ret
