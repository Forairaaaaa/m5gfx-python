/**
 * @file main.cpp
 * @author Forairaaaaa
 * @brief
 * @version 0.1
 * @date 2025-05-27
 *
 * @copyright Copyright (c) 2025
 *
 */
#include <M5GFX.h>
#include "LGFX_AutoDetect_sdl.hpp"

static LGFX gfx(480, 320);

void setup(void)
{
    gfx.init();
    gfx.fillScreen(TFT_WHITE);
}

void loop(void)
{
}

__attribute__((weak)) int user_func(bool* running)
{
    setup();
    do {
        loop();
    } while (*running);
    return 0;
}

int main(int argc, char const* argv[])
{
    return lgfx::Panel_sdl::main(user_func, 128);
}
