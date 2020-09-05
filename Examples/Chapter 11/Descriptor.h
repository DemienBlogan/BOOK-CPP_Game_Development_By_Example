#pragma once

#include <vector>
#include <vulkan\vulkan.h>

class Descriptor
{
private:
	void createDescriptorSetLayout();
	void createDescriptorPoolAndAllocateSets(uint32_t _swapChainImageCount);

public:
	VkDescriptorSetLayout descriptorSetLayout;
	VkDescriptorPool descriptorPool;
	VkDescriptorSet descriptorSet;

	Descriptor();
	~Descriptor();

	void createDescriptorLayoutSetPoolAndAllocate(uint32_t _swapChainImageCount);
	void populateDescriptorSets(uint32_t _swapChainImageCount, VkBuffer uniformBuffers);
	void destroy();
};