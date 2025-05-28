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
#include <cstddef>
#include <cstdint>
#include "lgfx_sdl.hpp"

namespace py = pybind11;

PYBIND11_MODULE(m5gfx, m)
{
    m.doc() = "Graphics library for M5Stack series  \n";
    m.def("delay", lgfx::delay, pybind11::arg("milliseconds"));
    m.attr("DejaVu9")    = (unsigned long long)&lgfx::v1::fonts::DejaVu9;
    m.attr("DejaVu12")   = (unsigned long long)&lgfx::v1::fonts::DejaVu12;
    m.attr("DejaVu18")   = (unsigned long long)&lgfx::v1::fonts::DejaVu18;
    m.attr("DejaVu24")   = (unsigned long long)&lgfx::v1::fonts::DejaVu24;
    m.attr("DejaVu40")   = (unsigned long long)&lgfx::v1::fonts::DejaVu40;
    m.attr("DejaVu56")   = (unsigned long long)&lgfx::v1::fonts::DejaVu56;
    m.attr("DejaVu72")   = (unsigned long long)&lgfx::v1::fonts::DejaVu72;
    m.attr("efontCN_14") = (unsigned long long)&lgfx::v1::fonts::efontCN_14;
    m.attr("efontCN_24") = (unsigned long long)&lgfx::v1::fonts::efontCN_24;
    m.attr("efontJA_14") = (unsigned long long)&lgfx::v1::fonts::efontJA_14;
    m.attr("efontJA_24") = (unsigned long long)&lgfx::v1::fonts::efontJA_24;
    m.attr("efontKR_14") = (unsigned long long)&lgfx::v1::fonts::efontKR_14;
    m.attr("efontKR_24") = (unsigned long long)&lgfx::v1::fonts::efontKR_24;

    py::class_<lgfx::v1::TextStyle>(m, "TextStyle")
        .def(py::init())
        .def_readwrite("fore_rgb888", &lgfx::v1::TextStyle::fore_rgb888)
        .def_readwrite("back_rgb888", &lgfx::v1::TextStyle::back_rgb888)
        .def_readwrite("size_x", &lgfx::v1::TextStyle::size_x)
        .def_readwrite("size_y", &lgfx::v1::TextStyle::size_y)
        .def_readwrite("datum", &lgfx::v1::TextStyle::datum)
        .def_readwrite("padding_x", &lgfx::v1::TextStyle::padding_x)
        .def_readwrite("utf8", &lgfx::v1::TextStyle::utf8)
        .def_readwrite("cp437", &lgfx::v1::TextStyle::cp437);

    py::class_<LGFX>(m, "M5GFX")
        .def(py::init<int, int>())
        .def("init", &LGFX::init)
        .def("begin", &LGFX::begin)
        .def("isAllClosed", &LGFX::isAllClosed)
        .def("color332", &LGFX::color332)
        .def("color565", &LGFX::color565)
        .def("color888", &LGFX::color888)
        .def("swap565", &LGFX::swap565)
        .def("swap888", &LGFX::swap888)
        .def("color16to8", &LGFX::color16to8)
        .def("color8to16", &LGFX::color8to16)
        .def("color16to24", &LGFX::color16to24)
        .def("color24to16", &LGFX::color24to16)
        .def("setColor", static_cast<void (LGFX::*)(uint8_t r, uint8_t g, uint8_t b)>(&LGFX::setColor))
        .def("setColor", [](LGFX& self, uint32_t arg0) { self.setColor(arg0); })
        .def("setRawColor", &LGFX::setRawColor)
        .def("getRawColor", &LGFX::getRawColor)
        .def("setBaseColor", [](LGFX& self, uint32_t arg0) { self.setBaseColor(arg0); })
        .def("getBaseColor", &LGFX::getBaseColor)
        .def("getColorConverter", &LGFX::getColorConverter)
        .def("getColorDepth", &LGFX::getColorDepth)
        .def("startWrite", &LGFX::startWrite)
        .def("endWrite", static_cast<void (LGFX::*)(void)>(&LGFX::endWrite))
        .def("endWrite", static_cast<void (LGFX::*)()>(&LGFX::endWrite))
        .def("beginTransaction", &LGFX::beginTransaction)
        .def("endTransaction", &LGFX::endTransaction)
        .def("getStartCount", &LGFX::getStartCount)
        .def("setWindow", &LGFX::setWindow)
        .def("writePixel", static_cast<void (LGFX::*)(int32_t x, int32_t y)>(&LGFX::writePixel))
        .def("writePixel",
             [](LGFX& self, int32_t arg0, int32_t arg1, uint32_t arg2) { self.writePixel(arg0, arg1, arg2); })
        .def("writeFastVLine", [](LGFX& self, int32_t arg0, int32_t arg1, int32_t arg2,
                                  uint32_t arg3) { self.writeFastVLine(arg0, arg1, arg2, arg3); })
        .def("writeFastVLine", static_cast<void (LGFX::*)(int32_t x, int32_t y, int32_t h)>(&LGFX::writeFastVLine))
        .def("writeFastHLine", [](LGFX& self, int32_t arg0, int32_t arg1, int32_t arg2,
                                  uint32_t arg3) { self.writeFastHLine(arg0, arg1, arg2, arg3); })
        .def("writeFastHLine", static_cast<void (LGFX::*)(int32_t x, int32_t y, int32_t w)>(&LGFX::writeFastHLine))
        .def("writeFillRect", [](LGFX& self, int32_t arg0, int32_t arg1, int32_t arg2, int32_t arg3,
                                 uint32_t arg4) { self.writeFillRect(arg0, arg1, arg2, arg3, arg4); })
        .def("writeFillRect",
             static_cast<void (LGFX::*)(int32_t x, int32_t y, int32_t w, int32_t h)>(&LGFX::writeFillRect))
        .def("writeFillRectPreclipped",
             [](LGFX& self, int32_t arg0, int32_t arg1, int32_t arg2, int32_t arg3, uint32_t arg4) {
                 self.writeFillRectPreclipped(arg0, arg1, arg2, arg3, arg4);
             })
        .def("writeFillRectPreclipped",
             static_cast<void (LGFX::*)(int32_t x, int32_t y, int32_t w, int32_t h)>(&LGFX::writeFillRectPreclipped))
        .def("writeColor", [](LGFX& self, uint32_t arg0, uint32_t arg1) { self.writeColor(arg0, arg1); })
        .def("pushBlock", [](LGFX& self, uint32_t arg0, uint32_t arg1) { self.pushBlock(arg0, arg1); })
        .def("drawPixel", static_cast<void (LGFX::*)(int32_t x, int32_t y)>(&LGFX::drawPixel))
        .def("drawPixel",
             [](LGFX& self, int32_t arg0, int32_t arg1, uint32_t arg2) { self.drawPixel(arg0, arg1, arg2); })
        .def("drawFastVLine", [](LGFX& self, int32_t arg0, int32_t arg1, int32_t arg2,
                                 uint32_t arg3) { self.drawFastVLine(arg0, arg1, arg2, arg3); })
        .def("drawFastVLine", static_cast<void (LGFX::*)(int32_t x, int32_t y, int32_t h)>(&LGFX::drawFastVLine))
        .def("drawFastHLine", [](LGFX& self, int32_t arg0, int32_t arg1, int32_t arg2,
                                 uint32_t arg3) { self.drawFastHLine(arg0, arg1, arg2, arg3); })
        .def("drawFastHLine", static_cast<void (LGFX::*)(int32_t x, int32_t y, int32_t w)>(&LGFX::drawFastHLine))
        .def("fillRect", [](LGFX& self, int32_t arg0, int32_t arg1, int32_t arg2, int32_t arg3,
                            uint32_t arg4) { self.fillRect(arg0, arg1, arg2, arg3, arg4); })
        .def("fillRect", static_cast<void (LGFX::*)(int32_t x, int32_t y, int32_t w, int32_t h)>(&LGFX::fillRect))
        .def("drawRect", [](LGFX& self, int32_t arg0, int32_t arg1, int32_t arg2, int32_t arg3,
                            uint32_t arg4) { self.drawRect(arg0, arg1, arg2, arg3, arg4); })
        .def("drawRect", static_cast<void (LGFX::*)(int32_t x, int32_t y, int32_t w, int32_t h)>(&LGFX::drawRect))
        .def("drawRoundRect", [](LGFX& self, int32_t arg0, int32_t arg1, int32_t arg2, int32_t arg3, int32_t arg4,
                                 uint32_t arg5) { self.drawRoundRect(arg0, arg1, arg2, arg3, arg4, arg5); })
        .def("drawRoundRect",
             static_cast<void (LGFX::*)(int32_t x, int32_t y, int32_t w, int32_t h, int32_t r)>(&LGFX::drawRoundRect))
        .def("fillRoundRect", [](LGFX& self, int32_t arg0, int32_t arg1, int32_t arg2, int32_t arg3, int32_t arg4,
                                 uint32_t arg5) { self.fillRoundRect(arg0, arg1, arg2, arg3, arg4, arg5); })
        .def("fillRoundRect",
             static_cast<void (LGFX::*)(int32_t x, int32_t y, int32_t w, int32_t h, int32_t r)>(&LGFX::fillRoundRect))
        .def("drawCircle", [](LGFX& self, int32_t arg0, int32_t arg1, int32_t arg2,
                              uint32_t arg3) { self.drawCircle(arg0, arg1, arg2, arg3); })
        .def("drawCircle", static_cast<void (LGFX::*)(int32_t x, int32_t y, int32_t r)>(&LGFX::drawCircle))
        .def("fillCircle", [](LGFX& self, int32_t arg0, int32_t arg1, int32_t arg2,
                              uint32_t arg3) { self.fillCircle(arg0, arg1, arg2, arg3); })
        .def("fillCircle", static_cast<void (LGFX::*)(int32_t x, int32_t y, int32_t r)>(&LGFX::fillCircle))
        .def("drawEllipse", [](LGFX& self, int32_t arg0, int32_t arg1, int32_t arg2, int32_t arg3,
                               uint32_t arg4) { self.drawEllipse(arg0, arg1, arg2, arg3, arg4); })
        .def("drawEllipse",
             static_cast<void (LGFX::*)(int32_t x, int32_t y, int32_t rx, int32_t ry)>(&LGFX::drawEllipse))
        .def("fillEllipse", [](LGFX& self, int32_t arg0, int32_t arg1, int32_t arg2, int32_t arg3,
                               uint32_t arg4) { self.fillEllipse(arg0, arg1, arg2, arg3, arg4); })
        .def("fillEllipse",
             static_cast<void (LGFX::*)(int32_t x, int32_t y, int32_t rx, int32_t ry)>(&LGFX::fillEllipse))
        .def("drawLine", [](LGFX& self, int32_t arg0, int32_t arg1, int32_t arg2, int32_t arg3,
                            uint32_t arg4) { self.drawLine(arg0, arg1, arg2, arg3, arg4); })
        .def("drawLine", static_cast<void (LGFX::*)(int32_t x0, int32_t y0, int32_t x1, int32_t y1)>(&LGFX::drawLine))
        .def("drawTriangle",
             [](LGFX& self, int32_t arg0, int32_t arg1, int32_t arg2, int32_t arg3, int32_t arg4, int32_t arg5,
                uint32_t arg6) { self.drawTriangle(arg0, arg1, arg2, arg3, arg4, arg5, arg6); })
        .def("drawTriangle",
             static_cast<void (LGFX::*)(int32_t x0, int32_t y0, int32_t x1, int32_t y1, int32_t x2, int32_t y2)>(
                 &LGFX::drawTriangle))
        .def("fillTriangle",
             [](LGFX& self, int32_t arg0, int32_t arg1, int32_t arg2, int32_t arg3, int32_t arg4, int32_t arg5,
                uint32_t arg6) { self.fillTriangle(arg0, arg1, arg2, arg3, arg4, arg5, arg6); })
        .def("fillTriangle",
             static_cast<void (LGFX::*)(int32_t x0, int32_t y0, int32_t x1, int32_t y1, int32_t x2, int32_t y2)>(
                 &LGFX::fillTriangle))
        .def("drawBezier",
             [](LGFX& self, int32_t arg0, int32_t arg1, int32_t arg2, int32_t arg3, int32_t arg4, int32_t arg5,
                uint32_t arg6) { self.drawBezier(arg0, arg1, arg2, arg3, arg4, arg5, arg6); })
        .def("drawBezier",
             static_cast<void (LGFX::*)(int32_t x0, int32_t y0, int32_t x1, int32_t y1, int32_t x2, int32_t y2)>(
                 &LGFX::drawBezier))
        .def("drawBezier", [](LGFX& self, int32_t arg0, int32_t arg1, int32_t arg2, int32_t arg3, int32_t arg4,
                              int32_t arg5, int32_t arg6, int32_t arg7,
                              uint32_t arg8) { self.drawBezier(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8); })
        .def("drawBezier", static_cast<void (LGFX::*)(int32_t x0, int32_t y0, int32_t x1, int32_t y1, int32_t x2,
                                                      int32_t y2, int32_t x3, int32_t y3)>(&LGFX::drawBezier))
        .def("drawEllipseArc",
             [](LGFX& self, int32_t arg0, int32_t arg1, int32_t arg2, int32_t arg3, int32_t arg4, int32_t arg5,
                float arg6, float arg7,
                uint32_t arg8) { self.drawEllipseArc(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8); })
        .def("drawEllipseArc",
             static_cast<void (LGFX::*)(int32_t x, int32_t y, int32_t r0x, int32_t r1x, int32_t r0y, int32_t r1y,
                                        float angle0, float angle1)>(&LGFX::drawEllipseArc))
        .def("fillEllipseArc",
             [](LGFX& self, int32_t arg0, int32_t arg1, int32_t arg2, int32_t arg3, int32_t arg4, int32_t arg5,
                float arg6, float arg7,
                uint32_t arg8) { self.fillEllipseArc(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8); })
        .def("fillEllipseArc",
             static_cast<void (LGFX::*)(int32_t x, int32_t y, int32_t r0x, int32_t r1x, int32_t r0y, int32_t r1y,
                                        float angle0, float angle1)>(&LGFX::fillEllipseArc))
        .def("drawArc", [](LGFX& self, int32_t arg0, int32_t arg1, int32_t arg2, int32_t arg3, float arg4, float arg5,
                           uint32_t arg6) { self.drawArc(arg0, arg1, arg2, arg3, arg4, arg5, arg6); })
        .def("drawArc",
             static_cast<void (LGFX::*)(int32_t x, int32_t y, int32_t r0, int32_t r1, float angle0, float angle1)>(
                 &LGFX::drawArc))
        .def("fillArc", [](LGFX& self, int32_t arg0, int32_t arg1, int32_t arg2, int32_t arg3, float arg4, float arg5,
                           uint32_t arg6) { self.fillArc(arg0, arg1, arg2, arg3, arg4, arg5, arg6); })
        .def("fillArc",
             static_cast<void (LGFX::*)(int32_t x, int32_t y, int32_t r0, int32_t r1, float angle0, float angle1)>(
                 &LGFX::fillArc))
        .def("drawCircleHelper", [](LGFX& self, int32_t arg0, int32_t arg1, int32_t arg2, uint_fast8_t arg3,
                                    uint32_t arg4) { self.drawCircleHelper(arg0, arg1, arg2, arg3, arg4); })
        .def("drawCircleHelper", static_cast<void (LGFX::*)(int32_t x, int32_t y, int32_t r, uint_fast8_t cornername)>(
                                     &LGFX::drawCircleHelper))
        .def("fillCircleHelper",
             [](LGFX& self, int32_t arg0, int32_t arg1, int32_t arg2, uint_fast8_t arg3, int32_t arg4, uint32_t arg5) {
                 self.fillCircleHelper(arg0, arg1, arg2, arg3, arg4, arg5);
             })
        .def("fillCircleHelper",
             static_cast<void (LGFX::*)(int32_t x, int32_t y, int32_t r, uint_fast8_t corners, int32_t delta)>(
                 &LGFX::fillCircleHelper))
        .def("floodFill",
             [](LGFX& self, int32_t arg0, int32_t arg1, uint32_t arg2) { self.floodFill(arg0, arg1, arg2); })
        .def("floodFill", static_cast<void (LGFX::*)(int32_t x, int32_t y)>(&LGFX::floodFill))
        .def("paint", [](LGFX& self, int32_t arg0, int32_t arg1, uint32_t arg2) { self.paint(arg0, arg1, arg2); })
        .def("paint", static_cast<void (LGFX::*)(int32_t x, int32_t y)>(&LGFX::paint))
        .def("fillAffine", [](LGFX& self, const float arg0[6], int32_t arg1, int32_t arg2,
                              uint32_t arg3) { self.fillAffine(arg0, arg1, arg2, arg3); })
        .def("fillAffine", static_cast<void (LGFX::*)(const float matrix[6], int32_t w, int32_t h)>(&LGFX::fillAffine))
        .def("drawSmoothLine", [](LGFX& self, int32_t arg0, int32_t arg1, int32_t arg2, int32_t arg3,
                                  uint32_t arg4) { self.drawSmoothLine(arg0, arg1, arg2, arg3, arg4); })
        .def("drawWideLine", [](LGFX& self, int32_t arg0, int32_t arg1, int32_t arg2, int32_t arg3, float arg4,
                                uint32_t arg5) { self.drawWideLine(arg0, arg1, arg2, arg3, arg4, arg5); })
        .def("drawWedgeLine",
             [](LGFX& self, int32_t arg0, int32_t arg1, int32_t arg2, int32_t arg3, float arg4, float arg5,
                uint32_t arg6) { self.drawWedgeLine(arg0, arg1, arg2, arg3, arg4, arg5, arg6); })
        .def("drawSpot", [](LGFX& self, int32_t arg0, int32_t arg1, float arg2,
                            uint32_t arg3) { self.drawSpot(arg0, arg1, arg2, arg3); })
        .def("fillSmoothRoundRect", [](LGFX& self, int32_t arg0, int32_t arg1, int32_t arg2, int32_t arg3, int32_t arg4,
                                       uint32_t arg5) { self.fillSmoothRoundRect(arg0, arg1, arg2, arg3, arg4, arg5); })
        .def("fillSmoothRoundRect", static_cast<void (LGFX::*)(int32_t x, int32_t y, int32_t w, int32_t h, int32_t r)>(
                                        &LGFX::fillSmoothRoundRect))
        .def("fillSmoothCircle", [](LGFX& self, int32_t arg0, int32_t arg1, int32_t arg2,
                                    uint32_t arg3) { self.fillSmoothCircle(arg0, arg1, arg2, arg3); })
        .def("fillSmoothCircle", static_cast<void (LGFX::*)(int32_t x, int32_t y, int32_t r)>(&LGFX::fillSmoothCircle))
        .def("fillScreen", [](LGFX& self, uint32_t arg0) { self.fillScreen(arg0); })
        .def("fillScreen", static_cast<void (LGFX::*)(void)>(&LGFX::fillScreen))
        .def("clear", [](LGFX& self, uint32_t arg0) { self.clear(arg0); })
        .def("clear", static_cast<void (LGFX::*)(void)>(&LGFX::clear))
        .def("clearDisplay", [](LGFX& self, uint32_t arg0) { self.clearDisplay(arg0); })
        .def("clearDisplay", static_cast<void (LGFX::*)(void)>(&LGFX::clearDisplay))
        .def("setPivot", &LGFX::setPivot)
        .def("getPivotX", &LGFX::getPivotX)
        .def("getPivotY", &LGFX::getPivotY)
        .def("width", &LGFX::width)
        .def("height", &LGFX::height)
        .def("setScrollRect", [](LGFX& self, int32_t arg0, int32_t arg1, int32_t arg2, int32_t arg3,
                                 uint32_t arg4) { self.setScrollRect(arg0, arg1, arg2, arg3, arg4); })
        .def("setScrollRect",
             static_cast<void (LGFX::*)(int32_t x, int32_t y, int32_t w, int32_t h)>(&LGFX::setScrollRect))
        .def("writePixels",
             static_cast<void (LGFX::*)(const uint16_t* data, int32_t len, bool swap)>(&LGFX::writePixels))
        .def("pushPixels", static_cast<void (LGFX::*)(const uint16_t* data, int32_t len, bool swap)>(&LGFX::pushPixels))
        .def("fillRectAlpha", [](LGFX& self, int32_t arg0, int32_t arg1, int32_t arg2, int32_t arg3, uint8_t arg4,
                                 uint32_t arg5) { self.fillRectAlpha(arg0, arg1, arg2, arg3, arg4, arg5); })
        .def("drawBitmap", [](LGFX& self, int32_t arg0, int32_t arg1, const uint8_t* arg2, int32_t arg3, int32_t arg4,
                              uint32_t arg5) { self.drawBitmap(arg0, arg1, arg2, arg3, arg4, arg5); })
        .def("drawBitmap",
             [](LGFX& self, int32_t arg0, int32_t arg1, const uint8_t* arg2, int32_t arg3, int32_t arg4, uint32_t arg5,
                uint32_t arg6) { self.drawBitmap(arg0, arg1, arg2, arg3, arg4, arg5, arg6); })
        .def("drawXBitmap", [](LGFX& self, int32_t arg0, int32_t arg1, const uint8_t* arg2, int32_t arg3, int32_t arg4,
                               uint32_t arg5) { self.drawXBitmap(arg0, arg1, arg2, arg3, arg4, arg5); })
        .def("drawXBitmap",
             [](LGFX& self, int32_t arg0, int32_t arg1, const uint8_t* arg2, int32_t arg3, int32_t arg4, uint32_t arg5,
                uint32_t arg6) { self.drawXBitmap(arg0, arg1, arg2, arg3, arg4, arg5, arg6); })
        .def("getRotation", &LGFX::getRotation)
        .def("setRotation", &LGFX::setRotation)
        .def("setColorDepth", static_cast<void (LGFX::*)(int bits)>(&LGFX::setColorDepth))
        .def("scroll", &LGFX::scroll)
        .def("setCursor", static_cast<void (LGFX::*)(int32_t x, int32_t y)>(&LGFX::setCursor))
        .def("getCursorX", &LGFX::getCursorX)
        .def("getCursorY", &LGFX::getCursorY)
        .def("setTextSize", static_cast<void (LGFX::*)(float size)>(&LGFX::setTextSize))
        .def("setTextSize", static_cast<void (LGFX::*)(float sx, float sy)>(&LGFX::setTextSize))
        .def("getTextSizeX", &LGFX::getTextSizeX)
        .def("getTextSizeY", &LGFX::getTextSizeY)
        .def("setTextDatum", static_cast<void (LGFX::*)(uint8_t datum)>(&LGFX::setTextDatum))
        .def("setTextDatum", static_cast<void (LGFX::*)(textdatum_t datum)>(&LGFX::setTextDatum))
        .def("getTextDatum", &LGFX::getTextDatum)
        .def("setTextPadding", &LGFX::setTextPadding)
        .def("getTextPadding", &LGFX::getTextPadding)
        .def("setTextWrap", &LGFX::setTextWrap)
        .def("setTextScroll", &LGFX::setTextScroll)
        .def("setTextColor", [](LGFX& self, uint32_t arg0) { self.setTextColor(arg0); })
        .def("setTextColor", [](LGFX& self, uint32_t arg0, uint32_t arg1) { self.setTextColor(arg0, arg1); })
        .def("fontHeight",
             [](LGFX& self, unsigned long long font) -> int { return self.fontHeight((const lgfx::GFXfont*)font); })
        .def(
            "setTextFont", [](LGFX& self, int f) -> void { self.setTextFont(f); }, pybind11::arg("f"))
        .def(
            "loadFont", [](LGFX& self, const std::string& path) -> void { self.loadFont(path.c_str()); },
            pybind11::arg("path"))
        .def("unloadFont", [](LGFX& self) -> void { self.unloadFont(); })
        .def("setFont", [](LGFX& self, int font) -> void {})
        .def("drawString", static_cast<size_t (LGFX::*)(const char* string, int32_t x, int32_t y)>(&LGFX::drawString))
        .def("drawNumber", static_cast<size_t (LGFX::*)(long long_num, int32_t poX, int32_t poY)>(&LGFX::drawNumber))
        .def("drawFloat",
             static_cast<size_t (LGFX::*)(float floatNumber, uint8_t dp, int32_t poX, int32_t poY)>(&LGFX::drawFloat))
        .def("drawCentreString",
             static_cast<size_t (LGFX::*)(const char* string, int32_t x, int32_t y)>(&LGFX::drawCentreString))
        .def("drawRightString",
             static_cast<size_t (LGFX::*)(const char* string, int32_t x, int32_t y)>(&LGFX::drawRightString));
}
