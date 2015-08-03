/*
 * demo1.c
 *
 *  Created on: 2015年8月3日
 *      Author: hexin
 */
#include <stdlib.h>
#include <stdio.h>
#include <omp.h>
#define LEN 5
__attribute__((target(mic))) void funcheck(int i)
{
#ifdef __MIC__
	printf("Index on MIC:%d\n",i);
#else
	printf("Index on CPU:%d\n",i);
#endif
}
int main(int argc, char **argv) {
	int i;
	float x=2;
	float *arr=(float *)malloc(LEN*sizeof(float));
//	float arr[LEN];
#pragma offload target(mic) out(arr:length(LEN))
#pragma omp parallel for
	for(i=0;i<LEN;++i)
	{
		arr[i]=i*3.0f/x;
//		printf("Index:%d\n",i);
	}
	if(fabsf(arr[2]-2*3.0f/x)<1e-6)
		printf("Demo is right\n");
	else
		printf("Demo is wrong,arr[2] is %f\n",arr[2]);
	return 0;
}
