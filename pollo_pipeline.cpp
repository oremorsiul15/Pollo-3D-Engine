#include "pollo_pipeline.hpp"

#include <fstream>
#include <stdexcept>
#include <iostream>
namespace pollo
{
    PolloPipeline::PolloPipeline(const std::string &vertFilePath, const std::string &fragFilePath)
    {
        createGraphicsPipeline(vertFilePath, fragFilePath);
    }

    std::vector<char> PolloPipeline::readFile(const std::string &filePath)
    {
        std::ifstream file{filePath, std::ios::ate | std::ios::binary};
        if (!file.is_open())
        {
            std::runtime_error("failed to open file " + filePath);
        }

        size_t fileSize = static_cast<size_t>(file.tellg());
        std::vector<char> buffer(fileSize);

        file.seekg(0);
        file.read(buffer.data(), fileSize);
        file.close();
        return buffer;
    }

    void PolloPipeline::createGraphicsPipeline(const std::string &vertFilePath, const std::string &fragFilePath)
    {
        auto vertCode = readFile(vertFilePath);
        auto fragCode = readFile(fragFilePath);

        std::cout << "Vertex shader code size is: " << vertCode.size() << std::endl;
        std::cout << "Fragment shader code size is: " << fragCode.size() << std::endl;
    }
} // namespace pollo
