# clear_8_hram()
Clears 8 memory locations in high RAM.
## Code
```
clear_8_hram :: proc() {
    clear_4_hram(0, $FFA1);
    clear_4_hram(0, $FFA5);
}

clear_4_hram :: proc(A: val, HL: ptr) {
    [HL+0] = val;
    [HL+1] = val;
    [HL+2] = val;
    [HL+3] = val;
}
```
## Variables
##### Software
- [\$FFA1-\$FFA9](variables/software/FFA1.md) [W]