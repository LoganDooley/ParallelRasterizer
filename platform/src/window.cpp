#include <pr/window.h>

#include <pr/image.h>

#define GLFW_EXPOSE_NATIVE_WIN32
#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>

#include <stdexcept>

namespace pr{
    Window::Window(int width, int height, const char* title, GLFWContext& context) {
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

        m_glfwWindow = glfwCreateWindow(width, height, title, nullptr, nullptr);
        if(!m_glfwWindow){
            throw std::runtime_error("Failed to create GLFW window");
        }
    }

    Window::~Window() {
        if(m_glfwWindow != nullptr){
            glfwDestroyWindow(m_glfwWindow);
        }
    }

    bool Window::shouldClose() const
    {
        return glfwWindowShouldClose(m_glfwWindow);
    }

    void Window::present(const Image &image)
    {
        HWND hwnd = glfwGetWin32Window(m_glfwWindow);
        HDC hdc = GetDC(hwnd);

        BITMAPINFO bmi{};
        bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
        bmi.bmiHeader.biWidth = static_cast<LONG>(image.width());
        bmi.bmiHeader.biHeight = -static_cast<LONG>(image.height());
        bmi.bmiHeader.biPlanes = 1;
        bmi.bmiHeader.biBitCount = 32;
        bmi.bmiHeader.biCompression = BI_RGB;

        SetStretchBltMode(hdc, COLORONCOLOR);
        StretchDIBits(hdc, 
            0, 0, static_cast<int>(image.width()), static_cast<int>(image.height()), 
            0, 0, static_cast<int>(image.width()), static_cast<int>(image.height()), 
            image.data(), &bmi, DIB_RGB_COLORS, SRCCOPY);

        ReleaseDC(hwnd, hdc);
    }
}