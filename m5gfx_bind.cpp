/**
 * @file m5gfx_pybind.cpp
 * @author Forairaaaaa
 * @brief
 * @version 0.1
 * @date 2025-05-28
 *
 * @copyright Copyright (c) 2025
 *
 */
#include <pybind11/pybind11.h>
#include <M5GFX.h>
#include "lgfx_sdl.hpp"

namespace py = pybind11;

PYBIND11_MODULE(m5gfx, m)
{
    py::class_<LGFX>(m, "M5GFX")
        .def(py::init<int, int>())
        .def("init", &LGFX::init)
        .def("begin", &LGFX::begin)
        .def("isAllClosed", &LGFX::isAllClosed)
        .def("fillRect", [](LGFX& self, int32_t arg0, int32_t arg1, int32_t arg2, int32_t arg3,
                            uint32_t arg4) { self.fillRect(arg0, arg1, arg2, arg3, arg4); })
        .def("fillRect", static_cast<void (LGFX::*)(int32_t x, int32_t y, int32_t w, int32_t h)>(&LGFX::fillRect));

    m.attr("TFT_WHITE") = TFT_WHITE;
}
