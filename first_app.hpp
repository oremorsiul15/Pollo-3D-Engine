#pragma once

#include "pollo_window.hpp"
#include "pollo_pipeline.hpp"
#include "pollo_device.hpp"

namespace pollo
{
    class FirstApp
    {
    public:
        static constexpr int WIDTH = 800;
        static constexpr int HEIGHT = 600;

        void run();

    private:
        PolloWindow polloWindow{WIDTH, HEIGHT, "Pollo 3D"};
        PolloDevice polloDevice{polloWindow};
        PolloPipeline polloPipeline{
            polloDevice,
            "shaders/simple_shader.vert.spv",
            "shaders/simple_shader.frag.spv",
            PolloPipeline::defaultPipelineConfigInfo(WIDTH, HEIGHT)};
    };
} // namespace pollo
