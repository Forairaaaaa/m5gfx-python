import m5gfx
import time

gfx = m5gfx.M5GFX(320, 240)
print("TFT_WHITE:", m5gfx.TFT_WHITE)

gfx.begin()

while not gfx.isAllClosed():
    time.sleep(1)
