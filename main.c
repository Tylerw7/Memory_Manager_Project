#include <stdio.h>
#include <stdlib.h>
#include "mm.c"


int main()
{
    struct mm_pool pool;

    pool.block_size = 32;
    pool.num_blocks = 5;

    pool.memory = malloc(MEM_SIZE(pool.block_size, pool.num_blocks));

    mm_pool_init(&pool);
    mm_show_stats(&pool);

    void *a = mm_allocate(&pool);
    void *b = mm_allocate(&pool);

    mm_show_stats(&pool);

    mm_free(a, &pool);
    mm_show_stats(&pool);

    free(pool.memory);



    return 0;
}