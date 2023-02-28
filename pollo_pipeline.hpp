#pragma once

#include "pollo_device.hpp"

// std
#include <string>
#include <vector>

namespace pollo
{
    struct PipelineConfigInfo
    {
        VkPipelineInputAssemblyStateCreateInfo inputAssemblyInfo;
    };
    class PolloPipeline
    {
    public:
        PolloPipeline(PolloDevice &device,
                      const std::string &vertFilePath,
                      const std::string &fragFilePath,
                      const PipelineConfigInfo &configInfo);
        ~PolloPipeline() {}

        PolloPipeline(const PolloPipeline &) = delete;
        void operator=(const PolloPipeline &) = delete;

        static PipelineConfigInfo defaultPipelineConfigInfo(uint32_t wigth, uint32_t height);

    private:
        static std::vector<char>
        readFile(const std::string &filePath);
        void createGraphicsPipeline(const std::string &vertFilePath,
                                    const std::string &fragFilePath,
                                    const PipelineConfigInfo &configInfo);

        void createShaderModule(const std::vector<char> &code, VkShaderModule *shaderModule);

        PolloDevice &polloDevice;
        VkPipeline graphicsPipeline;
        VkShaderModule vertShaderModule;
        VkShaderModule fragShaderModule;
    };
} // namespace pollo
