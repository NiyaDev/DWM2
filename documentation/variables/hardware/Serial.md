## FF40-FF4B
__| Serial Transfer |__

---

### rSB($FF01)
Serial Transfer Data (R/W)

Before a transfer, it holds the next byte that will go out.

During a transfer, it has a blend of the outgoing and incoming bytes. Each cycle, the leftmost bit is shifted out (and over the wire) and the incoming bit is shifted in from the other side:

---

### SC($FF02)
Serial I/O Control (R/W)

```
Bit 7 - Transfer Start Flag (0=No transfer is in progress or requested, 1=Transfer in progress, or requested)
Bit 1 - Clock Speed (0=Normal, 1=Fast) ** CGB Mode Only **
Bit 0 - Shift Clock (0=External Clock, 1=Internal Clock)
```
The master Game Boy will load up a data byte in SB and then set SC to 0x81 (Transfer requested, use internal clock). It will be notified that the transfer is complete in two ways: SC’s Bit 7 will be cleared (that is, SC will be set up 0x01), and also the Serial Interrupt handler will be called (that is, the CPU will jump to 0x0058).

The other Game Boy will load up a data byte and can optionally set SC’s Bit 7 (that is, SC=0x80). Regardless of whether or not it has done this, if and when the master wants to conduct a transfer, it will happen (pulling whatever happens to be in SB at that time). The externally clocked Game Boy will have its serial interrupt handler called at the end of the transfer, and if it bothered to set SC’s Bit 7, it will be cleared.

---