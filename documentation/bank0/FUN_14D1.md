# FUN_14D1()
Has to do with Serial
## Code
```
FUN_14D1 :: proc() {

	if [$C58A] != 0 {
		
		// Joypad only
		set_enabled_interrupts(%00001000);
		
		[$C57F] = ([$C580] & %10111111) | %10000000;
		
		// Spend time looping
		if [$C57F] & 2 != 2 {
			for i:=$6000; i!=0; i-=1 {}
		}
		
		ei();
		
		if [$C581] == 5 {
		
			FUN_15C2();
			FUN_07D1();
			
			if [rSB] != $F5 do FUN_15C2();
			
		} else {
		
			if FUN_1583() != 2 do FUN_07D1();
			
			if [rSB] != $70 && [rSB] != $71 do B = FUN_1583();
			
			if [$C581] != $05 {
				if [$C57F] & 2 != 2 {
					if [IsGBC] == 0 && B & 1 != 0 {
						[$C57F] = [$C57F] | 2;
					}
				} else if [IsGBC] != 0 && B & 1 != 0 {
					[$C57F] = [$C57F] & 2;
				}
			}
		}
		di();
		
		[$C580] = [$C580] & %01111100;
		
		if [$C57F] & 2 != 2 do FUN_08BA($F8);
	}
	[$C582] = 0;
	
	// Clear $C55E-$C56C
	HL = $C55E;
	for i:=14; i!=0; i-=1 {
		[HL] = 0;
		HL  += 1;
	}
}
```
## Functions
- [set_enabled_interrupts()](bank0/set_enabled_interrupts.md)
- [FUN_07D1()](bank0/FUN_07D1.md)
- [FUN_08BA()](bank0/FUN_08BA.md)
- [FUN_1583()](bank0/FUN_1583.md)
- [FUN_15C2()](bank0/FUN_15C2.md)
## Variables
##### Hardware
- [rSB](variables/hardware/Serial.md#rSB($FF01)) [R]
##### Software
- [IsGBC](variables/software/IsGBC.md) [R]
- [$C57F](variables/software/C57F.md) [R/W]
- [$C580](variables/software/C580.md) [R/W]
- [$C581](variables/software/C581.md) [R]
- [$C582](variables/software/C582.md) [W]
- [$C58A](variables/software/C58A.md) [R]
- [$C55E](variables/software/C55E.md) [W]