#pragma once

namespace pr
{
    class GLFWContext{
    public:
        GLFWContext();
        ~GLFWContext();

        GLFWContext(const GLFWContext&) = delete;
        GLFWContext& operator=(const GLFWContext&) = delete;
        GLFWContext(GLFWContext&&) = delete; 
        GLFWContext& operator=(GLFWContext&&) = delete;

        void pollEvents();
    };
}