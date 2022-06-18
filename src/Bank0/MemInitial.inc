
SECTION "MemInit", ROM0[$08D0]


;; MemInitialization ()
;; Initializes various parts of both console RAM and Cart RAM
MemInitialization:
	ld  a,[IsGBC]          ;; 
	or  a                  ;; 
	jr  z,.Skip            ;; if IsGBC == false, skip

	xor a                  ;; 
	ldh [rVBK],a           ;; 
	ldh [rSVBK],a          ;; 
	ldh [rHDMA1],a         ;; 
	ldh [rHDMA2],a         ;; 
	ldh [rHDMA3],a         ;; 
	ldh [rHDMA4],a         ;; 
	ldh [rHDMA5],a         ;; 
	ldh [rBCPS],a          ;; 
	ldh [rOCPS],a          ;; 
	ld  a,[IsGBC]          ;; 

.Skip:
	push af                ;;
	ld  hl,$C000           ;; =Pointer    ;; 
	ld  bc,$1E00           ;; =Counter    ;; Clears memory at
	ld  a,$00              ;; =Value      ;;  0xC000-0xDE00
	call Memset            ;; =Memset()   ;;      (RAM)

	ld  hl,$FF8A           ;; =Pointer    ;; 
	ld  bc,$0074           ;; =Counter    ;; Clears memory at
	ld  a,$0               ;; =Value      ;;  0xFF8A-0xFFFE
	call Memset            ;; =Memset()   ;;      (RAM)
	pop af                 ;;

	ld  [IsGBC], a         ;;

	ld  a,$0A              ;;
	ld  [rRAMG],a          ;; Enables writing to Cart RAM
	ld  a,$02              ;;
	ld  [rRAMB],a          ;; Selects cart RAM bank 2

	xor a                  ;; =Value      ;;
	ld  hl,$A000           ;; =Pointer    ;; Clears memory at
	ld  bc,$2000           ;; =Counter    ;;  0xA000-0xC000
	call Memset            ;; =Memset()   ;;   (RAM Bank2)

	ld  a,$00              ;;
	ld  [rRAMB],a          ;; Selects Cart RAM bank 0

	xor a                  ;; =Value      ;;
	ld  hl,$A000           ;; =Pointer    ;; Clears memory at
	ld  bc,$2000           ;; =Counter    ;;  0xA000-0xC000
	call Memset            ;; =Memset()   ;;   (RAM Bank0)

	ld  a,$00              ;;
	ld  [rRAMG],a          ;; Disable writing to Cart RAM
	ret