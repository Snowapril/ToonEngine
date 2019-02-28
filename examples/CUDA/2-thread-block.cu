#include <stdio.h>

#define NUM_BLOCKS 16
#define BLOCK_WIDTH 1

__global__
void hello() 
{
    printf("Hello, i am a thread in a block %d\n", blockIdx.x);
}

int main(int argc, char** argv)
{
    hello<<< NUM_BLOCKS, BLOCK_WIDTH >>>();
    cudaDeviceSynchronize();
    printf("That's all!");
    return 0;
}