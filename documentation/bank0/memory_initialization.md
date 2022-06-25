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
	
	memset(0, $1E00, $C000);
	memset(0, $0074, $FF84);
	
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
- [rVBK](variables/hardware/rVBK.md) [W]
- [rSVBK](variables/hardware/rSVBK.md) [W]
- [rHDMA1](variables/hardware/VRAMDMA.md#rHDMA1($FF51)) [W]
- [rHDMA2](variables/hardware/VRAMDMA.md#rHDMA2($FF52)) [W]
- [rHDMA3](variables/hardware/VRAMDMA.md#rHDMA3($FF53)) [W]
- [rHDMA4](variables/hardware/VRAMDMA.md#rHDMA4($FF54)) [W]
- [rHDMA5](variables/hardware/VRAMDMA.md#rHDMA5($FF55)) [W]
- [rBCPS](variables/hardware/Palettes.md#rBCPS($FF68)) [W]
- [rOCPS](variables/hardware/Palettes.md#rOCPS($FF6A)) [W]
- [rRAMG](variables/hardware/MBC5.md#rRAMG($0100)) [W]
- [rRAMB](variables/hardware/MBC5.md#rRAMB($4100)) [W]
##### Software
- [IsGBC](variables/software/IsGBC.md) [R]
- [$C000](variables/software/C000.md) [W]
- [$A000](variables/software/A000.md) [W]
- [$FF84](variables/software/FF84.md) [W]