#include "DVulkan.internal.h"
#include "../../Core/DMemory.h"
#include "../../Core/DLog.h"
#include <string.h>

DArray* get_VkExtensionProperties() {
	uint32_t extensionCount = 0;
	vkEnumerateInstanceExtensionProperties(NULL, &extensionCount, NULL);
	DArray* extensions = DArray_create(sizeof(VkExtensionProperties));
	DArray_allocate(extensions, NULL, extensionCount);
	DArray_set_size(extensions, extensionCount);
	vkEnumerateInstanceExtensionProperties(NULL, &extensionCount, (VkExtensionProperties*)DArray_begin(extensions));
	return extensions;
}
DArray* check_VkExtensionProperties(DArray* in_extensions) {
	uint32_t glfwExtensionCount = 0;
	const char** glfwExtensions;
    glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);
	DArray_append_cstr(in_extensions, (char**)glfwExtensions, glfwExtensionCount);

	if (DArray_size(in_extensions) == 0) { DPrint_dbg("No extensions active!") return in_extensions; }
	DArray* avaliable = get_VkExtensionProperties();
	for (uint32_t i = 0; i < DArray_size(in_extensions); i++) {
		uint32_t j = 0;
		for (; j < DArray_size(avaliable); j++) {
			if (strcmp(*DArray_get_cstr(in_extensions, i), ((VkExtensionProperties*)DArray_get(avaliable, j))->extensionName) == 0) {
				DPrint_dbg(COL_GREEN "%s" COL_RESET, *DArray_get_cstr(in_extensions, i));
				break;
			}
		}
		if (j == DArray_size(avaliable)) {
			DPrint_dbg(COL_RED "%s" COL_RESET, *DArray_get_cstr(in_extensions, i));
			DArray_remove_at(in_extensions, i);
			i--;
		}
	}
	DArray_free(avaliable);
	return in_extensions;
}
void    create_VkExtensionProperties(DVulkan* in_vk) {
	in_vk->_core._extensionLayers = DArray_create(sizeof(char*));
	DArray_pushback_cstr(in_vk->_core._extensionLayers, VK_EXT_DEBUG_UTILS_EXTENSION_NAME);

	DPrint_dbg("==== VULKAN EXTENSIONS ====");
	check_VkExtensionProperties(in_vk->_core._extensionLayers);
	DPrint_nl();
}

DArray* get_VkLayerProperties() {
	uint32_t validationLayerCount = 0;
	vkEnumerateInstanceLayerProperties(&validationLayerCount, NULL);
	DArray* avaliableValidationLayers = DArray_create(sizeof(VkLayerProperties));
	DArray_allocate(avaliableValidationLayers, NULL, validationLayerCount);
	DArray_set_size(avaliableValidationLayers, validationLayerCount);
	vkEnumerateInstanceLayerProperties(&validationLayerCount, (VkLayerProperties*)DArray_begin(avaliableValidationLayers));
	return avaliableValidationLayers;
}
DArray* check_VkLayerProperties(DArray* in_validation) {
	if (DArray_size(in_validation) == 0) { DPrint_dbg("No validation active!") return in_validation; }
	DArray* avaliable = get_VkLayerProperties();
	for (uint32_t i = 0; i < DArray_size(in_validation); i++) {
		uint32_t j = 0;
		for (; j < DArray_size(avaliable); j++) {
			if (strcmp(*DArray_get_cstr(in_validation, i), ((VkLayerProperties*)DArray_get(avaliable, j))->layerName) == 0) {
				DPrint_dbg(COL_GREEN "%s" COL_RESET, *DArray_get_cstr(in_validation, i));
				break;
			}
		}
		if (j == DArray_size(avaliable)) {
			DPrint_dbg(COL_RED "%s" COL_RESET, *DArray_get_cstr(in_validation, i));
			DArray_remove_at(in_validation, i);
		}
	}
	DArray_free(avaliable);
	return in_validation;
}
void    create_VkLayerProperties(DVulkan* in_vk) {
	in_vk->_core._validationLayers = DArray_create(sizeof(char*));
	DArray_pushback_cstr(in_vk->_core._validationLayers, "VK_LAYER_KHRONOS_validation");

	DPrint_dbg("==== VULKAN VALIDATION ====");
	check_VkLayerProperties(in_vk->_core._validationLayers);
	DPrint_nl();
}

DArray* get_VkDeviceExtension(VkPhysicalDevice in_device) {
	uint32_t extensionCount = 0;
	vkEnumerateDeviceExtensionProperties(in_device, NULL, &extensionCount, NULL);
	DArray* extensions = DArray_create(sizeof(VkExtensionProperties));
	DArray_allocate(extensions, NULL, extensionCount);
	DArray_set_size(extensions, extensionCount);
	vkEnumerateDeviceExtensionProperties(in_device, NULL, &extensionCount, (VkExtensionProperties*)DArray_begin(extensions));
	return extensions;
}
DArray* check_VkDeviceExtension(VkPhysicalDevice in_device, DArray* in_extensions) {
	if (DArray_size(in_extensions) == 0) { DPrint_dbg("No extensions active!") return in_extensions; }
	DArray* avaliable = get_VkDeviceExtension(in_device);
	for (uint32_t i = 0; i < DArray_size(in_extensions); i++) {
		uint32_t j = 0;
		for (; j < DArray_size(avaliable); j++) {
			if (strcmp(*DArray_get_cstr(in_extensions, i), ((VkExtensionProperties*)DArray_get(avaliable, j))->extensionName) == 0) {
				DPrint_dbg(COL_GREEN "%s" COL_RESET, *DArray_get_cstr(in_extensions, i));
				break;
			}
		}
		if (j == DArray_size(avaliable)) {
			DPrint_dbg(COL_RED "%s" COL_RESET, *DArray_get_cstr(in_extensions, i));
			DArray_remove_at(in_extensions, i);
			i--;
		}
	}
	DArray_free(avaliable);
	return in_extensions;
}
void    create_VkDeviceExtension(VkPhysicalDevice in_device, DVulkan* in_vk) {
	in_vk->_core._extensions = DArray_create(sizeof(char*));
	DArray_pushback_cstr(in_vk->_core._extensions, VK_KHR_SWAPCHAIN_EXTENSION_NAME);

	DPrint_dbg("==== DEVICE EXTENSIONS ====");
	check_VkDeviceExtension(in_device, in_vk->_core._extensions);
}

DArray* get_VkQueueFamilyProperties(VkPhysicalDevice in_device) {
	uint32_t queueFamilyCount = 0;
	vkGetPhysicalDeviceQueueFamilyProperties(in_device, &queueFamilyCount, NULL);
	DArray* queue = DArray_create(sizeof(VkQueueFamilyProperties));
	DArray_allocate(queue, NULL, queueFamilyCount);
	DArray_set_size(queue, queueFamilyCount);
	vkGetPhysicalDeviceQueueFamilyProperties(in_device, &queueFamilyCount, (VkQueueFamilyProperties*)DArray_begin(queue));
	return queue;
}
void check_VkQueueFamilyProperties(DVulkan* in_vk, DArray* in_queues, VkPhysicalDevice in_device) {
	uint32_t i = 0;
	for (; i < DArray_size(in_queues); i++) {
		if (((VkQueueFamilyProperties*)DArray_get(in_queues, i))->queueFlags & VK_QUEUE_GRAPHICS_BIT) {
			if (in_vk->_core._queues._graphics == NULL) {
				in_vk->_core._queues._graphics = (uint32_t*)DMalloc(sizeof(uint32_t));
			}
			*in_vk->_core._queues._graphics = i;

			VkBool32 presentSupport = false;
			vkGetPhysicalDeviceSurfaceSupportKHR(in_device, i, in_vk->_core._surface, &presentSupport);

			if (presentSupport) {
				if (in_vk->_core._queues._present == NULL) {
					in_vk->_core._queues._present = (uint32_t*)DMalloc(sizeof(uint32_t));
				}
				*in_vk->_core._queues._present = i;
			}
			return;
		}
	}
}

DArray* get_VkPhysicalDevices(DVulkan* in_vk) {
	uint32_t deviceCount = 0;
	vkEnumeratePhysicalDevices(in_vk->_core._instance, &deviceCount, NULL);
	if (deviceCount == 0) { DPrint_err("Failed to find GPUs with Vulkan support!"); return NULL; }
	DArray* devices = DArray_create(sizeof(VkPhysicalDevice));
	DArray_allocate(devices, NULL, deviceCount);
	DArray_set_size(devices, deviceCount);
	vkEnumeratePhysicalDevices(in_vk->_core._instance, &deviceCount, (VkPhysicalDevice*)DArray_begin(devices));
	return devices;
}
bool    check_VkPhysicalDevices(VkPhysicalDevice in_device) {
	VkPhysicalDeviceProperties deviceProperties;
	VkPhysicalDeviceFeatures deviceFeatures;
	vkGetPhysicalDeviceProperties(in_device, &deviceProperties);
	vkGetPhysicalDeviceFeatures(in_device, &deviceFeatures);

	bool suitable = deviceProperties.deviceType == VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU && deviceFeatures.geometryShader;
	if (suitable) { DPrint_dbg(COL_GREEN "%s" COL_RESET, deviceProperties.deviceName); }
	else { DPrint_dbg(COL_RED "%s" COL_RESET, deviceProperties.deviceName); }

	return suitable;
}
bool    create_VkPhysicalDevices(DVulkan* in_vk) {
	DPrint_dbg("==== DEVICES ====");
	DArray* avaliable = get_VkPhysicalDevices(in_vk);
	
	for (uint32_t i = 0; i < DArray_size(avaliable); i++) {
		if (check_VkPhysicalDevices(*(VkPhysicalDevice*)DArray_get(avaliable, i))) {
			
			DArray* avaliable_queues = get_VkQueueFamilyProperties(*(VkPhysicalDevice*)DArray_get(avaliable, i));
			check_VkQueueFamilyProperties(in_vk, avaliable_queues, *(VkPhysicalDevice*)DArray_get(avaliable, i));
			DArray_free(avaliable_queues);
			
			if (in_vk->_core._queues._graphics != NULL && in_vk->_core._queues._present != NULL) {
				DPrint_inf("Graphics Queue: %d", *in_vk->_core._queues._graphics);
				DPrint_inf("Present Queue: %d", *in_vk->_core._queues._present);
				DPrint_nl();

				create_VkDeviceExtension(*(VkPhysicalDevice*)DArray_get(avaliable, i), in_vk);

				if (DArray_size(in_vk->_core._extensions) != 0) {
					in_vk->_core._physical_device = *(VkPhysicalDevice*)DArray_get(avaliable, i);
					break;
				}
			}
		}
	}
	DPrint_nl();
	DArray_free(avaliable);
	if (in_vk->_core._physical_device == VK_NULL_HANDLE) {
		return false;
	}
	return true;
}

bool create_VkInstance(DVulkan* in_vk) {
	VkApplicationInfo appInfo = {
		.sType 				= VK_STRUCTURE_TYPE_APPLICATION_INFO,
		.pApplicationName 	= in_vk->_window._name,
		.applicationVersion = VK_MAKE_VERSION(1, 0, 0),
		.pEngineName        = "DVulkan",
		.engineVersion 		= VK_MAKE_VERSION(1, 0, 0),
		.apiVersion 		= VK_API_VERSION_1_0
	};

	VkInstanceCreateInfo createInfo = {
		.sType 					 = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
		.pApplicationInfo 		 = &appInfo,
		.enabledExtensionCount   = DArray_size(in_vk->_core._extensionLayers),
		.ppEnabledExtensionNames = (const char* const*)DArray_begin(in_vk->_core._extensionLayers),
		.enabledLayerCount  	 = 0
	};

	if (DArray_size(in_vk->_core._validationLayers) > 0) {
		createInfo.enabledLayerCount   = DArray_size(in_vk->_core._validationLayers);
		createInfo.ppEnabledLayerNames = (const char* const*)DArray_begin(in_vk->_core._validationLayers);
	}

	if (vkCreateInstance(&createInfo, NULL, &in_vk->_core._instance) != VK_SUCCESS) {
		return false;
	}

	return true;
}
bool create_VkDevice(DVulkan* in_vk) {
	in_vk->_core._queueInfos = DArray_create(sizeof(VkDeviceQueueCreateInfo));
	DArray* uniqueQueueFamilies = DArray_create(sizeof(uint32_t));
	DArray_pushback_u32(uniqueQueueFamilies, *in_vk->_core._queues._graphics);
	if (!DArray_contains_u32(uniqueQueueFamilies, *in_vk->_core._queues._present)) {
		DArray_pushback_u32(uniqueQueueFamilies, *in_vk->_core._queues._present);
	}

	float queuePriority = 1.0f;
	for (uint32_t i = 0; i < DArray_size(uniqueQueueFamilies); i++) {
		VkDeviceQueueCreateInfo queueCreateInfo = {
			.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO,
			.queueFamilyIndex = *DArray_get_u32(uniqueQueueFamilies, i),
			.queueCount = 1,
			.pQueuePriorities = &queuePriority,
		};
		DArray_pushback(in_vk->_core._queueInfos, &queueCreateInfo);
	}

	DArray_free(uniqueQueueFamilies);

	VkPhysicalDeviceFeatures deviceFeatures = {};

	VkDeviceCreateInfo createInfo = {
		.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO,
		.pQueueCreateInfos = (VkDeviceQueueCreateInfo*)DArray_begin(in_vk->_core._queueInfos),
		.queueCreateInfoCount = DArray_size(in_vk->_core._queueInfos),
		.pEnabledFeatures = &deviceFeatures,
		.enabledLayerCount = 0,
		.enabledExtensionCount = DArray_size(in_vk->_core._extensions),
		.ppEnabledExtensionNames = (const char* const*)DArray_begin(in_vk->_core._extensions)
	};

	if (DArray_size(in_vk->_core._validationLayers) > 0) {
		createInfo.enabledLayerCount   = DArray_size(in_vk->_core._validationLayers);
		createInfo.ppEnabledLayerNames = (const char* const*)DArray_begin(in_vk->_core._validationLayers);
	}

	if (vkCreateDevice(in_vk->_core._physical_device, &createInfo, NULL, &in_vk->_core._logical_device) != VK_SUCCESS) {
		return false;
	}

	vkGetDeviceQueue(in_vk->_core._logical_device, *in_vk->_core._queues._graphics, 0, &in_vk->_core._graphicsQueue);

	return true;
}
bool create_VkSurface(DVulkan* in_vk) {
	if (glfwCreateWindowSurface(in_vk->_core._instance, in_vk->_window._window, NULL, &in_vk->_core._surface) != VK_SUCCESS) {
        return false;
    }
	return true;
}

DVulkan* DVulkan_create(const char* in_name, const uint32_t in_width, const uint32_t in_height) {
	DVulkan* vk = DMalloc(sizeof(DVulkan));

	// -- Init GLFW -- //
	glfwInit();
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

	// -- Version Check -- //
	DPrint_nl();
	DPrint_dbg("==== VERSION ====");
	DPrint_dbg("%s\n", glfwGetVersionString());

	// -- Create DVulken instance -- //
	vk->_update = NULL;
	vk->_draw   = NULL;
	vk->_create = NULL;
	vk->_free   = NULL;
	vk->_core   = (struct DVulkanCore){
		._physical_device  = VK_NULL_HANDLE,
		._logical_device   = VK_NULL_HANDLE,
		._instance 		   = VK_NULL_HANDLE,
		._graphicsQueue    = VK_NULL_HANDLE,
		._presentQueue     = VK_NULL_HANDLE,
		._surface 		   = VK_NULL_HANDLE,
		._queueInfos	   = NULL,
		._extensionLayers  = NULL,
		._validationLayers = NULL,
		._extensions 	   = NULL
	};
	vk->_core._queues = (struct DVulkanQueueFamilies) {
		._graphics = NULL,
		._present  = NULL
	};
	vk->_window = (struct DVulkanWindow){
		._name   = in_name,
		._width  = in_width,
		._height = in_height,
		._window = NULL
	};
	vk->_window._window =
		glfwCreateWindow(vk->_window._width, vk->_window._height, vk->_window._name, NULL, NULL);

	create_VkExtensionProperties(vk);
	create_VkLayerProperties(vk);

	if (!create_VkInstance(vk)) { DPrint_err("Failed to create instance!"); return NULL; }
	if (!create_VkSurface(vk)) { DPrint_err("failed to create window surface!"); return NULL; }
	if (!create_VkPhysicalDevices(vk)) { DPrint_err("Failed to find a suitable GPU!") return NULL; }
	if (!create_VkDevice(vk)) { DPrint_err("Failed to create logical device!"); return NULL; }
	

	return vk;
}
void DVulkan_free(DVulkan* in_vk) {
	if (in_vk == NULL) return;
	vkDestroyDevice(in_vk->_core._logical_device, NULL);
	vkDestroySurfaceKHR(in_vk->_core._instance, in_vk->_core._surface, NULL);
	vkDestroyInstance(in_vk->_core._instance, NULL);
	glfwDestroyWindow(in_vk->_window._window);
	glfwTerminate();
	DArray_free(in_vk->_core._queueInfos);
	DArray_free(in_vk->_core._validationLayers);
	DArray_free(in_vk->_core._extensionLayers);
	DArray_free(in_vk->_core._extensions);
	DFree(in_vk->_core._queues._graphics);
	DFree(in_vk->_core._queues._present);
	DFree(in_vk);
}

void DVulkan_update(DVulkan* in_vk) {
	while (!glfwWindowShouldClose(in_vk->_window._window)) {
		glfwPollEvents();
		if (in_vk->_update != NULL) in_vk->_update(NULL);
	}
}

void DVulkan_hook_update(DVulkan* in_vk, void(*in_f)(void*)) {
	in_vk->_update = in_f;
}
void DVulkan_hook_draw(DVulkan* in_vk, void(*in_f)(void*)) {
	in_vk->_draw = in_f;
}
