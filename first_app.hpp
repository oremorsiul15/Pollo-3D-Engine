#pragma once

#include "pollo_window.hpp"
#include "pollo_pipeline.hpp"

namespace pollo
{
    class FirstApp
    {
    public:
        static constexpr int WIDTH = 800;
        static constexpr int HEIGHT = 600;

        void run();

    private:
        PolloWindow polloWindow{WIDTH, HEIGHT, "Hello Vulkan"};
        PolloPipeline polloPipeline{"shaders/simple_shader.vert.spv", "shaders/simple_shader.frag.spv"};
    };
} // namespace pollo
