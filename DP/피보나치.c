#include <stdio.h>
#include <stdlib.h>

/* 피보나치 수열 
	1 1 2 3 5 8 13 21 ... */
int main()
{
	int N;
	scanf("%d",&N);
	int *arr = (int *)malloc(sizeof(int)*(N+1));
	arr[1] = 1;
	arr[2] = 1;
	int idx;
	idx = 3;
	while (idx <= N)
	{
		arr[idx] = arr[idx-1] + arr[idx-2];
		idx++;
	}
	printf("%d", arr[N]);
}
