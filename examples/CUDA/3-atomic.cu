#include <stdio.h>

#define NUM_THREADS 1000000
#define ARRAY_SIZE  10
#define BLOCK_WIDTH 1000

void print_array(int *arr, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("array[%d] = %d\n", i, arr[i]);
    }
}

__global__ void increment_naive(int* g)
{
    int i = blockIdx.x * blockDim.x + threadIdx.x;
    i = i % ARRAY_SIZE;
    g[i] = g[i] + 1;
}

__global__ void increment_sync(int* g)
{
    int i = blockIdx.x * blockDim.x + threadIdx.x;
    i = i % ARRAY_SIZE;
    int temp = g[i];
    __syncthreads();
    g[i] = temp + 1;
    __syncthreads();
}

__global__ void increment_atomic(int* g)
{
    int i = blockIdx.x * blockDim.x + threadIdx.x;
    i = i % ARRAY_SIZE;
    atomicAdd(&g[i], 1);
}

int main(int argc, char** argv)
{
    printf("%d total threads in %d blocks writing into %d array elements\n", 
            NUM_THREADS, NUM_THREADS / BLOCK_WIDTH, ARRAY_SIZE);
    
    int h_array[ARRAY_SIZE];
    const int ARRAY_BYTES = ARRAY_SIZE * sizeof(int);

    int *d_array;
    cudaMalloc((void**)&d_array, ARRAY_BYTES);
    cudaMemset((void*)d_array, 0, ARRAY_BYTES);

    const int BLOCK_DIM = NUM_THREADS / BLOCK_WIDTH;

    printf("\nwithout __syncthreads or atomic operation\n");
    increment_naive<<<BLOCK_DIM, BLOCK_WIDTH>>>(d_array);
    cudaMemcpy(h_array, d_array, ARRAY_BYTES, cudaMemcpyDeviceToHost);
    print_array(h_array, ARRAY_SIZE);

    printf("\nwith __syncthreads\n");
    increment_sync<<<BLOCK_DIM, BLOCK_WIDTH>>>(d_array);
    cudaMemcpy(h_array, d_array, ARRAY_BYTES, cudaMemcpyDeviceToHost);
    print_array(h_array, ARRAY_SIZE);

    printf("\nwith atomic operations\n");
    increment_atomic<<<BLOCK_DIM, BLOCK_WIDTH>>>(d_array);
    cudaMemcpy(h_array, d_array, ARRAY_BYTES, cudaMemcpyDeviceToHost);
    print_array(h_array, ARRAY_SIZE);

    cudaFree(d_array);
    return 0;
}