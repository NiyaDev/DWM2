# ???()

## Code
```
intr_vblank :: proc() {
	di();
	
	jmp FUN_03A4;
}

intr_stat :: proc() {
	jmp FUN_256A;
}

intr_serial :: proc() {
	jmp FUN_255B;
}
```
## Functions
- [FUN_03A4()](bank0/FUN_03A4.md)
- [FUN_256A()](bank0/FUN_256A.md)
- [FUN_255B()](bank0/FUN_255B.md)