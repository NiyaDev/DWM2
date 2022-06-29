# stat_interrupt()

## Code
```
stat_interrupt :: proc() {
	stor1 = [rSVBK];
	
	[rSVBK] = 0;
	
	// Scroll X/Y by a value at $C0F0-C17F
	// If in hblank, scroll == [$FFA1] and (maybe) interrupts at rLY == 0
	// if not, add 2 to rLYC 
	#partial switch [$C5E1] {
		case 3:
			[rSCX] = [$C0F0 + [rLY]];
			
			if [rLYC] + 2 >= $90 {
				[rSCX] = [$FFA1];
				[rLYC] = 0;
			} else do [rLYC] = [rLYC] + 2;
			break;
		case 4:
			[rSCY] = [$C0F0 + [rLY]];
			
			if [rLYC] + 2 >= $81 {
				[rSCY] = [$FFA5];
				[rLYC] = 0;
			} else do [rLYC] = [rLYC] + 2;
			break;
	}
	
	[rSVBK] = stor1;
	ei();
}
```
## Variables
##### Hardware
- [rSVBK](variables/hardware/rSVBK.md) [W]
- [rSCY](variables/hardware/LCDC.md#rSCY($FF42)) [W]
- [rSCX](variables/hardware/LCDC.md#rSCX($FF43)) [W]
- [rLY](variables/hardware/LCDC.md#rLY($FF44) [R]
- [rLYC](variables/hardware/LCDC.md#rLYC($FF45)) [R/W]
##### Software
- [$C5E1](variables/software/C5E1.md) [R]
- [$FFA1](variables/software/FFA1.md) [R]
- [$FFA5](variables/software/FFA5.md) [R]