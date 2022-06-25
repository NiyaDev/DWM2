# FUN_07AA()

## Code
```
FUN_07AA :: proc() {
	[$C5EC] += $80;
	[rLCDC]  = [$C5EC];
	
	if ![$C524] do return;
	
	[$C47C] = 1;
	FUN_ROM31_5040();
	wait_7000();
}
```
## Functions
- [FUN_ROM31_5040()](bank31/FUN_5040.md)
- [wait_7000()](bank0/wait_7000.md)
## Variables
##### Hardware
- [rLCDC](variables/hardware/LCDC.md#rLCDC($FF40)) [W]
##### Software
- [$C47C](variables/software/C47C.md) [W]
- [$C524](variables/software/C524.md) [R]
- [$C5EC](variables/software/C5EC.md) [W]