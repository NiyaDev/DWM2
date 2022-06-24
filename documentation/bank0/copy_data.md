# copy_data()
Copies data from src to dest.
## Code
```
copy_data :: proc(BC: counter, DE: src, HL: dest) {
	for i:=counter; i!=0; i-=1 {
		[HL] = [DE];
		
		HL += 1;
		DE += 1;
	}
}
```