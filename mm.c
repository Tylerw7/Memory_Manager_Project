#include <stdio.h>
#include <string.h>
#include "mm.h"





void mm_pool_init(struct mm_pool * pool)
{
    memset(pool->memory, 0, MEM_SIZE(pool->block_size, pool->num_blocks));

    pool->first_free = (struct mm_block_header *)pool->memory;
    pool->num_free_blocks = 0;

    struct mm_block_header *current_block = pool->first_free;

    for (int i = 0; i < pool->num_blocks - 1; i++)
    {
        current_block->next =
            (struct mm_block_header *)((char *)current_block +
                                      sizeof(struct mm_block_header) +
                                      pool->block_size);

        current_block = current_block->next;
        pool->num_free_blocks++;
    }

    current_block->next = NULL;
    pool->num_free_blocks++;
}


void *mm_allocate(struct mm_pool * pool)
{
    if (pool->first_free == NULL)
    {
        printf("Out of memory: no free blocks left!\n");
        return NULL;
    }

    struct mm_block_header *allocated_block = pool->first_free;

    // Remove block from free list
    pool->first_free = allocated_block->next;

    pool->num_free_blocks--;

    return (void *)((char *)allocated_block + sizeof(struct mm_block_header));
}


void mm_free(void * data, struct mm_pool * pool)
{
    if (data == NULL)
        return;

    struct mm_block_header *block =
        (struct mm_block_header *)((char *)data - sizeof(struct mm_block_header));

    /* Push block back into free list */
    block->next = pool->first_free;
    pool->first_free = block;

    pool->num_free_blocks++;
}


void mm_show_stats(struct mm_pool * pool)
{
    printf("\n===== MEMORY POOL STATS =====\n");
    printf("Total Blocks     : %d\n", pool->num_blocks);
    printf("Free Blocks      : %d\n", pool->num_free_blocks);
    printf("Used Blocks      : %d\n", pool->num_blocks - pool->num_free_blocks);
    printf("Block Size       : %d bytes\n", pool->block_size);

    printf("Pool Total Size  : %lu bytes\n",
           MEM_SIZE(pool->block_size, pool->num_blocks));

    printf("============================\n\n");
}
