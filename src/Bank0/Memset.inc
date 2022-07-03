
SECTION "Memset", ROM0[$0949]

;; Sets memory at pointer HL to Value A, BC times
memset:
	ld  d,a
.loop:
	;; Set value and increment ptr
	ld  [hl],d
	inc hl

	;; if bc != 0, loop
	dec bc
	ld  a,b
	or  c
	jr  nz,.loop
	ret