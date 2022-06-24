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
- [IsGBC](variables.md#C525)
- [$C49F](variables.md#C49F)
- [$C4DF](variables.md#C4DF)
- [$C526](variables.md#C526)
- [$C527](variables.md#C527)