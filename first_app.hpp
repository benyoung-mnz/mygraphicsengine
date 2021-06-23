#pragma once

#include "lve_window.hpp"
#include "lve_pipeline.hpp"
#include "lve_game_object.hpp"
#include "lve_device.hpp"
#include "lve_swap_chain.hpp"

// std
#include <memory>
#include <vector>

namespace m_lve
{
    class FirstApp
    {
    private:
        void loadGameObjects(); 
        void createPipelineLayout();
        void createPipeline();
        void createCommandBuffers();
        void freeCommandBuffers();
        void drawFrame();
        void recreateSwapChain();
        void recordCommandBuffer(int imageIndex);
        void renderGameObjects(VkCommandBuffer commandBuffer);

        LveWindow lveWindow{WIDTH, HEIGHT, "Hello Vulkan!"};
        LveDevice lveDevice{lveWindow};
        std::unique_ptr<LveSwapChain> lveSwapChain;
        std::unique_ptr<LvePipeline> lvePipeline;
        VkPipelineLayout pipelineLayout;
        std::vector<VkCommandBuffer> commandBuffers;
        std::vector<LveGameObject> gameObjects;

    public:
        static constexpr int WIDTH = 800;
        static constexpr int HEIGHT = 600;

        FirstApp();
        ~FirstApp();

        FirstApp(const FirstApp &) = delete;
        FirstApp &operator=(const FirstApp &) = delete;

        void run();
    };

} // namespace m_lve
