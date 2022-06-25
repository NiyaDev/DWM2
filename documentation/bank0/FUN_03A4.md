# FUN_03A4()

## Code
```
FUN_03A4 :: proc() {
	{ AF,BC,DE,HL
		
		B = [rSVBK];
		[rSVBK] = 0;
		
		{ BC
			A = [rVBK];
			
			{ AF
				if [$C5ED] & $01 != $01 {
					[$C5ED] = [$C5ED] | $01;
					DMATransfer();
					
					if [IsGBC] && [$C56C] == 0 && [$C526] | [$C527] != 0 {
						if [$C526] != 0 do FUN_0829();
						[$C526] = 0;
								
						if [$C527] != 0 do FUN_085C();
						[$C527] = 0;
					}
					
					FUN_0BCC();
					FUN_07FD();
					FUN_07E0();
					FUN_04ED();
					FUN_07F1();
					
					if [$C58A] == 0 {
						ei();
						
						FUN_0A17();
						FUN_0A8D();
						FUN_33E8();
						FUN_09F3();
						FUN_131A();
						FUN_0474();
						
						if [$C52B] != 0 do FUN_2620();
						
						FUN_0F4E();
						
						(Word)[$C5F0] += 1;
					} else {
						FUN_33E8();
					
						ei();
					
						FUN_131A();
						FUN_0474();
					}
					if [$C56C] == 0 {
						if [$C55E] == 0 {
							if [$C58A] == 0 do goto main.initialize;
						}
					}
					HL = $C5ED;
					[HL] = [HL] & $01;
				} else {
					FUN_07F1();
					FUN_33E8();
					
					ei();
				}
			}
			[rVBK]  = A;
			[$C5D7] = [rLY];
		} AF
		[rSVBK] = A;
	}
}
```
## Functions
- [DMATransfer()](bank0/copy_dma_transfer.md)
- [FUN_0474()](bank0/FUN_0474.md)
- [FUN_04ED()](bank0/FUN_04ED.md)
- [FUN_07E0()](bank0/FUN_07E0.md)
- [FUN_07F1()](bank0/FUN_07F1.md)
- [FUN_07FD()](bank0/FUN_07FD.md)
- [FUN_0829()](bank0/FUN_0829.md)
- [FUN_085C()](bank0/FUN_085C.md)
- [FUN_09F3()](bank0/FUN_09F3.md)
- [FUN_0A17()](bank0/FUN_0A17.md)
- [FUN_0A8D()](bank0/FUN_0A8D.md)
- [FUN_0BCC()](bank0/FUN_0BCC.md)
- [FUN_0F4E()](bank0/FUN_0F4E.md)
- [FUN_131A()](bank0/FUN_131A.md)
- [FUN_2620()](bank0/FUN_2620.md)
- [FUN_33E8()](bank0/FUN_33E8.md)
- [main().initialize](main.md)
## Variables
##### Hardware
- [rSVBK](variables/hardware/rSVBK.md) [R/W]
- [rVBK](variables/hardware/rVBK.md) [R/W]
##### Software
- [IsGBC](variables/software/IsGBC.md) [R]
- [$C526](variables/software/C526.md) [R/W]
- [$C527](variables/software/C527.md) [R/W]
- [$C52B](variables/software/C52B.md) [R]
- [$C55E](variables/software/C55E.md) [R]
- [$C56C](variables/software/C56C.md) [R]
- [$C58A](variables/software/C58A.md) [R]
- [$C5D7](variables/software/C5D7.md) [W]
- [$C5ED](variables/software/C5ED.md) [R/W]
- [$C5F0](variables/software/C5F0.md) [W]