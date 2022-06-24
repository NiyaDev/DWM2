
SECTION "CopyData", ROM0[$1679]


;; CopyData (BC: counter, DE: copy, HL: location)
;; Copies data from [DE] to [HL], BC times
CopyData:
	ld  a,[de]               ;;
	inc de                   ;;
	ld  [hl+],a              ;; move [de] into [hl]
	
	dec bc                   ;;
	ld  a,b                  ;;
	or  c                    ;;
	jr  nz,CopyData          ;; while bc != 0, loop
	ret