

SECTION "Header", ROM0[$0100]

EntryPoint:
	nop
	jp  Start

Start:
	jp Start

SECTION "End", ROMX[$7FFF], BANK[255]
	db  $00