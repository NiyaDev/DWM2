
# set_interrupts()

Sets which interrupts are enabled then waits for LY == 91 and disables LCD.

```
set_interrupts :: proc() {
	[rIF]  = 0;
	[rIF] &= $E2;
	
	disable_lcd();
}

disable_lcd :: proc() {
	if bit(7, [$FF40]) == 0 do return;
	
	for [rLY] != 0 {}
	
	reset(7, [$FF40]);
	reset(7, [$C5EC]);
}
```