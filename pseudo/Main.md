```
main :: proc() {
	
	if A == $11 do [IsGBC] = true;
	else        do [IsGBC] = false;
	
	di();
	SP = $DFFF;
	
	SetInterrupts();
	MemInitialization();
	CopyDMATransfer();
	
	Memset(0, 7168, $8000);
	
	if [IsGBC] {
		[rVBK] = 1;
		Memset(0, 2048, $9800);
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
		if  {
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


# Functions
- [SetInterrupts()](bank0/set_interrupts.md)
- [MemInitialization()](bank0/memory_initialization.md)
- [CopyDMATransfer()](bank0/copy_dma_transfer.md)
- [Memset(value, counter, ptr)](bank0/memset.md)
- [Wait7000()](bank0/wait_7000.md)
- [VRAMClear()](bank0/vram_clear.md)
- [clear_work_start()](bank0/clear_work_start.md)
- [FUN_0355()](bank0/FUN_0355.md)
- [FUN_05E2()](bank0/FUN_05E2.md)
- [FUN_06A8($0D, $17, $44, $8C)](bank0/FUN_06A8.md)
- [FUN_0705(12, 2048, $446C, 23)](bank0/FUN_0705.md)
- [FUN_095B()](bank0/FUN_095B.md)
- [FUN_0B7F()](bank0/FUN_0B7F.md)
- [FUN_0B9B()](bank0/FUN_0B9B.md)
- [FUN_3290()](bank0/FUN_3290.md)
- [FUN_ROM2_42FA()](bank2/FUN_42FA.md)
- [FUN_ROM31_5040()](bank31/FUN_5040.md)

# Variables
##### Hardware
- [rP1] = $FF00;
- [rIF] = $FF0F;
- [rNR50] = $FF24;
- [rNR51] = $FF25;
- [rNR52] = $FF26;
- [rSCY] = $FF42;
- [rSCX] = $FF43;
- [rBGP] = $FF47;  
- [rVBK] = $FF4F;
- [rRP] = $FF56;
- [rSVBK] = $FF70;
##### Game
- [IsGBC] :: $C525