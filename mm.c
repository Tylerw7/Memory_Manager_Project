#include <stdio.h>
#include <string.h>
#include "mm.h"





void mm_pool_init(struct mm_pool * pool)
{
    memset(pool->memory, 0, MEM_SIZE(pool->block_size, pool->num_blocks));
    pool->first_free = (struct mm_block_header *)pool->memory;

    struct mm_block_header * current_block = pool->first_free;
    int i = 0;
    for (; i < pool->num_blocks - 1; i++) // -1 one because the last block does not have a next
    {
        current_block->next = (char *)(current_block + 1) + pool->block_size;
        current_block = current_block->next;
        pool->num_free_blocks++;
    }

    current_block->next = NULL;
    pool->num_free_blocks++;
}


void * mm_allocate(struct mm_pool * pool)
{

}


void mm_free(void * data, struct mm_pool * pool)
{

}


void mm_show_stats(struct mm_pool * pool)
{

}
