
SECTION "start_child_serial", ROM0[$08BA]

;; Initializes child serial transfer
;; Input A:input
start_child_serial: ;;08BA
	di

	call set_transfer_data

	;; Sets serial clock to internal and requests transfer
	ld  hl,rSC
	res 0,[hl]
	set 7,[hl]

	ei
	ret