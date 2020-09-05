#pragma once

#include <vector>
#include <vulkan\vulkan.h>

class DrawCommandBuffer
{
public:
	VkCommandPool commandPool;
	std::vector<VkCommandBuffer> commandBuffers;

	DrawCommandBuffer();
	~DrawCommandBuffer();

	void createCommandPoolAndBuffer(size_t imageCount);
	void beginCommandBuffer(VkCommandBuffer commandBuffer);
	void endCommandBuffer(VkCommandBuffer commandBuffer);
	void createCommandPool();
	void allocateCommandBuffers(size_t imageCount);
	void destroy();
};