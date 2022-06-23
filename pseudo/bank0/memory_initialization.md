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
- [rVBK](variables#FF4F)
- [rSVBK](variables#FF70)
- [rHDMA1](variables#FF51-FF55)
- [rHDMA2](variables#FF51-FF55)
- [rHDMA3](variables#FF51-FF55)
- [rHDMA4](variables#FF51-FF55)
- [rHDMA5](variables#FF51-FF55)
- [rBCPS](variables#FF68-FF69)
- [rOCPS](variables#FF68-FF69)
- [rRAMG](variables#MBC5)
- [rRAMB](variables#MBC5)
##### Software
- [IsGBC](variables#C525)