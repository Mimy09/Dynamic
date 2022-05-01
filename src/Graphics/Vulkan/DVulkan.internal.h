#pragma once
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

struct DVulkan {
	struct DVulkanWindow _window;
	VkInstance _instance;
	VkPhysicalDevice _device;
	void(*_update)(void*);
	void(*_draw)(void*);
	void(*_create)(void*);
	void(*_free)(void*);
	DArray* _validationLayers;
	DArray* _extensionLayers;
};
