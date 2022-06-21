
SECTION "FUN_3290", ROM0[$3290]


;; Unknown1 ()
;; Preps audio then does some audio clearing
FUN_3290:          ;; $3290
	ld  bc,$0000           ;; 
	call FUN_32DB          ;; =FUN_32DB($00, $00)

	ld  a,$80              ;;                       ;;
	ldh [rNR52],a          ;; [rNR52] = 1000 0000   ;;
	xor a                  ;;                       ;;
	ldh [rNR51],a          ;; [rNR51] = 0000 0000   ;; Preping audio
	ld  [$DD09],a          ;;                       ;;
	ld  a,$77              ;;                       ;;
	ldh [rNR50],a          ;; [rNR50] = 0111 0111   ;;


	ld  hl,$DC00           ;;
	ld  de,$0020           ;; Preping first loop
	ld  b,$06              ;;
	ld  a,$FF              ;;
.loop1:
	ld  [hl+],a            ;;
	ld  [hl+],a            ;; Sets the first word every $20 bytes
	add hl,de              ;; in RAM starting at $DC00 to $FFFF
	dec b                  ;;
	jr  nz,.loop1          ;; if b != 0, loop


	ld  hl,$DCC0           ;;
	ld  b,$48              ;; Preping second loop
	xor a                  ;;
.loop2
	ld  [hl+],a            ;; Sets the memory from $DCC0 to $DD08 to $00
	dec b                  ;;
	jr  nz,.loop2          ;; if b !0 =, loop

	xor a                  ;;
	ld  [$DD15],a          ;; Sets two variables to $00
	ld  [$DD19],a          ;;
	ret



;---------------------------------- TODO:

SECTION "FUN_32C6", ROM0[$32C6]


;; FUN_32C6 ()
;; Sets a variable to $00 then sets another to a seperate variable
;; NOTE: This function hasn't been called
;;       It was found by disassembling between functions
FUN_32C6:        ;; $32C6
	xor a
	ld  [$DD15],a
	ld  a,[$DD16]
	ld  [$DD09],a
	ret



;---------------------------------- TODO:

SECTION "FUN_32D1", ROM0[$32D1]


;; FUN_32D1 ()
;; Sets one variable to $04 and another to $00
;; NOTE: This function hasn't been called
;;       It was found by disassembling between functions
FUN_32D1:        ;; $32D1
	ld  a,$04
	ld  [$DD15],a
	xor a
	ld  [$DD09],a
	ret



;---------------------------------- TODO:

SECTION "FUN_32DB", ROM0[$32DB]


;; FUN_32DB (B: val1, C: val2)
;; Sets a few values
FUN_32DB:          ;; $32DB
	ld  a,b                ;;
	ld  [$DD12],a          ;;
	ld  a,c                ;;
	ld  [$DD13],a          ;;
	xor a                  ;;
	ld  [$DD14],a          ;;
	ret