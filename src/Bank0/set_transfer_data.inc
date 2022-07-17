
SECTION "set_transfer_data", ROM0[$08C7]

;; Resets serial control and sets input data
;; Input A:input
set_transfer_data: ;;08C7

	ld  b,a

	;; Turns off transfer, sets clock speed to external and normal speed (speed only in GBC)
	ld  a,0
	ldh [rSC],a

	;; Sets data to be transfered to input
	ld  a,b
	ldh [rSB],a

	ret