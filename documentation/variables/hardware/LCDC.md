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
LCDC Y-Coordinate (R)
Values range from 0->153. 144->153 is the VBlank period.

---

### rBGP($FF47)
BG Palette Data (W)

Bit 7-6 - Intensity for %11
Bit 5-4 - Intensity for %10
Bit 3-2 - Intensity for %01
Bit 1-0 - Intensity for %00

--- 
