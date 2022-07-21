
SECTION "0BCC", ROM0[$0BCC]

;; Copies data from UNK_C0C4 and UNK_C0DC into wherever [UNK_C0C0] and [UNK_C0D8] point to respectively.
FUN_0BCC: ;;0BCC
	;; Loads [UNK_C0C0] into DE
	ld  a,[UNK_C0C0]
	ld  e,a
	ld  a,[UNK_C0C1]
	ld  d,a

	;; If [UNK_C0C0] == 0, return
	ld  a,d
	or  e
	jr  nz,.continue

	ret


.continue:
	ld  a,[UNK_C0C3]
	ld  b,a

	ld  hl,UNK_C0C4

	;; If [UNK_C0C2] == 0, jump
	ld  a,[UNK_C0C2]
	or  a
	jr  nz,.LAB_0BF7

	;; C = E & $E0
	ld  a,e
	and $E0
	ld  c,a

.LAB_0BEA:
	;; Copy HL into DE
	ld  a,[hl+]
	ld  [de],a
	inc e

	;; E = (E & $1F) | C
	ld  a,e
	and $1F
	or  c
	ld  e,a

	;; Loop while B != 0
	dec b
	jr  nz,.LAB_0BEA

	jr  .LAB_0C05


.LAB_0BF7:
	;; Copy HL into DE
	ld  a,[hl+]
	ld  [de],a

	;; E = E + 32
	ld  a,$20
	add e
	ld  e,a

	;; If E < 255, jump
	jr  nc,.LAB_0C00

	;; Increment D to carry
	inc d

.LAB_0C00:
	res 2,d

	;; Loop while B != 0
	dec b
	jr  nz,.LAB_0BF7

.LAB_0C05:
	;; Clear
	xor a
	ld [UNK_C0C0],a
	ld [UNK_C0C1],a

	;; Leave if DMG
	ld  a,[IsGBC]
	or  a
	ret z

	;; Open VRAM bank 1
	ld  a,1
	ldh [rVBK],a

	;; Load [UNK_C0D8] into DE
	ld  a,[UNK_C0D8]
	ld  e,a
	ld  a,[UNK_C0D9]
	ld  d,a

	;; If [UNK_C0D8] == 0, return
	ld  a,d
	or  e
	jr  nz,.LAB_0C22

	ret


.LAB_0C22:
	ld  a,[UNK_C0DB]
	ld  b,a

	ld  hl,UNK_C0DC

	;; If [UNK_C0DA] != 0, jump
	ld  a,[UNK_C0DA]
	or  a
	jr  nz,.LAB_0C40

	;; C = E & $E0
	ld  a,e
	AND $E0
	ld  c,a

.LAB_0C33:
	;; Copy HL into DE
	ld  a,[hl+]
	ld  [de],a
	inc e
	
	;; E = (E & $1F) | C
	ld  a,e
	and $1F
	or  c
	ld  e,a

	;; Loop while B != 0
	dec b
	jr  nz,.LAB_0C33

	jr  .LAB_0C4E


.LAB_0C40:
	;; Copy HL into DE
	ld  a,[hl+]
	ld  [de],a
	
	;; E = E + 32
	ld  a,$20
	add e
	ld  e,a

	;; If E < 255, jump
	jr  nc,.LAB_0C49

	;; Carry
	inc d

.LAB_0C49:
	res 2,d

	;; Loop while B != 0
	dec b
	jr  nz,.LAB_0C40

.LAB_0C4E:
	;; Reset VRAM bank
	ld  a,0
	ldh [rVBK],a

	;; Clear 
	xor a
	ld  [UNK_C0D8],a
	ld  [UNK_C0D9],a

	ret