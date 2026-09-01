#ifndef MEMPOOL_H
#define MEMPOOL_H

#include <stddef.h> //for size_t

//MemPool Type decl
  typedef struct MemPool MemPool;

//MemPool func decl
  MemPool* MemPool_Create(size_t block_size, size_t block_count);

  void* MemPool_Alloc(MemPool* pool);

  void MemPool_Free(MemPool* pool, void* ptr);

  void MemPool_Destroy(MemPool* pool);

#endif
