
SECTION "isolate_offset", ROM0[$0897]

;; Takes input A and returns a multiple of 8 offset in HL
;; 0, 8, 16, 24, 32, 40, 48, 56
isolate_offset: ;;0897
	;; A = (A & %01111111) & %00111000
	res 7,a
	and $38
	ld  l,a
	ld  h,0

	ret