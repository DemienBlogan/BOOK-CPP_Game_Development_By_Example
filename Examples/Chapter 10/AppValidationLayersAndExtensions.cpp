#include "AppValidationLayersAndExtensions.h"

AppValidationLayersAndExtensions::AppValidationLayersAndExtensions()
{ }

AppValidationLayersAndExtensions::~AppValidationLayersAndExtensions()
{ }

bool AppValidationLayersAndExtensions::checkValidationLayerSupport()
{

	uint32_t layerCount;
	vkEnumerateInstanceLayerProperties(&layerCount, nullptr);
	std::vector<VkLayerProperties> availableLayers(layerCount);

	vkEnumerateInstanceLayerProperties(&layerCount, availableLayers.data());

	for (const char* layerName : requiredValidationLayers)
	{
		bool layerFound = false;

		for (const auto& layerproperties : availableLayers)
		{
			if (strcmp(layerName, layerproperties.layerName) == 0)
			{
				layerFound = true;
				break;
			}
		}

		if (!layerFound)
			return false;

		return true;
	}

}

std::vector<const char*> AppValidationLayersAndExtensions::getRequiredExtensions(
	bool isValidationLayersEnabled)
{
	uint32_t glfwExtensionCount = 0;
	const char** glfwExtensions;

	glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

	std::vector<const char*> extensions(glfwExtensions, glfwExtensions + glfwExtensionCount);

	if (isValidationLayersEnabled)
		extensions.push_back("VK_EXT_debug_report");

	return extensions;
}

static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(
	VkDebugReportFlagsEXT flags,
	VkDebugReportObjectTypeEXT objExt,
	uint64_t obj,
	size_t location,
	int32_t code,
	const char* layerPrefix,
	const char* msg,
	void* userData)
{
	std::cerr << "validation layer: " << msg << std::endl << std::endl;

	return false;
}


void AppValidationLayersAndExtensions::setupDebugCallback(
	bool isValidationLayersEnabled,
	VkInstance vkInstance)
{
	if (!isValidationLayersEnabled)
		return;

	printf("setup call back \n");

	VkDebugReportCallbackCreateInfoEXT info = {};

	info.sType = VK_STRUCTURE_TYPE_DEBUG_REPORT_CALLBACK_CREATE_INFO_EXT;
	info.flags = VK_DEBUG_REPORT_ERROR_BIT_EXT | VK_DEBUG_REPORT_WARNING_BIT_EXT;
	info.pfnCallback = debugCallback;

	if (createDebugReportCallbackEXT(vkInstance, &info, nullptr, &callback) != VK_SUCCESS)
		throw std::runtime_error("failed to set debug callback!");
}

void AppValidationLayersAndExtensions::destroy(
	VkInstance instance,
	bool isValidationLayersEnabled)
{
	if (isValidationLayersEnabled)
		DestroyDebugReportCallbackEXT(instance, callback, nullptr);
}