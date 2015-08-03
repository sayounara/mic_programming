/*
 * foo.c
 *
 *  Created on: 2015年8月3日
 *      Author: hexin
 */
#include <stdio.h>

__attribute__((target(mic))) int mic_add(int a, int b);
__attribute__((target(mic))) int a, b;

int mic_add(int a, int b)
{
 return a + b;
}

int main(void)
{

 int c;

 a = 10;
 b = 20;

#pragma offload target(mic)
{
 c = mic_add(a,b);
}

 printf("a + b = %d\n",c);
 return 0;
}

