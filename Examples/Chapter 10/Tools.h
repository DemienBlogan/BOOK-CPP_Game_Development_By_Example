#pragma once

#include <stdexcept>
#include <vector>
#include <vulkan\vulkan.h>

namespace vkTools
{
	VkImageView createImageView(VkImage image, VkFormat format, VkImageAspectFlags aspectFlags);
}