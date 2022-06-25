# FUN_077A()

## Code
```
FUN_077A :: proc(A: flags) {
	{ AF
		if [$C58A] != 0 do FUN_14D1();
		
		FUN_07AA();
	}
	
	set_enabled_interrupts(flags);
	
	ei();
}
```
## Functions
- [FUN_07AA()](bank0/FUN_07AA.md)
- [set_enabled_interrupts()](bank0/set_enabled_interrupts.md)
- [FUN_14D1()](bank0/FUN_14D1.md)
## Variables
##### Software
- [$C58A](variables/software/C58A.md) [R]