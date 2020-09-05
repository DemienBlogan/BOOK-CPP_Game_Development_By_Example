#pragma once

#include <array>
#include <vulkan\vulkan.h>

class Renderpass
{
public:
	VkRenderPass renderPass;

	Renderpass();
	~Renderpass();

	void createRenderPass(VkFormat swapChainImageFormat);
	void beginRenderPass(
		std::array<VkClearValue, 1> clearValues,
		VkCommandBuffer commandBuffer,
		VkFramebuffer swapChainFrameBuffer,
		VkExtent2D swapChainImageExtent);
	void endRenderPass(VkCommandBuffer commandBuffer);
	void destroy();
};