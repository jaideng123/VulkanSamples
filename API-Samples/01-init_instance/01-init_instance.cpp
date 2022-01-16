/*
 * Vulkan Samples
 *
 * Copyright (C) 2015-2016 Valve Corporation
 * Copyright (C) 2015-2016 LunarG, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
VULKAN_SAMPLE_SHORT_DESCRIPTION
create and destroy Vulkan instance
*/

/* This is part of the draw cube progression */

#include <iostream>
#include <cstdlib>
#include <util_init.hpp>

#define APP_SHORT_NAME "vulkansamples_instance"

int sample_main(int argc, char *argv[]) {
    struct sample_info info = {};
    init_global_layer_properties(info);

    /* VULKAN_KEY_START */

    // initialize the VkApplicationInfo structure
    VkApplicationInfo app_info = {};
    // The type of structure
    app_info.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    // Allows extenstions to analyze/lookup structure (not often used)
    app_info.pNext = NULL;
    // Used mainly for debug and self-identifying to driver
    app_info.pApplicationName = APP_SHORT_NAME;
    app_info.applicationVersion = 1;
    app_info.pEngineName = APP_SHORT_NAME;
    app_info.engineVersion = 1;
    // Major, minor, and patch levels of the Vulkan API header used
    app_info.apiVersion = VK_API_VERSION_1_0;

    // initialize the VkInstanceCreateInfo structure
    VkInstanceCreateInfo inst_info = {};
    // The type of structure
    inst_info.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    // Allows extenstions to analyze/lookup structure (not often used)
    inst_info.pNext = NULL;
    // Bit flags
    inst_info.flags = 0;
    // Pointer to app info
    inst_info.pApplicationInfo = &app_info;
    // Number of extensions
    inst_info.enabledExtensionCount = 0;
    // Names of extensions
    inst_info.ppEnabledExtensionNames = NULL;
    // Number of layers
    inst_info.enabledLayerCount = 0;
    // Layer Pointers
    inst_info.ppEnabledLayerNames = NULL;

    // Vulkan Instance stores all per-app state
    VkInstance inst;
    // Enum result of createInstance
    VkResult res;

    // pCreateInfo = Instance
    // pAllocator = Optional callback for custom memory allocator
    // VkInstance = Out param, returns handle for the instance (DO NOT DEREF)
    res = vkCreateInstance(&inst_info, NULL, &inst);
    if (res == VK_ERROR_INCOMPATIBLE_DRIVER) {
        std::cout << "cannot find a compatible Vulkan ICD\n";
        exit(-1);
    } else if (res) {  // Anything but 0 is an error
        std::cout << "unknown error\n";
        exit(-1);
    }

    vkDestroyInstance(inst, NULL);

    /* VULKAN_KEY_END */

    return 0;
}
