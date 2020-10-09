#include <cuda_runtime.h>
#include <cuda.h>
#include <device_launch_parameters.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h> 

__device__ int* ptrarr = 0;
__device__ bool fill=false;
__device__ bool printed = false;
__device__ unsigned int i = 0;
__device__ unsigned int j = 0;
__device__ unsigned int row=0;

__device__ int* generate_arr(const unsigned int x, const unsigned int y)
	{
		int* a = (int*)malloc(x * y * sizeof(int));
		for (i = 0; i < x; i++)
			for (j = 0; j < y; j++)
				*(a + i * y + j) = 0;
		return a;
	}

__device__ void printarr(int* arr, const unsigned int x, const unsigned int y) {
	for (i = 0; i < x; i++) 
	{
		for (j = 0; j < y; j++) 
		{
			if (row == x)
			{
				row = 0;
				printf("\n");
			}
			printf("%d ", *(arr + i * y + j));
			row++;
		}
	}
}


__global__ void array_increment(const unsigned int x,const unsigned int y)
{
	
	if (threadIdx.x == 0)
	{
		ptrarr = generate_arr(x, y);
		printf("\n\nFilling array... \n\n");
		printarr(ptrarr,x,y);
		fill = true;
		printed = true;
	}
	while (!fill) {}
	if (fill && printed)
	{
		for (i = 0; i < x; i++) 
		{
			*(ptrarr + threadIdx.x * x + i) = threadIdx.x;
		}
	}
	if (threadIdx.x == 0)
	{
		printf("\n\narr after increment... \n\n");
		printarr(ptrarr, x, y);
		printf("\n");
	}
}

int main()
{
	int a = 10;
	int b = 20;
	clock_t start, end;
	double t;
	start = clock();
	array_increment << <1, b >> > (a, b);
	//fill_gb<< <1, 1 >> >(1);
	cudaDeviceSynchronize();
	end = clock();
	t = ((double)((double)end - (double)start)) / CLOCKS_PER_SEC;
	printf("t = %lf", t);

	printf("\nI am a CPU\n\n\n\n!");

	return 0;
}
