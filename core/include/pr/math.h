#pragma once

#include <algorithm>

namespace pr {
    template <typename T>
    struct Vec2 {
        union {
            struct { T x, y; };
            T data[2];
        };
        Vec2() : x(0), y(0) {}
        explicit Vec2(T scalar) : x(scalar), y(scalar) {}
        Vec2(T valX, T valY) : x(valX), y(valY) {}
        T& operator[](size_t i) { return data[i]; }
    };

    template <typename T>
    struct Vec3 {
        union {
            struct { T x, y, z; };
            struct { T r, g, b; };
            T data[3];
        };
        Vec3() : x(0), y(0), z(0) {}
        explicit Vec3(T scalar) : x(scalar), y(scalar), z(scalar) {}
        Vec3(T valX, T valY, T valZ) : x(valX), y(valY), z(valZ) {}
        T& operator[](size_t i) { return data[i]; }
    };

    template <typename T>
    struct Vec4 {
        union {
            struct { T x, y, z, w; };
            struct { T r, g, b, a; };
            T data[4];
        };
        Vec4() : x(0), y(0), z(0), w(0) {}
        explicit Vec4(T scalar) : x(scalar), y(scalar), z(scalar), w(scalar) {}
        Vec4(T valX, T valY, T valZ, T valW) : x(valX), y(valY), z(valZ), w(valW) {}
        T& operator[](size_t i) { return data[i]; }
    };

    template <typename T>
    inline Vec2<T> operator+(const Vec2<T>& v1, const Vec2<T>& v2) {
        return Vec2<T>(v1.x + v2.x, v1.y + v2.y);
    }

    template <typename T>
    inline Vec2<T> operator-(const Vec2<T>& v1, const Vec2<T>& v2) {
        return Vec2<T>(v1.x - v2.x, v1.y - v2.y);
    }

    template <typename T>
    inline T dot(const Vec2<T>& v1, const Vec2<T>& v2) {
        return (v1.x * v2.x) + (v1.y * v2.y);
    }

    template <typename T>
    inline T cross(const Vec2<T>& v1, const Vec2<T>& v2) {
        return v1.x * v2.y - v2.x * v1.y;
    }

    template <typename T>
    inline Vec2<T> min(const Vec2<T>& v1, const Vec2<T>& v2) {
        return Vec2<T>(std::min(v1.x, v2.x), std::min(v1.y, v2.y));
    }

    template <typename T>
    inline Vec2<T> max(const Vec2<T>& v1, const Vec2<T>& v2) {
        return Vec2<T>(std::max(v1.x, v2.x), std::max(v1.y, v2.y));
    }

    template <typename T>
    inline Vec2<T> clamp(const Vec2<T>& v, const Vec2<T>& vMin, const Vec2<T>& vMax) {
        return max(min(v, vMax), vMin);
    }
}