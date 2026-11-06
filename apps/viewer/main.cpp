#include <pr/core.h>
#include <pr/glfw_context.h>
#include <pr/window.h>

int main()
{
    printHello();
    pr::GLFWContext glfwContext = pr::GLFWContext();
    pr::Window window = pr::Window(800, 600, "Parallel Rasterizer", glfwContext);
    while(!window.shouldClose()){
        glfwContext.pollEvents();
    }
    return 0;
}