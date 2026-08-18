/**
 * @file mock/node/plugin.c
 * @author Sergio Hidalgo (sergiohg.dev@gmail.com)
 * @brief Mock plugin node implementation for testing.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 * @copyright Copyright (c) Sergio Hidalgo 2026
 */
#include "rtsyn/mock/node/plugin.h"

#include <rtsyn/abi/port/direction.h>
#include <rtsyn/abi/status.h>
#include <rtsyn/abi/value.h>

static rtsyn_abi_status_t RTSYN_ABI_CALL
mock_plugin_create(void **out_instance)
{
    if (!out_instance)
    {
        return RTSYN_ABI_STATUS_INVALID_ARGUMENT;
    }
    *out_instance = nullptr;
    return RTSYN_ABI_STATUS_OK;
}

static rtsyn_abi_status_t RTSYN_ABI_CALL
mock_plugin_set_param(void *instance, uint32_t param_index, const void *value)
{
    (void)instance;
    (void)param_index;
    (void)value;
    return RTSYN_ABI_STATUS_OK;
}

static rtsyn_abi_status_t RTSYN_ABI_CALL
mock_plugin_read_state(const void *instance, uint32_t state_index, void *out_value)
{
    (void)instance;
    (void)state_index;
    (void)out_value;
    return RTSYN_ABI_STATUS_OK;
}

static rtsyn_abi_status_t RTSYN_ABI_CALL
mock_plugin_start(void *instance)
{
    (void)instance;
    return RTSYN_ABI_STATUS_OK;
}

static rtsyn_abi_status_t RTSYN_ABI_CALL
mock_plugin_process(void *instance, const rtsyn_abi_runtime_context_t *context)
{
    (void)instance;
    (void)context;
    return RTSYN_ABI_STATUS_OK;
}

static rtsyn_abi_status_t RTSYN_ABI_CALL
mock_plugin_stop(void *instance)
{
    (void)instance;
    return RTSYN_ABI_STATUS_OK;
}

static void RTSYN_ABI_CALL
mock_plugin_destroy(void *instance)
{
    (void)instance;
}

static const rtsyn_abi_port_descriptor_t mock_plugin_ports[] = {
    {"input", RTSYN_ABI_VALUE_F64, RTSYN_ABI_PORT_DIRECTION_IN},
    {"output", RTSYN_ABI_VALUE_F64, RTSYN_ABI_PORT_DIRECTION_OUT},
};

static const rtsyn_abi_node_descriptor_t mock_plugin_descriptor = {
    .name = "mock-plugin",
    .node_type = RTSYN_ABI_NODE_PLUGIN,
    .port_count = 2,
    .ports = mock_plugin_ports,
    .param_count = 0,
    .params = nullptr,
    .state_count = 0,
    .states = nullptr,
    .callbacks =
        {
            .create = mock_plugin_create,
            .set_param = mock_plugin_set_param,
            .read_state = mock_plugin_read_state,
            .start = mock_plugin_start,
            .process = mock_plugin_process,
            .stop = mock_plugin_stop,
            .destroy = mock_plugin_destroy,
        },
};

const rtsyn_abi_node_descriptor_t *
rtsyn_mock_node_plugin_get_descriptor(void)
{
    return &mock_plugin_descriptor;
}
