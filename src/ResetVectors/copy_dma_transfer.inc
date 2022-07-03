
SECTION "CopyDMATransfer", ROM0[$0080]

;; Copies DMA transfer function to beginning of HRAM
CopyDMATransfer:
	;; Initializes loop
	ld  c,_HRAMSTART
	ld  b,10
	ld  hl,copy_dma
.loop:
	ld  a,[hl+]
	ldh [c],a
	inc c
	dec b
	jr  nz,.loop

	ret


;; DMA transfer
copy_dma:
	;; Start
	ld  a,$C0
	ldh [rDMA],a

	;; Delay 160 cycles
	ld  a,40
.wait:
	dec a
	jr  nz,.wait
	ret