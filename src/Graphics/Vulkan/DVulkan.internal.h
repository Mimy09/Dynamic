#pragma once
#if defined(DYNAMIC_GRAPHICS)
#include "DVulkan.h"
#include <vulkan/vulkan.h>
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include "../../Container/DArray.h"
#include "../../Container/DStr.h"

struct DVulkanWindow {
	GLFWwindow* _window;
	uint32_t    _width;
	uint32_t    _height;
	const char* _name;
};

struct DVulkanQueueFamilies {
	uint32_t* _graphics;
	uint32_t* _present;
};

struct DVulkanCore {
	struct DVulkanQueueFamilies _queues;
	VkInstance _instance;
	VkPhysicalDevice _physical_device;
	VkDevice _logical_device;
	VkQueue _graphicsQueue;
	VkQueue _presentQueue;
	VkSurfaceKHR _surface;
	DArray* _queueInfos;
	DArray* _validationLayers;
	DArray* _extensionLayers;
	DArray* _extensions;
};

struct DVulkan {
	struct DVulkanWindow _window;
	struct DVulkanCore   _core;
	void(*_update)(void*);
	void(*_draw)(void*);
	void(*_create)(void*);
	void(*_free)(void*);
};
#endif