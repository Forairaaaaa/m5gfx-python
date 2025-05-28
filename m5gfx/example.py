import m5gfx
import time

gfx = m5gfx.M5GFX(320, 240)
print("TFT_WHITE:", m5gfx.TFT_WHITE)

gfx.begin()

gfx.fillRect(50, 60, 100, 60, 0x00ff00)

while not gfx.isAllClosed():
    time.sleep(1)
