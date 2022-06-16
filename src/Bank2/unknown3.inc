
SECTION "Unknown3", ROMX[$42FA], BANK[2]


;; Unknown3 ()
;; 
Unknown3:
	ld  a,[IsGBC]            ;;
	or  a                    ;;
	ret z                    ;; if IsGBC == 0, return

	ld  hl,$C49F             ;;
	ld  de,$4322             ;;
	ld  bc,$0008             ;;
	call CopyData            ;; =CopyData ($8, $4322, $C49F)

	ld  a,$7F                ;;
	ld  [$C526],a            ;;

	ld  hl,$C4DF             ;;
	ld  de,$4322             ;;
	ld  bc,$0008             ;;
	call CopyData            ;; =CopyData ($8, $4322, $C4DF)

	ld  a,$7F                ;;
	ld  [$C527],a            ;;

	ret