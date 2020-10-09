#include <cuda_runtime.h>
#include <device_launch_parameters.h>
#include <cuda.h>
#include <device_functions.h>
#include <cuda_runtime_api.h>

#include <stdio.h>
#include <device_functions.h>
#include <stdlib.h>

__device__ void printarr(int a[1000]) {
    int row = 0;
    for (int i = 0; i < 1000; i++) 
    {
        if (row == 20)
        {
            row = 0;
            printf("\n");
        }
        printf(" %d ", a[i]);
        row++;
    }
}

__device__ bool fill = false;

__global__ void cuda_test()
{
  
    int a[1000];
    if (blockIdx.x == 0)
    {
        for (int i = 0; i < 1000; i++)
        {
            a[i] = 0;
        }
        printarr(a);
        printf("\n\n\n\n");
        fill = true;
    }
    while (!fill) {}
    for (int i = int(256 * blockIdx.x); i < (256 * (int)(blockIdx.x+1));i++)
    {
        a[i] = 5;
    }

    if (blockIdx.x == 0)
    {
        printarr(a);
        printf("\n\n\n\n");
    }

    printf("\nI am cuda number %d:%d", threadIdx.x,blockIdx.x);
}

int main()
{
    cuda_test << <4, 1>> > ();
    cudaDeviceSynchronize();
    printf("\nI am the CPU!");
    return 0;

}
