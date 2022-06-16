
SECTION "Memset", ROM0[$0949]


;; Memset (A: value, BC: counter, HL: pointer)
;; Sets memory at pointer HL to Value a BC times
Memset:
	ld  d,a                ;;

.loop:
	ld  [hl],d             ;;
	inc hl                 ;;
	dec bc                 ;;
	ld  a,b                ;;
	or  c                  ;;
	jr  nz,.loop           ;; if bc != 0, loop
	ret