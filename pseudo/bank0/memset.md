# memset()
Sets the value of multiple designated memory locations.

## Code
```
memset :: proc(A: value, BC: counter, HL: ptr) {
	for counter != 0 {
		[ptr] = value;
		
		pointer += 1;
		counter -= 1;
	}
}
```