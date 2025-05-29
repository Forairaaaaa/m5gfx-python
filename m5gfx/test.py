import m5gfx
import time
# Refs: https://github.com/Bodmer/TFT_eSPI/blob/master/examples/480%20x%20320/TFT_graphicstest_one_lib/TFT_graphicstest_one_lib.ino

gfx = m5gfx.M5GFX(320, 240)
gfx.begin()


def test_fill_screen():
    print("test_fill_screen")
    colors = [0x000000, 0xff0000, 0x00ff00, 0x0000ff]
    for color in colors:
        gfx.fillScreen(color)
        time.sleep(0.2)
        if gfx.isAllClosed():
            break


def test_draw_line():
    print("test_draw_line")
    w = gfx.width()
    h = gfx.height()
    color = 0xffffff  # 白色

    # 从左上角开始
    gfx.fillScreen(0x000000)
    x1, y1 = 0, 0
    for x2 in range(0, w, 6):
        gfx.drawLine(x1, y1, x2, h-1, color)
    for y2 in range(0, h, 6):
        gfx.drawLine(x1, y1, w-1, y2, color)
    time.sleep(0.2)
    if gfx.isAllClosed():
        return

    # 从右上角开始
    gfx.fillScreen(0x000000)
    x1, y1 = w-1, 0
    for x2 in range(0, w, 6):
        gfx.drawLine(x1, y1, x2, h-1, color)
    for y2 in range(0, h, 6):
        gfx.drawLine(x1, y1, 0, y2, color)
    time.sleep(0.2)
    if gfx.isAllClosed():
        return

    # 从左下角开始
    gfx.fillScreen(0x000000)
    x1, y1 = 0, h-1
    for x2 in range(0, w, 6):
        gfx.drawLine(x1, y1, x2, 0, color)
    for y2 in range(0, h, 6):
        gfx.drawLine(x1, y1, w-1, y2, color)
    time.sleep(0.2)
    if gfx.isAllClosed():
        return

    # 从右下角开始
    gfx.fillScreen(0x000000)
    x1, y1 = w-1, h-1
    for x2 in range(0, w, 6):
        gfx.drawLine(x1, y1, x2, 0, color)
    for y2 in range(0, h, 6):
        gfx.drawLine(x1, y1, 0, y2, color)
    time.sleep(0.2)
    if gfx.isAllClosed():
        return


def test_draw_fast_line():
    print("test_draw_fast_line")
    w = gfx.width()
    h = gfx.height()
    color1 = 0xff0000  # 红色
    color2 = 0x0000ff  # 蓝色

    gfx.fillScreen(0x000000)

    # 画水平线
    for y in range(0, h, 5):
        gfx.drawFastHLine(0, y, w, color1)

    # 画垂直线
    for x in range(0, w, 5):
        gfx.drawFastVLine(x, 0, h, color2)

    time.sleep(0.2)
    if gfx.isAllClosed():
        return


def test_draw_rect():
    print("test_draw_rect")
    w = gfx.width()
    h = gfx.height()
    color = 0xffffff  # 白色

    gfx.fillScreen(0x000000)

    # 计算中心点
    cx = w // 2
    cy = h // 2

    # 计算最大尺寸
    n = min(w, h)

    # 画空心矩形
    for i in range(2, n, 6):
        i2 = i // 2
        gfx.drawRect(cx - i2, cy - i2, i, i, color)

    time.sleep(0.2)
    if gfx.isAllClosed():
        return


def test_fill_rect():
    print("test_fill_rect")
    w = gfx.width()
    h = gfx.height()
    color1 = 0xff0000  # 红色填充
    color2 = 0x0000ff  # 蓝色边框

    gfx.fillScreen(0x000000)

    # 计算中心点
    cx = w // 2 - 1
    cy = h // 2 - 1

    # 计算最大尺寸
    n = min(w, h)

    # 画实心矩形
    for i in range(n-1, 0, -6):
        i2 = i // 2
        gfx.fillRect(cx - i2, cy - i2, i, i, color1)
        gfx.drawRect(cx - i2, cy - i2, i, i, color2)

    time.sleep(0.2)
    if gfx.isAllClosed():
        return


def test_fill_circle():
    print("test_fill_circle")
    w = gfx.width()
    h = gfx.height()
    radius = 10
    color = 0x00ff00  # 绿色
    r2 = radius * 2

    gfx.fillScreen(0x000000)

    # 画实心圆
    for x in range(radius, w, r2):
        for y in range(radius, h, r2):
            gfx.fillCircle(x, y, radius, color)

    time.sleep(0.2)
    if gfx.isAllClosed():
        return


def test_fill_smooth_circle():
    print("test_fill_smooth_circle")
    w = gfx.width()
    h = gfx.height()
    radius = 10
    color = 0x00ff00  # 绿色
    r2 = radius * 2

    gfx.fillScreen(0x000000)

    # 画实心圆
    for x in range(radius, w, r2):
        for y in range(radius, h, r2):
            gfx.fillSmoothCircle(x, y, radius, color)

    time.sleep(0.2)
    if gfx.isAllClosed():
        return


def test_draw_circle():
    print("test_draw_circle")
    w = gfx.width()
    h = gfx.height()
    radius = 10
    color = 0xffff00  # 黄色
    r2 = radius * 2

    # 注意：这里不清屏，保持之前的图案

    # 画空心圆
    for x in range(0, w + radius, r2):
        for y in range(0, h + radius, r2):
            gfx.drawCircle(x, y, radius, color)

    time.sleep(0.2)
    if gfx.isAllClosed():
        return


def test_draw_triangle():
    print("test_draw_triangle")
    w = gfx.width()
    h = gfx.height()

    # 计算中心点
    cx = w // 2 - 1
    cy = h // 2 - 1

    gfx.fillScreen(0x000000)

    # 计算最大尺寸
    n = min(cx, cy)

    # 画空心三角形
    for i in range(0, n, 5):
        # 使用蓝色，颜色值随i变化
        color = gfx.color565(0, 0, i)
        gfx.drawTriangle(
            cx, cy - i,     # 顶点
            cx - i, cy + i,  # 左下
            cx + i, cy + i,  # 右下
            color
        )

    time.sleep(0.2)
    if gfx.isAllClosed():
        return


def test_fill_triangle():
    print("test_fill_triangle")
    w = gfx.width()
    h = gfx.height()

    # 计算中心点
    cx = w // 2 - 1
    cy = h // 2 - 1

    gfx.fillScreen(0x000000)

    # 计算最大尺寸
    n = min(cx, cy)

    # 画实心三角形
    for i in range(n, 10, -5):
        # 填充使用青色，颜色值随i变化
        fill_color = gfx.color565(0, i, i)
        # 边框使用黄色，颜色值随i变化
        border_color = gfx.color565(i, i, 0)

        gfx.fillTriangle(
            cx, cy - i,     # 顶点
            cx - i, cy + i,  # 左下
            cx + i, cy + i,  # 右下
            fill_color
        )
        gfx.drawTriangle(
            cx, cy - i,     # 顶点
            cx - i, cy + i,  # 左下
            cx + i, cy + i,  # 右下
            border_color
        )

    time.sleep(0.2)
    if gfx.isAllClosed():
        return


def test_draw_round_rect():
    print("test_draw_round_rect")
    w = gfx.width()
    h = gfx.height()

    # 计算中心点
    cx = w // 2 - 1
    cy = h // 2 - 1

    gfx.fillScreen(0x000000)

    # 计算最大尺寸
    n = min(w, h)

    # 画空心圆角矩形
    for i in range(0, n, 6):
        i2 = i // 2
        # 使用红色，颜色值随i变化
        color = gfx.color565(i, 0, 0)
        gfx.drawRoundRect(cx - i2, cy - i2, i, i, i // 8, color)

    time.sleep(0.2)
    if gfx.isAllClosed():
        return


def test_fill_round_rect():
    print("test_fill_round_rect")
    w = gfx.width()
    h = gfx.height()

    # 计算中心点
    cx = w // 2 - 1
    cy = h // 2 - 1

    gfx.fillScreen(0x000000)

    # 计算最大尺寸
    n = min(w, h)

    # 画实心圆角矩形
    for i in range(n, 20, -6):
        i2 = i // 2
        # 使用绿色，颜色值随i变化
        color = gfx.color565(0, i, 0)
        gfx.fillRoundRect(cx - i2, cy - i2, i, i, i // 8, color)

    time.sleep(0.2)
    if gfx.isAllClosed():
        return


def test_fill_smooth_round_rect():
    print("test_fill_smooth_round_rect")
    w = gfx.width()
    h = gfx.height()

    # 计算中心点
    cx = w // 2 - 1
    cy = h // 2 - 1

    gfx.fillScreen(0x000000)

    # 计算最大尺寸
    n = min(w, h)

    # 画实心圆角矩形
    for i in range(n, 20, -6):
        i2 = i // 2
        # 使用绿色，颜色值随i变化
        color = gfx.color565(0, i, 0)
        gfx.fillSmoothRoundRect(cx - i2, cy - i2, i, i, i // 8, color)

    time.sleep(0.2)
    if gfx.isAllClosed():
        return


def test_font():
    print("test_font")
    font_map = {
        "Font0": m5gfx.Font0,
        "Font2": m5gfx.Font2,
        "Font4": m5gfx.Font4,
        "Font6": m5gfx.Font6,
        "Font7": m5gfx.Font7,
        "Font8": m5gfx.Font8,
        "Font8x8C64": m5gfx.Font8x8C64,
        "AsciiFont8x16": m5gfx.AsciiFont8x16,
        "AsciiFont24x48": m5gfx.AsciiFont24x48,
        "TomThumb": m5gfx.TomThumb,
        "FreeMono9pt7b": m5gfx.FreeMono9pt7b,
        "FreeMono12pt7b": m5gfx.FreeMono12pt7b,
        "FreeMono18pt7b": m5gfx.FreeMono18pt7b,
        "FreeMono24pt7b": m5gfx.FreeMono24pt7b,
        "FreeMonoBold9pt7b": m5gfx.FreeMonoBold9pt7b,
        "FreeMonoBold12pt7b": m5gfx.FreeMonoBold12pt7b,
        "FreeMonoBold18pt7b": m5gfx.FreeMonoBold18pt7b,
        "FreeMonoBold24pt7b": m5gfx.FreeMonoBold24pt7b,
        "FreeMonoOblique9pt7b": m5gfx.FreeMonoOblique9pt7b,
        "FreeMonoOblique12pt7b": m5gfx.FreeMonoOblique12pt7b,
        "FreeMonoOblique18pt7b": m5gfx.FreeMonoOblique18pt7b,
        "FreeMonoOblique24pt7b": m5gfx.FreeMonoOblique24pt7b,
        "FreeMonoBoldOblique9pt7b": m5gfx.FreeMonoBoldOblique9pt7b,
        "FreeMonoBoldOblique12pt7b": m5gfx.FreeMonoBoldOblique12pt7b,
        "FreeMonoBoldOblique18pt7b": m5gfx.FreeMonoBoldOblique18pt7b,
        "FreeMonoBoldOblique24pt7b": m5gfx.FreeMonoBoldOblique24pt7b,
        "FreeSans9pt7b": m5gfx.FreeSans9pt7b,
        "FreeSans12pt7b": m5gfx.FreeSans12pt7b,
        "FreeSans18pt7b": m5gfx.FreeSans18pt7b,
        "FreeSans24pt7b": m5gfx.FreeSans24pt7b,
        "FreeSansOblique9pt7b": m5gfx.FreeSansOblique9pt7b,
        "FreeSansOblique12pt7b": m5gfx.FreeSansOblique12pt7b,
        "FreeSansOblique18pt7b": m5gfx.FreeSansOblique18pt7b,
        "FreeSansOblique24pt7b": m5gfx.FreeSansOblique24pt7b,
        "FreeSansBoldOblique9pt7b": m5gfx.FreeSansBoldOblique9pt7b,
        "FreeSansBoldOblique12pt7b": m5gfx.FreeSansBoldOblique12pt7b,
        "FreeSansBoldOblique18pt7b": m5gfx.FreeSansBoldOblique18pt7b,
        "FreeSansBoldOblique24pt7b": m5gfx.FreeSansBoldOblique24pt7b,
        "FreeSerif9pt7b": m5gfx.FreeSerif9pt7b,
        "FreeSerif12pt7b": m5gfx.FreeSerif12pt7b,
        "FreeSerif18pt7b": m5gfx.FreeSerif18pt7b,
        "FreeSerif24pt7b": m5gfx.FreeSerif24pt7b,
        "FreeSerifItalic9pt7b": m5gfx.FreeSerifItalic9pt7b,
        "FreeSerifItalic12pt7b": m5gfx.FreeSerifItalic12pt7b,
        "FreeSerifItalic18pt7b": m5gfx.FreeSerifItalic18pt7b,
        "FreeSerifItalic24pt7b": m5gfx.FreeSerifItalic24pt7b,
        "FreeSerifBold9pt7b": m5gfx.FreeSerifBold9pt7b,
        "FreeSerifBold12pt7b": m5gfx.FreeSerifBold12pt7b,
        "FreeSerifBold18pt7b": m5gfx.FreeSerifBold18pt7b,
        "FreeSerifBold24pt7b": m5gfx.FreeSerifBold24pt7b,
        "FreeSerifBoldItalic9pt7b": m5gfx.FreeSerifBoldItalic9pt7b,
        "FreeSerifBoldItalic12pt7b": m5gfx.FreeSerifBoldItalic12pt7b,
        "FreeSerifBoldItalic18pt7b": m5gfx.FreeSerifBoldItalic18pt7b,
        "FreeSerifBoldItalic24pt7b": m5gfx.FreeSerifBoldItalic24pt7b,
        "DejaVu9": m5gfx.DejaVu9,
        "DejaVu12": m5gfx.DejaVu12,
        "DejaVu18": m5gfx.DejaVu18,
        "DejaVu24": m5gfx.DejaVu24,
        "DejaVu40": m5gfx.DejaVu40,
        "DejaVu56": m5gfx.DejaVu56,
        "DejaVu72": m5gfx.DejaVu72,
        "lgfxJapanMincho_8": m5gfx.lgfxJapanMincho_8,
        "lgfxJapanMincho_12": m5gfx.lgfxJapanMincho_12,
        "lgfxJapanMincho_16": m5gfx.lgfxJapanMincho_16,
        "lgfxJapanMincho_20": m5gfx.lgfxJapanMincho_20,
        "lgfxJapanMincho_24": m5gfx.lgfxJapanMincho_24,
        "lgfxJapanMincho_28": m5gfx.lgfxJapanMincho_28,
        "lgfxJapanMincho_32": m5gfx.lgfxJapanMincho_32,
        "lgfxJapanMincho_36": m5gfx.lgfxJapanMincho_36,
        "lgfxJapanMincho_40": m5gfx.lgfxJapanMincho_40,
        "lgfxJapanMinchoP_8": m5gfx.lgfxJapanMinchoP_8,
        "lgfxJapanMinchoP_12": m5gfx.lgfxJapanMinchoP_12,
        "lgfxJapanMinchoP_16": m5gfx.lgfxJapanMinchoP_16,
        "lgfxJapanMinchoP_20": m5gfx.lgfxJapanMinchoP_20,
        "lgfxJapanMinchoP_24": m5gfx.lgfxJapanMinchoP_24,
        "lgfxJapanMinchoP_28": m5gfx.lgfxJapanMinchoP_28,
        "lgfxJapanMinchoP_32": m5gfx.lgfxJapanMinchoP_32,
        "lgfxJapanMinchoP_36": m5gfx.lgfxJapanMinchoP_36,
        "lgfxJapanMinchoP_40": m5gfx.lgfxJapanMinchoP_40,
        "lgfxJapanGothic_8": m5gfx.lgfxJapanGothic_8,
        "lgfxJapanGothic_12": m5gfx.lgfxJapanGothic_12,
        "lgfxJapanGothic_16": m5gfx.lgfxJapanGothic_16,
        "lgfxJapanGothic_20": m5gfx.lgfxJapanGothic_20,
        "lgfxJapanGothic_24": m5gfx.lgfxJapanGothic_24,
        "lgfxJapanGothic_28": m5gfx.lgfxJapanGothic_28,
        "lgfxJapanGothic_32": m5gfx.lgfxJapanGothic_32,
        "lgfxJapanGothic_36": m5gfx.lgfxJapanGothic_36,
        "lgfxJapanGothicP_16": m5gfx.lgfxJapanGothicP_16,
        "lgfxJapanGothicP_20": m5gfx.lgfxJapanGothicP_20,
        "lgfxJapanGothicP_24": m5gfx.lgfxJapanGothicP_24,
        "lgfxJapanGothicP_28": m5gfx.lgfxJapanGothicP_28,
        "lgfxJapanGothicP_32": m5gfx.lgfxJapanGothicP_32,
        "lgfxJapanGothicP_36": m5gfx.lgfxJapanGothicP_36,
        "lgfxJapanGothicP_40": m5gfx.lgfxJapanGothicP_40,
        "efontCN_10": m5gfx.efontCN_10,
        "efontCN_10_b": m5gfx.efontCN_10_b,
        "efontCN_10_bi": m5gfx.efontCN_10_bi,
        "efontCN_10_i": m5gfx.efontCN_10_i,
        "efontCN_12": m5gfx.efontCN_12,
        "efontCN_12_b": m5gfx.efontCN_12_b,
        "efontCN_12_bi": m5gfx.efontCN_12_bi,
        "efontCN_12_i": m5gfx.efontCN_12_i,
        "efontCN_14": m5gfx.efontCN_14,
        "efontCN_14_b": m5gfx.efontCN_14_b,
        "efontCN_14_bi": m5gfx.efontCN_14_bi,
        "efontCN_14_i": m5gfx.efontCN_14_i,
        "efontCN_16": m5gfx.efontCN_16,
        "efontCN_16_b": m5gfx.efontCN_16_b,
        "efontCN_16_bi": m5gfx.efontCN_16_bi,
        "efontCN_16_i": m5gfx.efontCN_16_i,
        "efontCN_24": m5gfx.efontCN_24,
        "efontCN_24_b": m5gfx.efontCN_24_b,
        "efontCN_24_bi": m5gfx.efontCN_24_bi,
        "efontCN_24_i": m5gfx.efontCN_24_i,
        "efontJA_10": m5gfx.efontJA_10,
        "efontJA_10_b": m5gfx.efontJA_10_b,
        "efontJA_10_bi": m5gfx.efontJA_10_bi,
        "efontJA_10_i": m5gfx.efontJA_10_i,
        "efontJA_12": m5gfx.efontJA_12,
        "efontJA_12_b": m5gfx.efontJA_12_b,
        "efontJA_12_bi": m5gfx.efontJA_12_bi,
        "efontJA_12_i": m5gfx.efontJA_12_i,
        "efontJA_14": m5gfx.efontJA_14,
        "efontJA_14_b": m5gfx.efontJA_14_b,
        "efontJA_14_bi": m5gfx.efontJA_14_bi,
        "efontJA_14_i": m5gfx.efontJA_14_i,
        "efontJA_16": m5gfx.efontJA_16,
        "efontJA_16_b": m5gfx.efontJA_16_b,
        "efontJA_16_bi": m5gfx.efontJA_16_bi,
        "efontJA_16_i": m5gfx.efontJA_16_i,
        "efontJA_24": m5gfx.efontJA_24,
        "efontJA_24_b": m5gfx.efontJA_24_b,
        "efontJA_24_bi": m5gfx.efontJA_24_bi,
        "efontJA_24_i": m5gfx.efontJA_24_i,
        "efontKR_10": m5gfx.efontKR_10,
        "efontKR_10_b": m5gfx.efontKR_10_b,
        "efontKR_10_bi": m5gfx.efontKR_10_bi,
        "efontKR_10_i": m5gfx.efontKR_10_i,
        "efontKR_12": m5gfx.efontKR_12,
        "efontKR_12_b": m5gfx.efontKR_12_b,
        "efontKR_12_bi": m5gfx.efontKR_12_bi,
        "efontKR_12_i": m5gfx.efontKR_12_i,
        "efontKR_14": m5gfx.efontKR_14,
        "efontKR_14_b": m5gfx.efontKR_14_b,
        "efontKR_14_bi": m5gfx.efontKR_14_bi,
        "efontKR_14_i": m5gfx.efontKR_14_i,
        "efontKR_16": m5gfx.efontKR_16,
        "efontKR_16_b": m5gfx.efontKR_16_b,
        "efontKR_16_bi": m5gfx.efontKR_16_bi,
        "efontKR_16_i": m5gfx.efontKR_16_i,
        "efontKR_24": m5gfx.efontKR_24,
        "efontKR_24_b": m5gfx.efontKR_24_b,
        "efontKR_24_bi": m5gfx.efontKR_24_bi,
        "efontKR_24_i": m5gfx.efontKR_24_i,
        "efontTW_10": m5gfx.efontTW_10,
        "efontTW_10_b": m5gfx.efontTW_10_b,
        "efontTW_10_bi": m5gfx.efontTW_10_bi,
        "efontTW_10_i": m5gfx.efontTW_10_i,
        "efontTW_12": m5gfx.efontTW_12,
        "efontTW_12_b": m5gfx.efontTW_12_b,
        "efontTW_12_bi": m5gfx.efontTW_12_bi,
        "efontTW_12_i": m5gfx.efontTW_12_i,
        "efontTW_14": m5gfx.efontTW_14,
        "efontTW_14_b": m5gfx.efontTW_14_b,
        "efontTW_14_bi": m5gfx.efontTW_14_bi,
        "efontTW_14_i": m5gfx.efontTW_14_i,
        "efontTW_16": m5gfx.efontTW_16,
        "efontTW_16_b": m5gfx.efontTW_16_b,
        "efontTW_16_bi": m5gfx.efontTW_16_bi,
        "efontTW_16_i": m5gfx.efontTW_16_i,
        "efontTW_24": m5gfx.efontTW_24,
        "efontTW_24_b": m5gfx.efontTW_24_b,
        "efontTW_24_bi": m5gfx.efontTW_24_bi,
        "efontTW_24_i": m5gfx.efontTW_24_i,
    }

    gfx.setTextScroll(True)
    gfx.setCursor(0, 0)
    gfx.setTextColor(0xffffff, 0x000000)

    for name, font in font_map.items():
        print("test font:", name)
        gfx.setFont(font)
        gfx.println(
            "Hello, World!123~!@#$%^&*()_+-=\{\}[]:;'<>,./?")
        time.sleep(0.05)
        if gfx.isAllClosed():
            break


test_fill_screen()
test_draw_line()
test_draw_fast_line()
test_draw_rect()
test_fill_rect()
test_fill_circle()
test_fill_smooth_circle()
test_draw_circle()
test_draw_triangle()
test_fill_triangle()
test_draw_round_rect()
test_fill_round_rect()
test_fill_smooth_round_rect()
test_font()
