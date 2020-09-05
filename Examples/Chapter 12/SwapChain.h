#pragma once

#include <vector>
#include <set>
#include <algorithm>
#include <vulkan\vulkan.h>

class SwapChain
{
public:
	VkSwapchainKHR swapChain;
	VkFormat swapChainImageFormat;
	VkExtent2D swapChainImageExtent;
	std::vector<VkImage> swapChainImages;

	SwapChain();
	~SwapChain();

	VkSurfaceFormatKHR chooseSwapChainSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats);
	VkPresentModeKHR chooseSwapPresentMode(const std::vector<VkPresentModeKHR> availablePresentModes);
	VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities);
	void create(VkSurfaceKHR surface);
	void destroy();
};