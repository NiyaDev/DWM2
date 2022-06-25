# clear_work_start()
Clears first 160 bytes of work RAM.
## Code
```
clear_work_start :: proc() {
	[$FFB1] = 0;
	
	HL = $C000;
	for i:=160; i!=0; i-=1 {
		[HL] = 0;
		HL  += 1;
	}
}
```
## Variables
##### Software
- [\$FFB1](variables/software/FFB1.md) [W]
- [\$C000-\$C0A0](variables/software/C000.md) [W]