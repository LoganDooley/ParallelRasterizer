#pragma once

#include <pr/math.h>

#include <cstdint>

namespace pr {
    class Image;

    void drawTriangle(Image& image, const Vec2<float>& v0, const Vec2<float>& v1, const Vec2<float>& v2, 
        uint8_t r, uint8_t g, uint8_t b, uint8_t a);
}