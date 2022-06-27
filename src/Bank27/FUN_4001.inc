
SECTION "4001", ROMx[$4001],bank[27]


;;
FUN_ROM27_4001:
	ld  a,[$C580]
	bit 7,a
	jr  z,.LAB_400E

	set 6,a
	ld  [$C580],a

	ret

.LAB_400E:
	ld  a,[$C581]
	and a
	jr  z,.LAB_402A

	ld  a,[$C581]
	rst $00

	ld  a,[hl+]
	ld  b,b
	jp  hl


	;;TODO:
	db  $43, $20, $44, $57, $44, $8E, $44, $C5, $44, $FC, $44, $33, $45, $6A, $45


.LAB_402A:
	ld  a,$FF
	ld  [$D784],a

	xor a
	ld  [$D783],a
	ld  [$D784],a

	call FUN_07D1

	ld  a,[$D781]
	ld  [$D784],a

	ldh a,[rSB]
	ld  b,a
	cp  $F1
	jr  z,.LAB_4132

	cp  $F5
	jr  z,.LAB_4060

	cp  $F6
	jr  z,.LAB_408A

	cp  $B7
	jr  z,.LAB_40B4

	cp  $E0
	jr  z,.LAB_40DE

	cp  $DC
	jr  z,.LAB_4108

	jp  .LAB_4163


.LAB_4060:
	call FUN_ROM27_4394

	cp  $FF
	jp  z,.LAB_4357

	ld  a,[$C46B]
	cp  $02
	jr  z,.LAB_407D

	ld  a,$02
	ld  [$C471],a

	ld  a,[$D782]
	ld  [$D785],a

	jp  .LAB_4357


.LAB_407D:
	ld  a,[$C57F]
	set 0,a
	set 1,a
	ld  [$C57F],a

	jp  .LAB_42A7


.LAB_408A:
	call FUN_ROM27_4394

	cp  $FF
	jp  z,.LAB_4357

	ld  a,[$C46B]
	cp  $03
	jr  z,.LAB_40A7

	ld  a,$03
	ld  [$C471],a

	ld  a,[$D782]
	ld  [$D785],a

	jp  .LAB_4357


.LAB_40A7:
	ld  a,[$C57F]
	set 0,a
	set 1,a
	ld  [$C57F],a

	jp  .LAB_42C3


.LAB_40B4:
	call FUN_ROM27_4394

	cp  $FF
	jp  z,.LAB_4357

	ld  a,[$C46B]
	cp  $04
	jr  z,.LAB_40D1

	ld  a,$04
	ld  [$C471],a

	ld  a,[$D782]
	ld  [$D785],a

	jp  .LAB_4357


.LAB_40D1:
	ld  a,[$C57F]
	set 0,a
	set 1,a
	ld  [$C57F],a

	jp  .LAB_4301
	

.LAB_40DE:
	call FUN_ROM27_4394

	cp  $FF
	jp  z,.LAB_4357

	ld  a,[$C46B]
	cp  $06
	jr  z,.LAB_40FB

	ld  a,$06
	ld  [$C471],a

	ld  a,[$D782]
	ld  [$D785],a

	jp  .LAB_4357


.LAB_40FB:
	ld  a,[$C57F]
	set 0,a
	set 1,a
	ld  [$C57F],a

	jp  .LAB_4320


.LAB_4108:
	call FUN_ROM27_4394

	cp  $FF
	jp  z,.LAB_4357

	ld  a,[$C46B]
	cp  $05
	jr  z,.LAB_4125

	ld  a,$05
	ld  [$C471],a

	ld  a,[$D782]
	ld  [$D785],a

	jp  .LAB_4357


.LAB_4125:
	ld  a,[$C57F]
	set 0,a
	set 1,a
	ld  [$C57F],a

	jp  .LAB_42E2


.LAB_4132:
	call FUN_ROM27_4394

	cp  $FF
	jp  z,.LAB_4357

	ld  a,[$C46B]
	cp  $07
	jr  z,.LAB_4156

	ld  a,[$C894]
	or  a
	jp  z,.LAB_4357

	ld  a,$07
	ld  [$C471],a

	ld  a,[$D782]
	ld  [$D785],a

	jp  .LAB_4357


.LAB_4156:
	ld  a,[$C57F]
	set 0,a
	set 1,a
	ld  [$C57F],a

	jp  .LAB_426F


.LAB_4163:
	ld  a,[$D06B]
	cp  $02
	jr  z,.LAB_416D

	jp  .LAB_4357


.LAB_416D:
	ld  a,[$C588]
	cp  b
	jp  z,.LAB_4357

	call FUN_4388

	ld  a,b
	ld  [$D700],a
	cp  $F3
	jr  nz,.LAB_41A1

	ld  a,[$C46B]
	cp  $07
	jr  z,.LAB_4194
	
	ld  a,$FF
	ld  [$C470],a

	ld  a,[$D786]
	ld  [$D787],a

	jp  .LAB_4357


.LAB_4194:
	ld  a,[$C57F]
	set 0,a
	res 1,a
	ld  [$C57F],a

	jp  .LAB_426F


.LAB_41A1:
	cp  $FA
	jr  nz,.LAB_41C7

	ld  a,[$C46B]
	cp  $02
	jr  z,.LAB_41BA

	ld  a,$FF
	ld  [$C470],a

	ld  a,[$D786]
	ld  [$D787],a

	jp  .LAB_4357


.LAB_41BA:
	ld  a,[$C57F]
	set 0,a
	res 1,a
	ld  [$C57F],a

	jp  .LAB_42A4


.LAB_41C7:
	cp  $FB
	jr  nz,.LAB_41ED

	ld  a,[$C46B]
	cp  $03
	jr  z,.LAB_41E0

	ld  a,$FF
	ld  [$C470],a
	
	ld  a,[$D786]
	ld  [$D787],a

	jp .LAB_4357


.LAB_41E0:
	ld  a,[$C57F]
	set 0,a
	res 1,a
	ld  [$C57F],a

	jp  .LAB_42C3


.LAB_41ED:
	cp  $FC
	jr  nz,.LAB_4213

	ld  a,[$C46B]
	cp  $04
	jr  z,.LAB_4206

	ld  a,$FF
	ld  [$C470],a
	
	ld  a,[$D786]
	ld  [$D787],a

	jp .LAB_4357


.LAB_4206:
	ld  a,[$C57F]
	set 0,a
	res 1,a
	ld  [$C57F],a

	jp  .LAB_4301


.LAB_4213:
	cp  $E1
	jr  nz,.LAB_4239

	ld  a,[$C46B]
	cp  $06
	jr  z,.LAB_422C

	ld  a,$FF
	ld  [$C470],a
	
	ld  a,[$D786]
	ld  [$D787],a

	jp .LAB_4357


.LAB_422C:
	ld  a,[$C57F]
	set 0,a
	res 1,a
	ld  [$C57F],a

	jp  .LAB_4320


.LAB_4239:
	cp  $DD
	jr  nz,.LAB_425F

	ld  a,[$C46B]
	cp  $05
	jr  z,.LAB_4252

	ld  a,$FF
	ld  [$C470],a
	
	ld  a,[$D786]
	ld  [$D787],a

	jp .LAB_4357


.LAB_4252:
	ld  a,[$C57F]
	set 0,a
	res 1,a
	ld  [$C57F],a

	jp  .LAB_42E2


.LAB_425F:
	ld  a,$FF
	ld  [$C470],a

	jp  .LAB_4357


	;;TODO:
	db $3E, $FF, $EA, $70, $C4, $C3, $57, $43


.LAB_426F:
	ld  a,$69
	call FUN_1278

	ld  a,$00
	ld  [$C55D],a

	ld  a,$01
	ld  [$C58A],a

	di 

	ld  hl,$717D
	ld  b,2
	rst $10

	ld  a,[$CC44]
	bit 7,a
	jr  z,.LAB_4292

	ld  hl,$6CD1
	ld  b,96
	rst $10

.LAB_4292:
	ei 
	
	ld  hl,$C5DB
	ld  a,$05
	ld  [hl+],a
	ld  a,$02
	ld  [hl+],a
	ld  a,$05
	ld  [$C581],a

	jp  .LAB_433F


.LAB_42A4:
	ld  a,$69
	call FUN_1278

	ld  a,$00
	ld  [$C55D],a

	ld  a,$01
	ld  [$C58A],a
	
	ld  hl,$C5DB
	ld  a,$05
	ld  [hl+],a
	ld  a,$02
	ld  [hl+],a
	ld  a,$02
	ld  [$C581],a

	jr  .LAB_433F


.LAB_42C3:
	ld  a,$69
	call FUN_1278

	ld  a,$00
	ld  [$C55D],a

	ld  a,$01
	ld  [$C58A],a
	
	ld  hl,$C5DB
	ld  a,$05
	ld  [hl+],a
	ld  a,$03
	ld  [hl+],a
	ld  a,$03
	ld  [$C581],a

	jr  .LAB_433F


.LAB_42E2:
	ld  a,$69
	call FUN_1278

	ld  a,$00
	ld  [$C55D],a

	ld  a,$01
	ld  [$C58A],a
	
	ld  hl,$C5DB
	ld  a,$05
	ld  [hl+],a
	ld  a,$07
	ld  [hl+],a
	ld  a,$08
	ld  [$C581],a

	jr  .LAB_433F


.LAB_4301:
	ld  a,$69
	call FUN_1278

	ld  a,$00
	ld  [$C55D],a

	ld  a,$01
	ld  [$C58A],a
	
	ld  hl,$C5DB
	ld  a,$05
	ld  [hl+],a
	ld  a,$04
	ld  [hl+],a
	ld  a,$04
	ld  [$C581],a

	jr  .LAB_433F


.LAB_4320:
	ld  a,$69
	call FUN_1278

	ld  a,$00
	ld  [$C55D],a

	ld  a,$02
	ld  [$C58A],a
	
	ld  hl,$C5DB
	ld  a,$05
	ld  [hl+],a
	ld  a,$06
	ld  [hl+],a
	ld  a,$06
	ld  [$C581],a

	jr  .LAB_433F


.LAB_433F:
	xor a
	ld  [$C5DD],a
	ld  [$C5DE],a
	ld  [$C582],a
	ld  [$C583],a
	ld  [$C58B],a
	
	ld  a,$01
	ld  [$C5DF],a

	call FUN_ROM27_4362

.LAB_4357:
	ld  a,$03
	ld  [$C580],a

	ld  a,$F8
	call FUN_08BA

	ret