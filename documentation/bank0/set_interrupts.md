# set_interrupts()

Sets which interrupts are enabled then waits for LY == 91 and disables LCD.
Disable Trans, Serial, Timer, and V-Blank interrupts, but enable LCDC.

```
set_interrupts :: proc() {
	[rIF]  = 0;
	[rIF] &= $E2;
	
	disable_lcd();
}

disable_lcd :: proc() {
	if [rLCDC] & $80 == $80 do return;
	
	// Wait until rLY == 0
	for [rLY] != 0 {}
	
	[rLCDC] = [rLCDC] & $80;
	[$C5EC] = [$C5EC] & $80;
}
```
## Variables
##### Hardware
- [rIF](variables/hardware/rIF.md) [W]
- [rLCDC](variables/hardware/LCDC.md#rLCDC($FF40)) [R]
- [rLY](variables/hardware/LCDC.md#rLY($FF44)) [R]
##### Software
- [$C5EC](variables/software/C5EC.md) [W]