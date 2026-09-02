#include "mempool.h"
#include <stdlib.h>

//MemPool type def
  typedef struct MemPool {
    void* pool_start;
    void* pool_freehead;
    size_t pool_block_count;
    size_t pool_block_size;
  } MemPool;

// Mempool func def
  MemPool* MemPool_Create(size_t block_size, size_t block_count)
  {
    //argv check
      if(block_size < sizeof(void*) || block_count == 0)
      {
        return nullptr;
      }

    //alloc Pool struct
      MemPool *Pool = (MemPool*)malloc(sizeof(MemPool));
      //Pool check
        if(Pool == nullptr)
        {
          return nullptr;
        }

    //alloc MemPool
      Pool->pool_start = malloc(block_count * block_size);
      //MemPool check
        if(Pool->pool_start == nullptr)
        {
          free(Pool);
          return nullptr;
        }

    //init Pool struct members
      Pool->pool_block_count = block_count;
      Pool->pool_block_size = block_size;
      Pool->pool_freehead = Pool->pool_start;

    //linking list
      char *base = (char*)Pool->pool_start;
      for(size_t i=0; i<block_count-1; i++)
      {
        void *current = base + (i * block_size);
        void *next = base + ((i+1) * block_size);
        *(void**)current = next;
      }
      void *last = base + (block_count - 1)*block_size;
      *(void**)last = nullptr;

    //return
      return Pool;
  }

  
