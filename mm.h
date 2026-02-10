

#define MEM_SIZE(bsize, nblocks) \
    ((sizeof(struct mm_block_header) + (bsize)) * (nblocks))

struct mm_block_header {
    struct mm_block_header * next;
};

struct mm_pool {
    char *memory;
    struct mm_block_header *first_free;
    int num_blocks;
    int num_free_blocks;
    int block_size;
};

void mm_pool_init(struct mm_pool * pool);
void * mm_allocate(struct mm_pool * pool);
void mm_free(void * data, struct mm_pool * pool);
void mm_show_stats(struct mm_pool * pool);