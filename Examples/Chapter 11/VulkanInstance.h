#pragma once

#include <vulkan\vulkan.h>

#include "AppValidationLayersAndExtensions.h"

class VulkanInstance
{
public:
	VkInstance vkInstance;

	VulkanInstance();
	~VulkanInstance();

	void createAppAndVkInstance(bool enableValidationLayers, AppValidationLayersAndExtensions *valLayersAndExtentions);
};