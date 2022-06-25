# wait_1750_x()
loops a number of input times taking ~.015 seconds each loop.
## Code
```
wait_1750_x :: proc(BC: counter) {
	if ![$C524] do return;
	
	for i:=BC; i!=0; i-=1 {
		for i:=1750; i!=0; i-=1 {
			// Skip 36 cycles
		}
	}
}
```
## Variables
##### Software
- [$C524](variables/software/C524.md) [R]