#include "VulkanContext.h"

VulkanContext* VulkanContext::instance = nullptr;

VulkanContext* VulkanContext::getInstance()
{
	if (!instance)
		instance = new VulkanContext();

	return instance;
}

VulkanContext::~VulkanContext()
{
	if (instance)
	{
		delete instance;
		instance = nullptr;
	}
}

void VulkanContext::initVulkan(GLFWwindow* window)
{
	valLayersAndExt = new AppValidationLayersAndExtensions();

	if (isValidationLayersEnabled && !valLayersAndExt->checkValidationLayerSupport())
		throw std::runtime_error("alidation Layers Not Available !");

	vInstance = new VulkanInstance();
	vInstance->createAppAndVkInstance(isValidationLayersEnabled, valLayersAndExt);

	valLayersAndExt->setupDebugCallback(isValidationLayersEnabled, vInstance->vkInstance);

	if (glfwCreateWindowSurface(vInstance->vkInstance, window, nullptr, &surface) != VK_SUCCESS)
		throw std::runtime_error(" failed to create window surface !");

	device = new Device();
	device->pickPhysicalDevice(vInstance, surface);
	device->createLogicalDevice(surface, isValidationLayersEnabled, valLayersAndExt);

	swapChain = new SwapChain();
	swapChain->create(surface);

	renderPass = new Renderpass();
	renderPass->createRenderPass(swapChain->swapChainImageFormat);

	renderTarget = new RenderTarget();
	renderTarget->createViewsAndFramebuffer(swapChain->swapChainImages,
		swapChain->swapChainImageFormat,
		swapChain->swapChainImageExtent,
		renderPass->renderPass);

	drawComBuffer = new DrawCommandBuffer();
	drawComBuffer->createCommandPoolAndBuffer(swapChain->swapChainImages.size());
}

void VulkanContext::drawBegin()
{
	vkAcquireNextImageKHR(device->logicalDevice,
		swapChain->swapChain,
		std::numeric_limits<uint64_t>::max(),
		nullptr,
		VK_NULL_HANDLE,
		&imageIndex);

	curentCommandBuffer = drawComBuffer->commandBuffers[imageIndex];

	drawComBuffer->beginCommandBuffer(curentCommandBuffer);

	VkClearValue clearcolor = { 1.0f, 0.0f, 1.0f, 1.0f };

	std::array<VkClearValue, 1> clearValues = { clearcolor };

	renderPass->beginRenderPass(clearValues,
		curentCommandBuffer,
		renderTarget->swapChainFramebuffers[imageIndex],
		renderTarget->_swapChainImageExtent);
}

void VulkanContext::drawEnd()
{
	renderPass->endRenderPass(curentCommandBuffer);

	drawComBuffer->endCommandBuffer(curentCommandBuffer);

	VkSubmitInfo submitInfo = {};
	submitInfo.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;
	submitInfo.commandBufferCount = 1;
	submitInfo.pCommandBuffers = &curentCommandBuffer;

	vkQueueSubmit(device->graphicsQueue, 1, &submitInfo, NULL);

	VkPresentInfoKHR presentInfo = {};
	presentInfo.sType = VK_STRUCTURE_TYPE_PRESENT_INFO_KHR;
	presentInfo.swapchainCount = 1;
	presentInfo.pSwapchains = &swapChain->swapChain;
	presentInfo.pImageIndices = &imageIndex;

	vkQueuePresentKHR(device->presentQueue, &presentInfo);
	vkQueueWaitIdle(device->presentQueue);
}

void VulkanContext::cleanup()
{
	vkDeviceWaitIdle(device->logicalDevice);

	drawComBuffer->destroy();
	renderTarget->destroy();
	renderPass->destroy();
	swapChain->destroy();
	device->destroy();

	valLayersAndExt->destroy(vInstance->vkInstance, isValidationLayersEnabled);

	vkDestroySurfaceKHR(vInstance->vkInstance, surface, nullptr);
	vkDestroyInstance(vInstance->vkInstance, nullptr);
}

Device* VulkanContext::getDevice()
{
	return device;
}