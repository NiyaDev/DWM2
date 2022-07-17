
SECTION "start_parent_serial", ROM0[$08AD]

;; Initializes parent serial transfer
;; Input A:input
start_parent_serial: ;;08AD
	di

	call set_transfer_data

	;; Sets serial clock to external and requests transfer
	ld  hl,rSC
	set 0,[hl]
	set 7,[hl]

	ei
	ret