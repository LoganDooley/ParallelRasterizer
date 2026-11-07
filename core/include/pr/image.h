#pragma once

#include <cstdint>
#include <cstddef>
#include <vector>

namespace pr {
    class Image {
    public:
        Image(size_t width, size_t height);

        void clear(uint8_t r, uint8_t g, uint8_t b, uint8_t a);

        uint32_t* data() { return m_data.data(); }
        const uint32_t* data() const { return m_data.data(); }

        size_t width() const { return m_width; }
        size_t height() const { return m_height; }

        void drawPixel(int x, int y, uint8_t r, uint8_t g, uint8_t b, uint8_t a);

    private:
        static uint32_t packColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a);

        size_t m_width = 0;
        size_t m_height = 0;
        std::vector<uint32_t> m_data;
    };
}