
SECTION "memcpy", ROM0[$1679]

;; Copies DE:src to HL:dest
;; Input - BC:count DE:src HL:dest
memcpy:
	;; Copy [DE] to [HL]
	ld  a,[de]
	inc de
	ld  [hl+],a
	
	dec bc
	ld  a,b
	or  c
	jr  nz,memcpy

	ret