#pragma once

#include <vector>
#include <array>
#include <vulkan/vulkan.h>

class RenderTarget
{
public:
	std::vector<VkImage> _swapChainImages;
	VkExtent2D _swapChainImageExtent;
	std::vector<VkImageView> swapChainImageViews;
	std::vector<VkFramebuffer> swapChainFramebuffers;
	VkImage depthImage;
	VkDeviceMemory depthImageMemory;
	VkImageView depthImageView;
	VkFormat depthFormat;

	RenderTarget();
	~RenderTarget();

	void createViewsAndFramebuffer(std::vector<VkImage> swapChainImages, VkFormat swapChainImageFormat, VkExtent2D swapChainImageExtent, VkRenderPass renderPass);
	void createImageViews(VkFormat swapChainImageFormat);
	void createFrameBuffer(VkExtent2D swapChainImageExtent, VkRenderPass renderPass);
	void destroy();
};