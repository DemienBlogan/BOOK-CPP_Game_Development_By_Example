#pragma once

#include <vector>
#include <fstream>
#include <vulkan\vulkan.h>

class GraphicsPipeline
{
private:
	std::vector<char> readfile(const std::string& filename);
	VkShaderModule createShaderModule(const std::vector<char>& code);
	void createGraphicsPipelineLayout(VkDescriptorSetLayout descriptorSetLayout);
	void createGraphicsPipeline(VkExtent2D swapChainImageExtent, VkRenderPass renderPass);

public:
	VkPipelineLayout pipelineLayout;
	VkPipeline graphicsPipeline;

	GraphicsPipeline();
	~GraphicsPipeline();

	void createGraphicsPipelineLayoutAndPipeline(VkExtent2D swapChainImageExtent,
		VkDescriptorSetLayout descriptorSetLayout, VkRenderPass renderPass);
	void destroy();
};