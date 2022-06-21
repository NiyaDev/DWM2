	
SECTION "FUN_0B7F", ROM0[$0B7F]


;; Sets three bytes in seperate locations to $D2,$D2,$E2
FUN_0B7F:
	ld  hl,$C5E9             ;;
	ld  a,$D2                ;;
	ld  [hl+],a              ;;

	ld  a,$D2                ;;
	ld  [hl+],a              ;;

	ld  a,$E2                ;;
	ld  [hl+],a              ;;

	ld  hl,$D040             ;;
	ld  a,[$C5E9]            ;;
	ld  [hl+],a              ;;

	ld  a,[$C5EA]            ;;
	ld  [hl+],a              ;;

	ld  a,[$C5AB]            ;;
	ld  [hl],a               ;;
	ret