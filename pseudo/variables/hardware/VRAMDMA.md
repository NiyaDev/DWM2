## VRAM DMA (\$FF51-\$FF55)
__| VRAM DMA |__
__{GBC Onwards}__

---

### rHDMA1($FF51)
High byte for Horizontal Blanking/General Purpose DMA source address (W)

---

### rHDMA2($FF52)
Low byte for Horizontal Blanking/General Purpose DMA source address (W)

---

### rHDMA3($FF53)
High byte for Horizontal Blanking/General Purpose DMA destination address (W)

---

### rHDMA4($FF54)
Low byte for Horizontal Blanking/General Purpose DMA destination address (W)

---

### rHDMA5($FF55)
Transfer length (in tiles minus 1)/mode/start for Horizontal Blanking, General Purpose DMA (R/W)

---