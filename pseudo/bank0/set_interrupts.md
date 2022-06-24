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
	if bit(7, [rLCDC]) == 0 do return;
	
	for [rLY] != 0 {}
	
	reset(7, [rLCDC]);
	reset(7, [$C5EC]);
}
```
## Variables
##### Hardware
- [rIF](variables/hardware/rIF.md)
- [rLCDC](variables/hardware/LCDC.md#rLCDC($FF40))
- [rLY](variables/hardware/LCDC.md#rLY($FF44))
##### Software
- [$C5EC](variables/software/C5EC.md)