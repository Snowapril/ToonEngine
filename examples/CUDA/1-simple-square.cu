#include <stdio.h>

__global__
void square(float *d_in, float *d_out)
{
    int idx = threadIdx.x;
    float v = d_in[idx];
    d_out[idx] = v * v;
}

int main(int argc, char **argv)
{
    const int ARRAY_SIZE  = 64;
    const int ARRAY_BYTES = ARRAY_SIZE * sizeof(float);

    // generate the input array on the host
    float h_in[ARRAY_SIZE], h_out[ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; i++)
        h_in[i] = i + 1;
    
    // declare GPU memory pointers.
    float *d_in, *d_out;
    // allocate GPU memory
    cudaMalloc((void**)&d_in, ARRAY_BYTES);
    cudaMalloc((void**)&d_out, ARRAY_BYTES);

    cudaMemcpy(d_in, h_in, ARRAY_BYTES, cudaMemcpyHostToDevice);
    square<<< 1, ARRAY_SIZE >>>(d_in, d_out);
    cudaMemcpy(h_out, d_out, ARRAY_BYTES, cudaMemcpyDeviceToHost);

    for (int i = 0; i < ARRAY_SIZE; i++)
        printf("%d th array element : %f\n", i, h_out[i]);

    cudaDeviceSynchronize();

    return 0;
}