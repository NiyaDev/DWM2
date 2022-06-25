# FUN_42FA()

## Code
```
FUN_ROM2_42FA :: proc() {
	if ![IsGBC] do return;
	
	copy_data($8, $4322, $C49F);
	
	[$C526] = $7F;
	
	copy_data($8, $4322, $C4DF);
	
	[$C527] = $7F;
}
```
## Functions
- [copy_data()](bank0/copy_data.md)
## Variables
##### Software
- [$4322](variables/software/4322.md) [R]
- [IsGBC](variables/software/C525.md) [R]
- [$C49F](variables/software/C49F.md) [W]
- [$C4DF](variables/software/C4DF.md) [W]
- [$C526](variables/software/C526.md) [W]
- [$C527](variables/software/C527.md) [W]