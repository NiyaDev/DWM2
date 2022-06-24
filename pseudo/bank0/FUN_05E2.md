# FUN_05E2()

## Code
```
FUN_05E2 :: proc() -> bool {

	[$C47C] = 11;
    FUN_ROM31_5040();
    wait_7000();

	// This is always true
	// When forced false it cause the game to load normally, but all transitions were disabled, making it possible to see the game loading in sprites.
    if [rP1] & 3 == 3 {
        [rP1] = P1F_GET_DPAD;
        [rP1] = P1F_GET_NONE;
        [rP1] = P1F_GET_BTN;
        [rP1] = P1F_GET_NONE;

        if [rP1] & 3 == 3 {
		
            [$C47C] = 10;
            FUN_ROM31_5040();
            wait_7000();

            return false;
        }
    }

    [$C47C] = 10;
    FUN_ROM31_5040();
    wait_7000();

    return true;
}
```
## Functions
- [FUN_ROM31_5040()](bank31/FUN_5040.md)
- [wait_7000()](bank0/wait_7000.md)
## Variables
##### Hardware
- [rP1](variables.md#FF00)
##### Software
- [$C47C](variables.md#C47C)