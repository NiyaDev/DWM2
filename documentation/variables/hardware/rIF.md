## rIF $FF0F
__| Interrupt Flag |__

---

Interrupt Flag (R/W)

```undefined
Bit 0: VBlank   Interrupt Request (INT $40)  (1=Request)
Bit 1: LCD STAT Interrupt Request (INT $48)  (1=Request)
Bit 2: Timer    Interrupt Request (INT $50)  (1=Request)
Bit 3: Serial   Interrupt Request (INT $58)  (1=Request)
Bit 4: Joypad   Interrupt Request (INT $60)  (1=Request)
```

When an interrupt request signal changes from low to high, the corresponding bit in the IF register is set. For example, Bit 0 becomes set when the LCD controller enters the VBlank period.

Any set bits in the IF register are only **requesting** an interrupt. The actual **execution** of the interrupt handler happens only if both the IME flag and the corresponding bit in the IE register are set; otherwise the interrupt “waits” until both IME and IE allow it to be serviced.

Since the CPU automatically sets and clears the bits in the IF register, it is usually not necessary to write to the IF register. However, the user may still do that in order to manually request (or discard) interrupts. Just like real interrupts, a manually requested interrupt isn’t serviced unless/until IME and IE allow it.

---
