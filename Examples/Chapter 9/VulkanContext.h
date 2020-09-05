#pragma once

#include <vulkan/vulkan.h>
#include "AppValidationLayersAndExtensions.h"
#include "VulkanInstance.h"
#include "Device.h"

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#ifdef _DEBUG
const bool isValidationLayersEnabled = true;
#else
const bool isValidationLayersEnabled = false;
#endif

class VulkanContext
{
private:
	AppValidationLayersAndExtensions* valLayersAndExt;
	VulkanInstance* vInstance;
	VkSurfaceKHR surface;
	Device* device;

public:
	static VulkanContext* instance;

	~VulkanContext();

	static VulkanContext* getInstance();
	void initVulkan(GLFWwindow* window);
};