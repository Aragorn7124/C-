#include "mempool.h"
#include <iostream>

//MemPool type def
  typedef struct MemPool {
    void* Pool_Start;
    void* Pool_Next;
    size_t Pool_Size;
    size_t Pool_UsedSize;
  } MemPool;

//Mempool func def
  MemPool* MemPool_Create(size_t block_size, size_t block_count)
  {
    if(block_size >= sizeof(void*) && block_count > 0)
    {
      return nullptr;
    }

    MemPool MemPool;
    MemPool.Pool_Size = block_count;
    MemPool.Pool_UsedSize = 0;
    MemPool.Pool_Start = malloc(block_count * block_size);
    if(MemPool.Pool_Start == nullptr)
    {
      return nullptr;
    }

  }
