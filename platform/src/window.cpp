#include <pr/window.h>

#include <GLFW/glfw3.h>

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
}