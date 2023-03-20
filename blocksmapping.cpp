#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct block_map {
    int block_idx;
    int a;
    int b;
    int c;
};

struct block_map get_map(int i, int j, int k, int A, int B, int C, int D, int E, int F) {
    int num_blocks_x = ceil((double) A / D);
    int num_blocks_y = ceil((double) B / E);
    int num_blocks_z = ceil((double) C / F);
    int num_blocks = num_blocks_x * num_blocks_y * num_blocks_z;

    int block_i = i / D;
    int block_j = j / E;
    int block_k = k / F;
    int a = i % D;
    int b = j % E;
    int c = k % F;
    int block_idx = block_i + block_j * num_blocks_x + block_k * num_blocks_x * num_blocks_y;

    struct block_map map = {block_idx, a, b, c};
    return map;
}

int main() {
    int A = 1024, B = 1024, C = 1024;
    int D = 80, E = 512, F = 325;
    int i = 100, j = 200, k = 300;

    struct block_map map = get_map(i, j, k, A, B, C, D, E, F);

    printf("Block ID: %d\n", map.block_idx);
    printf("Indices within block: %d, %d, %d\n", map.a, map.b, map.c);

    return 0;
}
