#pragma once

#include "toy_common.h"

#define ALLOCATE(type, count) ((type*)reallocate(NULL, 0, sizeof(type) * (count)))
#define FREE(type, pointer) reallocate(pointer, sizeof(type), 0)
#define GROW_CAPACITY(capacity) ((capacity) < 8 ? 8 : (capacity) * 2)
#define GROW_CAPACITY_FAST(capacity) ((capacity) < 32 ? 32 : (capacity) * 2)
#define GROW_ARRAY(type, pointer, oldCount, count) (type*)reallocate((type*)pointer, sizeof(type) * (oldCount), sizeof(type) * (count))
#define SHRINK_ARRAY(type, pointer, oldCount, count) (type*)reallocate((type*)pointer, sizeof(type) * (oldCount), sizeof(type) * (count))
#define FREE_ARRAY(type, pointer, oldCount) reallocate((type*)pointer, sizeof(type) * (oldCount), 0)

//implementation details
void* reallocate(void* pointer, size_t oldSize, size_t newSize);

//assign the memory allocator
typedef void* (*MemoryAllocatorFn)(void* pointer, size_t oldSize, size_t newSize);
TOY_API void setMemoryAllocator(MemoryAllocatorFn);
