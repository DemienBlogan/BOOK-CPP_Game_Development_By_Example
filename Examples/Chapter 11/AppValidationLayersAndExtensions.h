#pragma once

#define GLFW_INCLUDE_VULKAN

#include <vector>
#include <iostream>
#include <vulkan\vulkan.h>
#include <GLFW\glfw3.h>

class AppValidationLayersAndExtensions
{
public:
	const std::vector<const char*> requiredValidationLayers = { "VK_LAYER_LUNARG_standard_validation" };
	VkDebugReportCallbackEXT callback;
	AppValidationLayersAndExtensions();
	~AppValidationLayersAndExtensions();
	bool checkValidationLayerSupport();
	std::vector<const char*> getRequiredExtensions(bool isValidationLayersEnabled);
	void setupDebugCallback(bool isValidationLayersEnabled, VkInstance vkInstance);
	void destroy(VkInstance instance, bool isValidationLayersEnabled);

	VkResult createDebugReportCallbackEXT(
		VkInstance instance,
		const VkDebugReportCallbackCreateInfoEXT* pCreateInfo,
		const VkAllocationCallbacks* pAllocator,
		VkDebugReportCallbackEXT* pCallback)
	{
		auto func = (PFN_vkCreateDebugReportCallbackEXT)vkGetInstanceProcAddr(instance, "vkCreateDebugReportCallbackEXT");

		if (func != nullptr)
			return func(instance, pCreateInfo, pAllocator, pCallback);
		else
			return VK_ERROR_EXTENSION_NOT_PRESENT;
	}

	void DestroyDebugReportCallbackEXT(
		VkInstance instance,
		VkDebugReportCallbackEXT callback,
		const VkAllocationCallbacks* pAllocator)
	{
		auto func = (PFN_vkDestroyDebugReportCallbackEXT)vkGetInstanceProcAddr(instance, "vkDestroyDebugReportCallbackEXT");
		if (func != nullptr)
			func(instance, callback, pAllocator);
	}
};