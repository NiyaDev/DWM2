# FUN_048A

## Code
```
FUN_048A :: proc() {
	if [$C5DF] == 0 do return;
	
	if [$C58A] == 0 && [$C56C] != 0 {
		if [$C56C] & $80 == 0 do return;
	}
	
	switch [$C5DB] {
		case 0:
			FUN_ROM1_4AD4();
			return;
		case 1:
			FUN_ROM2_4AD8();
			return;
		case 2:
			FUN_ROM3_4015();
			return;
		case 3:
			return;
		case 4:
			FUN_ROM49_40A5();
			return;
		case 5:
			FUN_ROM7_4F7B();
			return;
		case 6:
			FUN_ROM24_4117();
			return;
		case 7:
			FUN_ROM160_4F70();
			return;
		case 8:
			FUN_ROM242_40A2();
			return;
	}
}
```
## Functions
- [FUN_ROM1_4AD4()](bank1/FUN_4AD4.md)
- [FUN_ROM2_4AD8()](bank2/FUN4AD8.md)
- [FUN_ROM3_4015()](bank3/FUN_4015.md)
- [FUN_ROM49_40A5()](bank49/FUN_40A5.md)
- [FUN_ROM7_4F7B()](bank7/FUN_4F7B.md)
- [FUN_ROM24_4117()](bank42/FUN_4117.md)
- [FUN_ROM160_4F70()](bank160/FUN_4F70.md)
- [FUN_ROM242_40A2()](bank242/FUN_40A2.md)
## Variables
##### Software
- [$C56C](variables/software/.md) [R]
- [$C58A](variables/software/.md) [R]
- [$C5DB](variables/software/.md) [R]
- [$C5DF](variables/software/.md) [R]