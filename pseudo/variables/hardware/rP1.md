## rP1 $FF00 
__| Joypad input |__

---

Register for reading joy pad info. (R/W)

[P1F_5] = %00100000 | P15, set to 0 to get buttons
[P1F_4] = %00010000 | P14, set to 0 to get dpad
[P1F_3] = %00001000 | P13, Down / Start
[P1F_2] = %00000100 | P12, Up / Select
[P1F_1] = %00000010 | P11, Left / B
[P1F_0] = %00000001 | P10, Right / A

[P1F_GET_DPAD] = [P1F_5]
[P1F_GET_BTN]  = [P1F_4]
[P1F_GET_NONE] = [P1F_4] | [P1F_5]

---