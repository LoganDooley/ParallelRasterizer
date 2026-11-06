#include <pr/glfw_context.h>

#include <GLFW/glfw3.h>

#include <stdexcept>

namespace pr {
    GLFWContext::GLFWContext(){
        if(!glfwInit()){
            throw std::runtime_error("GLFW failed to init");
        }
    }

    GLFWContext::~GLFWContext(){
        glfwTerminate();
    }

    void GLFWContext::pollEvents()
    {
        glfwPollEvents();
    }
}