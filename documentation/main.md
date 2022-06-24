# main()
### Code
```
main :: proc() {
	
	if A == $11 do [IsGBC] = true;
	else        do [IsGBC] = false;
	
	di();
	SP = $DFFF;
	
	set_interrupts();
	memory_initialization();
	copy_dma_transfer();
	
	memset(0, 7168, $8000);
	
	if [IsGBC] {
		[rVBK] = 1;
		memset(0, 2048, $9800);
		[rVBK] = 0;
	}
	
	[$C5DB] = 5;
    [$C5DC] = 0;
    [$C5DD] = 0;
    [$C5DE] = 0;

    [rRAMB]  = 0;  //
    [rRAMG]  = 0;  // ROM Bank 1
    [rROMB0] = 1;  //  selected
    [rROMB1] = 0;  //

    [$C524] = 1;
    [$C60A] = 255;
    [$C60B] = 255;

    FUN_3290();

    [$C58C] = 0;
	
	if [IsGBC] {
		[rVBK]  = 0;
        [rSVBK] = 0;
        [rRP]   = 0;

        FUN_ROM2_42FA();
	} else {
		if FUN_05E2() {
			Wait1750_X(12);

            [$C47C] = 20;
            FUN_ROM31_5040();
            Wait7000();

            [$C47C] = 2;
            FUN_ROM31_5040();
            Wait7000();

            [$C47C] = 3;
            FUN_ROM31_5040();
            Wait7000();

            [$C47C] = 4;
            FUN_ROM31_5040();
            Wait7000();

            [$C47C] = 5;
            FUN_ROM31_5040();
            Wait7000();

            [$C47C] = 6;
            FUN_ROM31_5040();
            Wait7000();

            [$C47C] = 7;
            FUN_ROM31_5040();
            Wait7000();

            [$C47C] = 8;
            FUN_ROM31_5040();
            Wait7000();

            [$C47C] = 9;
            FUN_ROM31_5040();
            Wait7000();

            FUN_0705(12, 2048, $446C, 23);
            Wait7000();

            FUN_06A8($0D, $17, $44, $8C);
            Wait7000();

            [$C47C] = 18;
            FUN_ROM31_5040();
            Wait7000();

            [$C47C] = 10;
            FUN_ROM31_5040();
            Wait7000();

            [$C47C] = 19;
            FUN_ROM31_5040();
            Wait7000();

            [$C47C] = 14;
            FUN_ROM31_5040();
            Wait7000();

            [$C524] = 1;
            [$C523] = 255;
            [$C51F] = 0;
            [$C520] = 0;
		}
	}
	
	[$C524] = 0;
	
	ei();
	
	for {
		VRAMClear();
        clear_work_start();
        FUN_0B7F();
        FUN_0B9B();
        FUN_0DCA();
		
		[$C586] = 0;
        [$C52B] = 0;
        [$C52F] = 0;
        [$C530] = 0;
        FUN_0355();
		
		[$C5DF] = 0;
        [$C5E0] = 0;
        [$C5EE] = 0;
        [$C0C0] = 0;
        [$C0C1] = 0;
        [$C0D8] = 0;
        [$C0D9] = 0;
        [$C5ED] = 0;
        [$C5F0] = 0;
        [$C5F1] = 0;

        [$FFB9] = 0;
        [$FFB9] = 128;

        [$C58D] = 0;
        [$C58E] = 0;

        [$C604] = 0;
        [$C605] = 0;
        [$C606] = 0;
        [$C607] = 0;
		
		for [$C5DF] == 0 {
			if [$C58A] == 0 do FUN_095B();
			
			halt();

            if [$C5DF] == 0           do continue;
            if [$C56C] == 0           do break;
            if bit(7, [$C56C]) == 128 do continue;
            else                      do break;
		}
	}
}
```


## Functions
- [set_interrupts()](bank0/set_interrupts.md)
- [memory_initialization()](bank0/memory_initialization.md)
- [copy_dma_transfer()](bank0/copy_dma_transfer.md)
- [memset(value, counter, ptr)](bank0/memset.md)
- [wait_7000()](bank0/wait_7000.md)
- [wait_1750_X(counter)](wait_1750_x.md)
- [vram_clear()](bank0/vram_clear.md)
- [clear_work_start()](bank0/clear_work_start.md)
- [FUN_0355()](bank0/FUN_0355.md)
- [FUN_05E2()](bank0/FUN_05E2.md)
- [FUN_06A8($0D, $17, $44, $8C)](bank0/FUN_06A8.md)
- [FUN_0705(12, 2048, $446C, 23)](bank0/FUN_0705.md)
- [FUN_095B()](bank0/FUN_095B.md)
- [FUN_0B7F()](bank0/FUN_0B7F.md)
- [clear_8_hram()](bank0/clear_8_hram.md)
- [FUN_3290()](bank0/FUN_3290.md)
- [FUN_ROM2_42FA()](bank2/FUN_42FA.md)
- [FUN_ROM31_5040()](bank31/FUN_5040.md)

## Variables
##### Hardware
- [rP1](variables/hardware/rP1.md)
- [rIF](variables/hardware/rIF.md)
- [rNR50](variables/hardware/Sound.md#rAUDVOL/rNR50($FF24))
- [rNR51](variables/hardware/Sound.md#rAUDTERM/rNR51($FF25))
- [rNR52](variables/hardware/Sound.md#rAUDENA/rNR52($FF26))
- [rSCY](variables/hardware/LCDC.md#rSCY($FF42))
- [rSCX](variables/hardware/LCDC.md#rSCX($FF43))
- [rBGP](variables/hardware/LCDC.md#rBGP($FF47))
- [rVBK](variables/hardware/rVBK.md)
- [rRP](variables/hardware/rRP.md)
- [rSVBK](variables/hardware/rSVBK.md)
- [rRAMB](variables/hardware/MBC5.md)
- [rRAMG](variables/hardware/MBC5.md)
- [rROMB0](variables/hardware/MBC5.md)
- [rROMB1](variables/hardware/MBC5.md)
##### Software
- [IsGBC](variables/software/C525.md)
- [$C0C0](variables/software/C0C0.md)
- [$C0C1](variables/software/C0C1.md)
- [$C0D8](variables/software/C0D8.md)
- [$C0D9](variables/software/C0D9.md)
- [$C47C](variables/software/C47C.md)
- [$C51F](variables/software/C51F.md)
- [$C520](variables/software/C520.md)
- [$C523](variables/software/C523.md)
- [$C524](variables/software/C524.md)
- [$C52B](variables/software/C52B.md)
- [$C52F](variables/software/C52F.md)
- [$C530](variables/software/C530.md)
- [$C56C](variables/software/C56C.md)
- [$C586](variables/software/C586.md)
- [$C58A](variables/software/C58A.md)
- [$C58C](variables/software/C58C.md)
- [$C58D](variables/software/C58D.md)
- [$C58E](variables/software/C58E.md)
- [$C5DB](variables/software/C5DB.md)
- [$C5DC](variables/software/C5DC.md)
- [$C5DD](variables/software/C5DD.md)
- [$C5DE](variables/software/C5DE.md)
- [$C5DF](variables/software/C5DF.md)
- [$C5E0](variables/software/C5E0.md)
- [$C5ED](variables/software/C5ED.md)
- [$C5EE](variables/software/C5EE.md)
- [$C5F0](variables/software/C5F0.md)
- [$C5F1](variables/software/C5F1.md)
- [$C604](variables/software/C604.md)
- [$C605](variables/software/C605.md)
- [$C606](variables/software/C606.md)
- [$C607](variables/software/C607.md)
- [$C60A](variables/software/C60A.md)
- [$C60B](variables/software/C60B.md)
- [$FFB9](variables/software/FFB9.md)
- [$FFBA](variables/software/FFBA.md)