#ifndef LL_DEFS_H
#define LL_DEFS_H

// Base
#define LL_OK               0x0000   // Action successful

// Errors / warnings
#define LL_BAD_STRUCT       0x0001    // The provided headref is invalid
#define LL_NEN_NODES        0x0002    // Not enough nodes
#define LL_BAD_INDEX        0x0003    // Index is out of bounds
#define LL_BAD_NODE         0x0004    // The provided node is NULL
#define LL_FAIL_ALLOC       0x0005    // Failed to allocate memory for the object

#endif // LL_DEFS_H