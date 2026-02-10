#include <stdio.h>
#include <stdlib.h>
#include "mm.c"


int main()
{
    struct mm_pool pool;

    pool.block_size = 32;
    pool.num_blocks = 5;

    pool.memory = malloc(MEM_SIZE(pool.block_size, pool.num_blocks));

    return 0;
}