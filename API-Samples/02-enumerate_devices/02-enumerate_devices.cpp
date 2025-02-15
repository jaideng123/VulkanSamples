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
enumerate physical devices
*/

#include <cassert>
#include <cstdlib>
#include <util_init.hpp>

int sample_main(int argc, char *argv[]) {
    // Stores all our state
    struct sample_info info = {};
    init_global_layer_properties(info);
    // Everything from 01, stored in info
    init_instance(info, "vulkansamples_enumerate");

    /* VULKAN_KEY_START */

    uint32_t gpu_count = 1;
    // Returns the number of physical devices available via gpu_count
    VkResult U_ASSERT_ONLY res = vkEnumeratePhysicalDevices(info.inst, &gpu_count, NULL);
    // We should have at least 1 GPU available
    assert(gpu_count);
    // Allocate space for the number of devices we have
    info.gpus.resize(gpu_count);
    // Now pull info about the devices into our info object
    res = vkEnumeratePhysicalDevices(info.inst, &gpu_count, info.gpus.data());
    // We should be good
    assert(!res && gpu_count >= 1);

    /* VULKAN_KEY_END */

    vkDestroyInstance(info.inst, NULL);

    return 0;
}
