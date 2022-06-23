# Reset Vectors
RST00 jumps to a position located at offset away from where reset was called
RST10 jumps to a function in a designated ROM bank.
## Code
```
RST00 :: proc(A: offset, ST: base) {
	HL = base + offset << 1;
	
	HL = [HL];
	
	jump HL();
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
- [rRAMB](variables.md#MBC5)
- [rROMB0](variables.md#MBC5)