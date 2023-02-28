#include "first_app.hpp"

namespace pollo
{
    void FirstApp::run()
    {
        while (!polloWindow.shouldClose())
        {
            glfwPollEvents();
        }
    }
} // namespace pollo
