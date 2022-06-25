# FUN_095B()
Loads [$C5E8] and uses it to get a value out of ROM for [$C5E7].
## Code
```
FUN_095B :: proc() {
	{ HL
        A       = ([$C5E8] + 1) & $7F;
        [$C5E8] = A;
		
		HL      = $0973 + A;

        [$C5E7] = [HL];
    }
}
```
## Variables
##### Software
- [$C5E8](variables/software/C5E8.md) [W]
- [$C5E7](variables/software/C5E7.md) [W]