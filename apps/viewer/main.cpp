#include <pr/core.h>
#include <pr/glfw_context.h>
#include <pr/window.h>
#include <pr/image.h>

int main()
{
    printHello();
    pr::GLFWContext glfwContext = pr::GLFWContext();
    pr::Window window = pr::Window(800, 600, "Parallel Rasterizer", glfwContext);
    pr::Image colorImage = pr::Image(800, 600);
    colorImage.clear(255, 0, 0, 255);
    while(!window.shouldClose()){
        glfwContext.pollEvents();
        window.present(colorImage);
    }
    return 0;
}