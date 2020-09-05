#include "VulkanContext.h"

VulkanContext* VulkanContext::instance = nullptr;

VulkanContext::~VulkanContext()
{ }

VulkanContext* VulkanContext::getInstance()
{
	if (!instance)
		instance = new VulkanContext();

	return instance;
}

void VulkanContext::initVulkan(GLFWwindow* window)
{
	valLayersAndExt = new AppValidationLayersAndExtensions();

	if (isValidationLayersEnabled && !valLayersAndExt->checkValidationLayerSupport())
		throw std::runtime_error("Validation Layers Not Available!");

	vInstance = new VulkanInstance();
	vInstance->createAppAndVkInstance(isValidationLayersEnabled, valLayersAndExt);

	valLayersAndExt->setupDebugCallback(isValidationLayersEnabled, vInstance->vkInstance);

	if (glfwCreateWindowSurface(vInstance->vkInstance, window, nullptr, &surface) != VK_SUCCESS)
		throw std::runtime_error("failed to create window surface!");

	device = new Device();
	device->pickPhysicalDevice(vInstance, surface);
	device->createLogicalDevice(surface, isValidationLayersEnabled, valLayersAndExt);
}