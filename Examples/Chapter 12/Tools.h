#pragma once

#include <stdexcept>
#include <vector>

#include <vulkan\vulkan.h>

namespace vkTools
{
	VkImageView createImageView(VkImage image, VkFormat format, VkImageAspectFlags aspectFlags);

	uint32_t findMemoryTypeIndex(uint32_t typeFilter, VkMemoryPropertyFlags properties);

	void createBuffer(VkDeviceSize size,
		VkBufferUsageFlags usage,
		VkMemoryPropertyFlags properties,
		VkBuffer& buffer,
		VkDeviceMemory& bufferMemory);

	VkCommandBuffer beginSingleTimeCommands(VkCommandPool commandPool);

	void endSingleTimeCommands(VkCommandBuffer commandBuffer, VkCommandPool commandPool);

	void copyBuffer(VkBuffer srcBuffer,
		VkBuffer dstBuffer,
		VkDeviceSize size);
}