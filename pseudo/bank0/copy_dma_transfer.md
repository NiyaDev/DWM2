# copy_dma_transfer()
Copies DMA transfer function from ROM to beginning of high-memory.

## Code
```
copy_dma_transfer :: proc() {
	C  = $80;   // Beginning of DMATransfer
	B  = $0A;
	HL = $008E;
	
	for B != 0 {
		[$FF00+C] = [HL];
		
		HL += 1;
		C  += 1;
		B  -+ 1;
	}
}

ROMDMA: db  $3E, $C0, $E0, $46, $3E, $28, $3D, $20, $FD, $C9;
```
## Variables
##### Software
- [DMATransfer](variables.md#FF80-FF89)