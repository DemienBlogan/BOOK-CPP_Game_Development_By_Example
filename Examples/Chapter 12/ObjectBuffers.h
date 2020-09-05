#pragma once

#include <vector>
#include <vulkan\vulkan.h>

#include "Mesh.h"

class ObjectBuffers
{
private:
	void createVertexBuffer();
	void createIndexBuffer();
	void createUniformBuffers();

public:
	std::vector<Vertex> vertices;
	VkBuffer vertexBuffer;
	VkDeviceMemory vertexBufferMemory;
	std::vector<uint32_t> indices;
	VkBuffer indexBuffer;
	VkDeviceMemory indexBufferMemory;
	VkBuffer uniformBuffers;
	VkDeviceMemory uniformBuffersMemory;

	ObjectBuffers();
	~ObjectBuffers();

	void createVertexIndexUniformsBuffers(MeshType modelType);
	void destroy();
};