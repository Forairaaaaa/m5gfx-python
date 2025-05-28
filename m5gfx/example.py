import m5gfx
import time

gfx = m5gfx.M5GFX(320, 240)

gfx.begin()

gfx.fillRect(50, 60, 100, 60, 0x00ff00)

gfx.setColor(0xffffff)
gfx.fillRect(100, 150, 20, 30)

gfx.drawEllipseArc(100, 100, 50, 100, 50, 100, 0, 360, 0xff0000)

while not gfx.isAllClosed():
    time.sleep(1)
