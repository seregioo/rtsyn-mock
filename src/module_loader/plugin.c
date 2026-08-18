#include "rtsyn/mock/module_loader/node.h"

static rtsyn_abi_status_t RTSYN_ABI_CALL
create(void **instance)
{
    *instance = nullptr;
    return RTSYN_ABI_STATUS_OK;
}

static rtsyn_abi_status_t RTSYN_ABI_CALL
start(void *instance)
{
    (void)instance;
    return RTSYN_ABI_STATUS_OK;
}

static rtsyn_abi_status_t RTSYN_ABI_CALL
process(void *instance, const rtsyn_abi_runtime_context_t *context)
{
    (void)instance;
    (void)context;
    return RTSYN_ABI_STATUS_OK;
}

static rtsyn_abi_status_t RTSYN_ABI_CALL
stop(void *instance)
{
    (void)instance;
    return RTSYN_ABI_STATUS_OK;
}

static void RTSYN_ABI_CALL
destroy(void *instance)
{
    (void)instance;
}

static const rtsyn_abi_node_descriptor_t descriptor = {
    .name = "test-plugin",
    .node_type = RTSYN_ABI_NODE_PLUGIN,
    .port_count = 0,
    .ports = nullptr,
    .callbacks =
        {
            .create = create,
            .start = start,
            .process = process,
            .stop = stop,
            .destroy = destroy,
        },
};

RTSYN_ABI_EXPORT const rtsyn_abi_node_descriptor_t *RTSYN_ABI_CALL
rtsyn_module_get_descriptor(void)
{
    return &descriptor;
}
