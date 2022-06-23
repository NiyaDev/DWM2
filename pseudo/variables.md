# Variables
## Hardware
##### MBC5
_[rRAMG] ($0100)_
Enable or disable writing to cartridge RAM

---

_[rROMB0] ($2100)_
Lower byte of ROM bank

---

_[rROMB1] ($3100)_
If more than 256 ROM banks are present

---

_[rRAMB] ($4100)_

Bit 3 enables rumble (if present)

---
##### FEA0-FEFF
__| Prohibited |__
##### FF00 
__| Joypad input |__

---

_[rP1] ($FF00)_
Register for reading joy pad info. (R/W)

[P1F_5] = %00100000 | P15, set to 0 to get buttons
[P1F_4] = %00010000 | P14, set to 0 to get dpad
[P1F_3] = %00001000 | P13, Down / Start
[P1F_2] = %00000100 | P12, Up / Select
[P1F_1] = %00000010 | P11, Left / B
[P1F_0] = %00000001 | P10, Right / A

[P1F_GET_DPAD] = P1F_5
[P1F_GET_BTN]  = P1F_4
[P1F_GET_NONE] = P1F_4 | P1F_5

---

##### FF01-FF02
__| Serial |__
##### FF04-FF07
__| Timer and Divider |___
##### FF0F
__| Interrupt Flag |__

---

_[rIF] ($FF0F)_
Interrupt Flag (R/W)

---

##### FF10-FF26
__| Sound |__

---

_[rAUDVOL] / [rNR50] ($FF24)_
Channel control / ON-OFF / Volume (R/W)

Bit 7   - Vin->SO2 ON/OFF (Vin??)
Bit 6-4 - SO2 output level (volume) (# 0-7)
Bit 3   - Vin->SO1 ON/OFF (Vin??)
Bit 2-0 - SO1 output level (volume) (# 0-7)

---

[rAUDTERM] / [rNR51] ($FF25)_
Selection of Sound output terminal (R/W)

Bit 7   - Output sound 4 to SO2 terminal
Bit 6   - Output sound 3 to SO2 terminal
Bit 5   - Output sound 2 to SO2 terminal
Bit 4   - Output sound 1 to SO2 terminal
Bit 3   - Output sound 4 to SO1 terminal
Bit 2   - Output sound 3 to SO1 terminal
Bit 1   - Output sound 2 to SO1 terminal
Bit 0   - Output sound 0 to SO1 terminal

---

[rAUDENA] / [rNR52] ($FF26)
Sound on/off (R/W)

Bit 7   - All sound on/off (sets all audio regs to 0!)
Bit 3   - Sound 4 ON flag (read only)
Bit 2   - Sound 3 ON flag (read only)
Bit 1   - Sound 2 ON flag (read only)
Bit 0   - Sound 1 ON flag (read only)

---

##### FF30-FF3F
__| Wave pattern |__
##### FF40-FF4B
__| LCD Control, Status, Position, Scrolling, and Palettes |__

---

_[rLCDC] ($FF40)_
LCD Control (R/W)

---

_[rSCY] ($FF42)_
Scroll Y (R/W)

---

_[rSCX] ($FF43)_
Scroll X (R/W)

---

_[rLY] ($FF44)_
LCDC Y-Coordinate (R)
Values range from 0->153. 144->153 is the VBlank period.

---

_[rBGP] ($FF47)_
BG Palette Data (W)

Bit 7-6 - Intensity for %11
Bit 5-4 - Intensity for %10
Bit 3-2 - Intensity for %01
Bit 1-0 - Intensity for %00

--- 

##### FF4F
__| VRAM bank select |__
__{GBC Onwards}__

---

_[rVBK] ($FF4F)_
Select Video RAM Bank (R/W)
Bit 0 - Bank Specification (0: Specify Bank 0; 1: Specify Bank 1)

---

##### FF50
__| Disable boot ROM |__
##### FF51-FF55
__| VRAM DMA |__
__{GBC Onwards}__

---

_[rHDMA1] ($FF51)_
High byte for Horizontal Blanking/General Purpose DMA source address (W)

---

_[rHDMA2] ($FF52)_
Low byte for Horizontal Blanking/General Purpose DMA source address (W)

---

_[rHDMA3] ($FF53)_
High byte for Horizontal Blanking/General Purpose DMA destination address (W)

---

_[rHDMA4] ($FF54)_
Low byte for Horizontal Blanking/General Purpose DMA destination address (W)

---

_[rHDMA5] ($FF55)_
Transfer length (in tiles minus 1)/mode/start for Horizontal Blanking, General Purpose DMA (R/W)

---
##### FF56
__| Infrared communications port |__

---

_[rRP] ($FF56)_
Infrared Communications Port (R/W)
CGB Mode Only

---

##### FF68-FF69
__| BG / OBJ palettes |__
_{GBC Onwards}_

---

_[rBCPS] ($FF68)_
Background Color Palette Specification (R/W)

---

_[rOCPS] ($FF6A)_
Object Color Palette Specification (R/W)

---
##### FF70
__| WRAM bank select |__
_{GBC Onwards}_

---

_[rSMBK] / [rSVBK] ($FF70)_
Select Main RAM Bank (R/W)
Bit 2-0 - Bank Specification (0,1: Specify Bank 1; 2-7: Specify Banks 2-7)

---

## Software
##### C525
___[IsGBC] | bool___
True if Gameboy Color
False if not

##### C5EC
___[$C5EC] | ???___

##### FF80-FF89
___[DMATransfer] | proc()___
