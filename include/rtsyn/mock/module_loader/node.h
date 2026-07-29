/**
 * @file rtsyn/mock/module_loader/node.h
 * @author Sergio Hidalgo (sergiohg.dev@gmail.com)
 * @brief Header for the Mock Node.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 * @copyright Copyright (c) Sergio Hidalgo 2026
 */
#ifndef RTSYN_MOCK_MODULE_LOADER_NODE_H
#define RTSYN_MOCK_MODULE_LOADER_NODE_H

#include <rtsyn/abi/node.h>

#ifdef __cplusplus
extern "C" {
#endif

RTSYN_ABI_EXPORT const rtsyn_abi_node_descriptor_t *RTSYN_ABI_CALL
rtsyn_module_get_descriptor(void);

#ifdef __cplusplus
}
#endif

#endif /* RTSYN_MOCK_MODULE_LOADER_NODE_H */
