#include <stdio.h>
#include <stdlib.h>
int main()
{
	int N;
	int T;
	scanf("%d",&T);
	long long arr[101] = {0, };
	while (T--)
	{
		scanf("%d", &N);
		//long long * arr = (long long *)malloc(sizeof(long long)*(N+1));
		arr[1] = 1;
		arr[2] = 1;
		arr[3] = 1;
		int idx;
		idx = 4;
		while (idx <= N)
		{
			arr[idx] = arr[idx-2] + arr[idx-3];
			idx++;
		}
		printf("%lld\n", arr[N]);

		//free(arr);
	}
	
}