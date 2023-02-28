#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <string>

namespace pollo
{
    class PolloWindow
    {
    public:
        PolloWindow(int w, int h, std::string name);
        ~PolloWindow();

        PolloWindow(const PolloWindow &) = delete;
        PolloWindow &operator=(const PolloWindow &) = delete;

        bool shouldClose()
        {
            return glfwWindowShouldClose(window);
        }

        void createWindowSurface(VkInstance instance, VkSurfaceKHR *surface);

    private:
        void
        initWindow();
        const int width;
        const int height;

        std::string windowName;

        GLFWwindow *window;
    };
} // namespace pollo_window
