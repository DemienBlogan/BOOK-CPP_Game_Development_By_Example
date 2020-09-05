#pragma once

#define GLFW_INCLUDE_VULKAN

#include <GLFW\glfw3.h>
#include <vulkan\vulkan.h>

#include "AppValidationLayersAndExtensions.h"
#include "VulkanInstance.h"
#include "Device.h"
#include "SwapChain.h"
#include "Renderpass.h"
#include "RenderTarget.h"
#include "DrawCommandBuffer.h"

#ifdef _DEBUG
const bool isValidationLayersEnabled = true;
#else
const bool isValidationLayersEnabled = false;
#endif

class VulkanContext
{
private:
	uint32_t imageIndex = 0;
	VkCommandBuffer currentCommandBuffer;
	VkSurfaceKHR surface;
	AppValidationLayersAndExtensions* valLayersAndExt;
	VulkanInstance* vInstance;
	SwapChain* swapChain;
	Renderpass* renderPass;
	RenderTarget* renderTarget;
	DrawCommandBuffer* drawComBuffer;
	const int MAX_FRAMES_IN_FLIGHT = 2;
	VkSemaphore imageAvailableSemaphore;
	VkSemaphore renderFinishedSemaphore;
	std::vector<VkFence> inFlightFences;

public:
	static VulkanContext* instance;
	Device* device;

	~VulkanContext();

	static VulkanContext* getInstance();
	void initVulkan(GLFWwindow* window);
	void drawBegin();
	void drawEnd();
	void cleanup();
	Device* getDevice();
	SwapChain* getSwapChain();
	Renderpass* getRenderpass();
	VkCommandBuffer getCurrentCommandBuffer();
};