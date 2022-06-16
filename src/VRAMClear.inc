
SECTION "VRAMClear", ROM0[$0930]


;; VRAMClear ()
;; Clears $9800-$9FFF (VRAM) on GB
;;     or $9800-$9BFF (VRAM) on GBC
VRAMClear:
	ld  hl,$9800           ;; =Pointer    ;; Clears memory at
	ld  bc,$0800           ;; =Counter    ;; $9800-$9FFF (VRAM)
	ld  a,[$D066]          ;; =Value      ;; set to $00
	or  a                  ;;
	jr  z,.skip            ;; if $D066 == 0, change input
	xor a                  ;;
	ld  [$D066],a          ;;
	ld  bc,$0400           ;; =Counter    ;; $9800-$9BFF (VRAM)
	ld  a,$C3              ;; =Value      ;; set to $C3

.skip:
	call Memset            ;; =Memset()   ;;
	ret