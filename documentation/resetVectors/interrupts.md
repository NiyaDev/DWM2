# ???()

## Code
```
intr_vblank :: proc() {
	di();
	
	jmp FUN_03A4;
}

intr_stat :: proc() {
	jmp stat_interrupt;
}

intr_serial :: proc() {
	jmp FUN_255B;
}
```
## Functions
- [FUN_03A4()](bank0/FUN_03A4.md)
- [stat_interrupt](bank0/stat_interrupt.md)
- [FUN_255B()](bank0/FUN_255B.md)