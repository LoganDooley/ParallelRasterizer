#include <pr/core.h>
#include <pr/glfw_context.h>
#include <pr/window.h>
#include <pr/image.h>
#include <pr/math.h>
#include <pr/raster.h>

#include <chrono>
#include <string>

int main()
{
    printHello();
    std::chrono::time_point lastFrame = std::chrono::steady_clock::now();
    pr::GLFWContext glfwContext = pr::GLFWContext();
    pr::Window window = pr::Window(800, 600, "Parallel Rasterizer", glfwContext);
    int width, height;
    window.getSize(width, height);
    pr::Image colorImage = pr::Image(width, height);
    colorImage.clear(255, 0, 0, 255);

    double totalClearTime = 0.0f;
    double totalPresentTime = 0.0f;
    int statsFrames = 0;

    pr::Vec2<float> v0 { -100.0, 0.0 };
    pr::Vec2<float> v1 { 0.0, 50.0 };
    pr::Vec2<float> v2 { 40.0, 50.0 };

    while(!window.shouldClose()){
        glfwContext.pollEvents();

        // Check for window resize
        int newWidth, newHeight;
        window.getSize(newWidth, newHeight);
        if(newWidth != width || newHeight != height){
            width = newWidth;
            height = newHeight;
            colorImage = pr::Image(width, height);
        }

        std::chrono::time_point beforeClear = std::chrono::steady_clock::now();
        colorImage.clear(255, 0, 0, 255);
        std::chrono::time_point afterClear = std::chrono::steady_clock::now();

        // Draw
        drawTriangle(colorImage, v0, v1, v2, 
        0, 255, 0, 255);

        window.present(colorImage);
        std::chrono::time_point afterPresent = std::chrono::steady_clock::now();
    
        // Stats
        auto currentClearTime = std::chrono::steady_clock::duration(afterClear - beforeClear).count();
        auto currentPresentTime = std::chrono::steady_clock::duration(afterPresent - afterClear).count();
        totalClearTime += currentClearTime;
        totalPresentTime += currentPresentTime;
        statsFrames++;

        float clearMs = 1e-6 * totalClearTime / static_cast<float>(statsFrames);
        float presentMs = 1e-6 * totalPresentTime / static_cast<float>(statsFrames);
        std::string title = "Clear MS: " + std::to_string(clearMs) + " Present MS: " + std::to_string(presentMs);
        window.setTitle(title.c_str());
    }
    return 0;
}