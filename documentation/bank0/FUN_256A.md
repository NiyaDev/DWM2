# FUN_256A()
This doesn't seem to really do anything except re-enable interrupts.
## Code
```
FUN_256A :: proc() {
	bank = [rSVBK];
	rst00([$C5E1] & 3, $257A);
	[rSVBK] = bank;
	ei();
}
```
## Functions
- [rst00()](resetVectors/reset.md)
## Variables
##### Hardware
- [rSVBK](variables/hardware/rSVBK.md)
##### Software
- [$C5E1](variables/software/C5E1.md)