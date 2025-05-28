/*----------------------------------------------------------------------------/
  Lovyan GFX - Graphics library for embedded devices.

Original Source:
 https://github.com/lovyan03/LovyanGFX/

Licence:
 [FreeBSD](https://github.com/lovyan03/LovyanGFX/blob/master/license.txt)

Author:
 [lovyan03](https://twitter.com/lovyan03)

Contributors:
 [ciniml](https://github.com/ciniml)
 [mongonta0716](https://github.com/mongonta0716)
 [tobozo](https://github.com/tobozo)
/----------------------------------------------------------------------------*/
#pragma once
#include <M5GFX.h>
#include <thread>
#include <atomic>
#include <lgfx/v1/platforms/common.hpp>
#include <lgfx/v1/platforms/sdl/Panel_sdl.hpp>
#include <pybind11/pybind11.h>

namespace py = pybind11;

namespace lgfx {
inline namespace v1 {
//----------------------------------------------------------------------------

class LGFX : public LGFX_Device {
public:
    LGFX(int width = 320, int height = 240, uint_fast8_t scaling_x = 0, uint_fast8_t scaling_y = 0)
    {
        auto cfg          = _panel_instance.config();
        cfg.memory_width  = width;
        cfg.panel_width   = width;
        cfg.memory_height = height;
        cfg.panel_height  = height;
        _panel_instance.config(cfg);
        if (scaling_x == 0) {
            scaling_x = 1;
        }
        if (scaling_y == 0) {
            scaling_y = scaling_x;
        }
        _panel_instance.setScaling(scaling_x, scaling_y);
        setPanel(&_panel_instance);

        // Create sdl thread
        _running    = true;
        _sdl_thread = std::thread([this]() { this->sdl_thread(); });
    }

    ~LGFX()
    {
        // Join sdl thread
        _running = false;
        if (_sdl_thread.joinable()) {
            _sdl_thread.join();
        }
    }

    bool isAllClosed() const
    {
        return _all_closed;
    }

private:
    lgfx::Panel_sdl _panel_instance;

    bool init_impl(bool use_reset, bool use_clear)
    {
        return LGFX_Device::init_impl(false, use_clear);
    }

    std::thread _sdl_thread;
    std::atomic<bool> _running{false};
    std::atomic<bool> _all_closed{false};

    void sdl_thread()
    {
        if (0 != Panel_sdl::setup()) {
            py::print("[m5gfx] [error] Panel_sdl::setup() failed");
            return;
        }

        while (_running) {
            if (lgfx::Panel_sdl::loop()) {
                _all_closed = true;
                break;
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(8));
        }

        Panel_sdl::close();
    }
};

//----------------------------------------------------------------------------
}  // namespace v1
}  // namespace lgfx

using LGFX = lgfx::LGFX;
