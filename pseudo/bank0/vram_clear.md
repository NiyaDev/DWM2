# vram_clear()
Clears the VRAM at \$9800-\$9FFF on GB or \$9800-\$9BFF on GBC
## Code
```
vram_clear :: proc() {
	if [$D066] == 0 {
		memset(  0, 2048, $9800);
	} else {
		[$D066] = 0;
		memset(195, 1024, $9800);
	}
}
```
## Functions
- [memset(value, counter, ptr)](bank0/memset.md)
## Variables
##### Software
- [$D066](variables.md#D066)