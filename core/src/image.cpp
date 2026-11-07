#include <pr/image.h>

#include <algorithm>
#include <cassert>

namespace pr {
    Image::Image(size_t width, size_t height) :
        m_width(width),
        m_height(height),
        m_data(width * height, 0)
    {

    }

    void Image::clear(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
    {
        uint32_t packedColor = packColor(r, g, b, a);
        std::fill(m_data.begin(), m_data.end(), packedColor);
    }

    void Image::drawPixel(int x, int y, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
    {
        assert(x >= 0 && x < m_width && y >= 0 && y < m_height);
        m_data[x + y * m_width] = packColor(r, g, b, a);
    }

    uint32_t Image::packColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
    {
        return (static_cast<uint32_t>(a) << 24) | 
            (static_cast<uint32_t>(r) << 16) |
            (static_cast<uint32_t>(g) << 8) |
            (static_cast<uint32_t>(b));
    }
}