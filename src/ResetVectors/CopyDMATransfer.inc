
;; Copies DMA transfer function from 0x008E to high memory
DEF DMAFunction    EQU  $80
DEF DMATransfer    EQU  $FF80


SECTION "CopyDMATransfer", ROM0[$0080]


;; CopyDMATransfer ()
CopyDMATransfer:
	ld  c,DMAFunction      ;;
	ld  b,10               ;;
	ld  hl,ROMDMA          ;;

.loop:
	ld  a,[hl+]            ;;
	ldh [c],a              ;; Copies from ROMDMA to DMAFunction
	inc c                  ;;
	dec b                  ;;
	jr  nz,.loop           ;; Loops 10 times
	ret


;; DMA copy proc
ROMDMA:
	db  $3E, $C0, $E0, $46, $3E, $28, $3D, $20, $FD, $C9