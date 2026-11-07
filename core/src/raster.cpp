#include <pr/raster.h>

#include <pr/image.h>

#include <cmath>

namespace pr {
    void drawTriangle(Image& image, const Vec2<float>& v0, const Vec2<float>& v1, const Vec2<float>& v2, 
        uint8_t r, uint8_t g, uint8_t b, uint8_t a)
    {
        Vec2<int> imageMin = Vec2<int>(0);
        Vec2<int> imageMax = Vec2<int>(static_cast<int>(image.width() - 1), static_cast<int>(image.height() - 1));

        Vec2<int> minPixel;
        minPixel.x = static_cast<int>(std::fminf(v0.x, std::fminf(v1.x, v2.x)));
        minPixel.y = static_cast<int>(std::fminf(v0.y, std::fminf(v1.y, v2.y)));
        minPixel = clamp(minPixel, imageMin, imageMax);

        Vec2<int> maxPixel;
        maxPixel.x = static_cast<int>(std::fmaxf(v0.x, std::fmaxf(v1.x, v2.x)));
        maxPixel.y = static_cast<int>(std::fmaxf(v0.y, std::fmaxf(v1.y, v2.y)));
        maxPixel = clamp(maxPixel, imageMin, imageMax);

        Vec2<float> e0 = v1 - v0;
        Vec2<float> e1 = v2 - v1;
        Vec2<float> e2 = v0 - v2;

        e0 = Vec2<float>(e0.y, -e0.x);
        e1 = Vec2<float>(e1.y, -e1.x);
        e2 = Vec2<float>(e2.y, -e2.x);

        if(dot(v2 - v0, e0) <= 0.0f) {
            return;
        }

        for(int y = minPixel.y; y <= maxPixel.y; y++){
            for (int x = minPixel.x; x <= maxPixel.x; x++){
                Vec2<float> p = Vec2<float>(static_cast<float>(x), static_cast<float>(y)) + Vec2<float>(0.5f, 0.5f);

                Vec2<float> t0 = p - v0;
                if(dot(t0, e0) <= 0.0f){
                    continue;
                }

                Vec2<float> t1 = p - v1;
                if(dot(t1, e1) <= 0.0f){
                    continue;
                }

                Vec2<float> t2 = p - v2;
                if(dot(t2, e2) <= 0.0f){
                    continue;
                }

                image.drawPixel(x, y, r, g, b, a);
            }
        }
    }

}