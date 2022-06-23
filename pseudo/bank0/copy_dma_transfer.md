# copy_dma_transfer()
Copies DMA transfer function from ROM to beginning of high-memory.

## Code
```
copy_dma_transfer :: proc() {
	C  = $80;   // Beginning of DMATransfer
	HL = $008E;
	
	for i:=10; i!=0; i-=1 {
		[$FF00+C] = [HL+];
		
		C += 1;
	}
}

ROMDMA: db  $3E, $C0, $E0, $46, $3E, $28, $3D, $20, $FD, $C9;
```
## Variables
##### Software
- [DMATransfer](variables.md#FF80-FF89)