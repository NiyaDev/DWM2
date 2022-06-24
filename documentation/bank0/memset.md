# memset()
Sets the value of multiple designated memory locations.

## Code
```
memset :: proc(A: value, BC: counter, HL: ptr) {
	for i:=counter; i!=0; i-=1 {
		[ptr] = value;
		
		ptr += 1;
	}
}
```