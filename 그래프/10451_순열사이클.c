#include <stdio.h>
#include <stdlib.h>

int N; /* 순열의 크기 */

void DFS(int start, int *arr, int *visited);

int main()
{
	int K;
	int idx;
	int cnt;
	scanf("%d", &K);
	while (K--)
	{
		/* 순열 크기 입력 */
		scanf("%d", &N);

		/* 순열 생성 */
		int *arr = (int *)malloc(sizeof(int) * (N + 1));
		/* 방문기록 생성 */
		int *visited = (int *)malloc(sizeof(int) * (N + 1));

		/* 순열에 값 넣어주기 */
		idx = 1;
		while (idx <= N)
		{
			scanf("%d", &arr[idx]);
			idx++;
		}

		/* 사이클 개수 찾으러 가자 */
		cnt = 0;
		idx = 1;
		while (idx <= N) /* 빠지는 노드 없이 방문하기 위함 */
		{
			if (visited[idx] == 0)
			{
				DFS(idx, arr, visited);
				cnt++;
			}
			idx++;
		}
		printf("%d\n", cnt);
	}
}

void DFS(int start, int *arr, int *visited)
{
	visited[start] = 1;
	/* 방향이 있고, 연결 노드는 단 1개 뿐이므로
		연결노드 여러개를 신경쓸 때 쓰는 while을 써주지 않아도 된다. */
	if (visited[arr[start]] == 0)
	{
		DFS(arr[start], arr, visited);
	}
}