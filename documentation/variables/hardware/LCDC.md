## FF40-FF4B
__| LCD Control, Status, Position, Scrolling, and Palettes |__

---

### rLCDC($FF40)
LCD Control (R/W)

---

### rSCY($FF42)
Scroll Y (R/W)

---

### rSCX($FF43)
Scroll X (R/W)

---

### rLY($FF44)
LY indicates the current horizontal line, which might be about to be drawn, being drawn, or just been drawn. LY can hold any value from 0 to 153, with values from 144 to 153 indicating the VBlank period.

---

### rLYC($FF45)
The Game Boy permanently compares the value of the LYC and LY registers. When both values are identical, the “LYC=LY” flag in the STAT register is set, and (if enabled) a STAT interrupt is requested.

---

### rBGP($FF47)
BG Palette Data (W)

Bit 7-6 - Intensity for %11
Bit 5-4 - Intensity for %10
Bit 3-2 - Intensity for %01
Bit 1-0 - Intensity for %00

--- 
