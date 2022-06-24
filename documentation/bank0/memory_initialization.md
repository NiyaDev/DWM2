# memory_initialization()
Clears the Work RAM and High-RAM as well was Bank 0 and 2 of the cartridge RAM.

## Code
```
memory_initialization :: proc() {
	if ![IsGBC] {
		[rVBK]   = 0;
        [rSVBK]  = 0;
        [rHDMA1] = 0;
        [rHDMA2] = 0;
        [rHDMA3] = 0;
        [rHDMA4] = 0;
        [rHDMA5] = 0;
        [rBCPS]  = 0;
        [rOCPS]  = 0;
	}
	
	memset(0, 7680, $C000);
	memset(0, 116,  $FF84);
	
	[rRAMG] = $0A;
    [rRAMB] = 2;

    memset(0, $2000, $A000);
    [rRAMB] = 0;
    memset(0, $2000, $A000);
	
    [rRAMG] = 0;
}
```

## Functions
- [memset(value, counter, ptr)](bank0/memset.md)
## Variables
##### Hardware
- [rVBK](variables/hardware/rVBK.md)
- [rSVBK](variables/hardware/rSVBK.md)
- [rHDMA1](variables/hardware/VRAMDMA.md#rHDMA1($FF51))
- [rHDMA2](variables/hardware/VRAMDMA.md#rHDMA2($FF52))
- [rHDMA3](variables/hardware/VRAMDMA.md#rHDMA3($FF53))
- [rHDMA4](variables/hardware/VRAMDMA.md#rHDMA4($FF54))
- [rHDMA5](variables/hardware/VRAMDMA.md#rHDMA5($FF55))
- [rBCPS](variables/hardware/Palettes.md#rBCPS($FF68))
- [rOCPS](variables/hardware/Palettes.md#rOCPS($FF6A))
- [rRAMG](variables/hardware/MBC5.md#rRAMG($0100))
- [rRAMB](variables/hardware/MBC5.md#rRAMB($4100))
##### Software
- [IsGBC](variables/software/C525.md)