
SECTION "Unknown2", ROM0[$0355]


;; Unknown2 ()
;; 
Unknown2:
	ld  a,[$C5DB]
	rst $00
	ld  l,e
	inc bc
	ld  [hl],d
	inc bc
	ld  a,c
	inc bc
	add b
	inc bc
	add c
	inc bc
	adc b
	inc bc
	adc a
	inc bc
	sub [hl]
	inc bc
	sbc l
	inc bc

	ld  hl,$4001
	ld  b,$01
	rst $10

	ret