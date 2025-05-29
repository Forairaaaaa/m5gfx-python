import m5gfx
import time
import random

gfx = m5gfx.M5GFX(320, 240)

gfx.begin()

gfx.fillRect(50, 60, 100, 60, 0x00ff00)

gfx.setColor(0xffffff)
gfx.fillRect(100, 150, 20, 30)

gfx.drawEllipseArc(100, 100, 50, 100, 50, 100, 0, 360, 0xff0000)

gfx.drawLine(0, 0, 320, 240, 0xffffff)

gfx.fillSmoothCircle(250, 120, 50, random.randint(0x101010, 0xffffff))

gfx.fillSmoothRoundRect(100, 100, 100, 100, 10,
                        random.randint(0x101010, 0xffffff))

gfx.setTextFont(m5gfx.efontCN_24)

gfx.setTextColor(0x000000, 0xffffff)

gfx.drawString("Hello, World!", 160, 120)

while not gfx.isAllClosed():
    time.sleep(1)
