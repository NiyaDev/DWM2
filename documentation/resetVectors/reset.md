# Reset Vectors
RST00 jumps to a pointer located at offset * 2 ahead of return address.
RST10 jumps to a function in a designated ROM bank.
## Code
```
RST00 :: proc(A: offset, RETADR: base) {
	RETADR += offset * 2;
	
	jmp [RETADR];
}

RST10 :: proc(B: bank, HL: ptr) {
	A = [rRAMB]
	{ AF
		[rROMB0] = bank;
		jump ptr();
	}
	[rROMB0] = A;
}
```
## Variables
##### Hardware
- [rRAMB](variables/hardware/MBC5.md)
- [rROMB0](variables/hardware/MBC5.md)