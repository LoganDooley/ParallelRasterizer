#pragma once

struct GLFWwindow;

namespace pr {
    class Image;
    class GLFWContext;

    class Window {
    public:
        Window(int width, int height, const char* title, GLFWContext& context);
        ~Window();

        Window(const Window&) = delete;
        Window& operator=(const Window&) = delete;
        Window(Window&&) = delete; 
        Window& operator=(Window&&) = delete;

        bool shouldClose() const;

        void present(const Image& image);

    private:
        GLFWwindow* m_glfwWindow = nullptr;
    };
}