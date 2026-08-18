/**
 * @file rtsyn/mock/node/plugin.h
 * @author Sergio Hidalgo (sergiohg.dev@gmail.com)
 * @brief Mock plugin node descriptor for testing.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 * @copyright Copyright (c) Sergio Hidalgo 2026
 */
#ifndef RTSYN_MOCK_NODE_PLUGIN_H
#define RTSYN_MOCK_NODE_PLUGIN_H

#include <rtsyn/abi/node.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Gets a mock ABI node descriptor for a plugin node.
 *
 * @return Pointer to a static, fully initialized plugin node descriptor.
 */
const rtsyn_abi_node_descriptor_t *
rtsyn_mock_node_plugin_get_descriptor(void);

#ifdef __cplusplus
}
#endif

#endif /* RTSYN_MOCK_NODE_PLUGIN_H */
