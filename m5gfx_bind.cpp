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
        .def("startWrite", &LGFX::startWrite)
        .def("endWrite", &LGFX::endWrite);

    m.attr("TFT_WHITE") = TFT_WHITE;
}
