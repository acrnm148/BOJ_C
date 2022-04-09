#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N; /* 지도 크기 */
int cnt[1000] = {0, }; /* 집 카운트 */
int dir_x[4] = {0,1,0,-1};
int dir_y[4] = {1,0,-1,0};
int cnt_;

int DFS(int** arr, int** visited, int start_y, int start_x)
{
	visited[start_y][start_x] = 1;
	int next_x;
	int next_y;
	int idx;
	idx = 0;
	cnt_++;
	
	while (idx < 4)
	{
		next_x = start_x + dir_x[idx];
		next_y = start_y + dir_y[idx];
		/* 범위를 지정해줘야 한다 */
		if (!(next_x <= 0 || next_x > N || next_y <= 0 || next_y > N))
		{
			if (arr[next_y][next_x] == 1 && visited[next_y][next_x] == 0)
			{
				visited[next_y][next_x] = 1;
				DFS(arr, visited, next_y, next_x);
			}
		}
		idx++;
	}
	return cnt_;
}

int main()
{
	int idx;
	int j;
	scanf("%d",&N);
	
	/* 그래프 동적할당 */
	idx = 0;
	int **arr = (int **)malloc(sizeof(int*)*(N+1));
	while (idx <= N)
	{
		arr[idx] = (int *)malloc(sizeof(int)*(N+1));
		idx++;
	}
	/* 방문기록 동적할당 */
	idx = 0;
	int ** visited = (int**)malloc(sizeof(int*)*(N+1));
	while (idx <= N)
	{
		visited[idx] = (int*)malloc(sizeof(int)*(N+1));
		memset(visited[idx], 0, sizeof(int)*(N+1));
		idx++;
	}
	/* 값 입력 */
	char input[26];
	idx = 1;
	while (idx <= N)
	{
		j = 1;
		scanf("%s", input);
		while (j <= N)
		{
			arr[idx][j] = input[j-1] - '0';
			j++;
		}
		idx++;
	}
	/* DFS 탐색 */
	int i; /* cnt 배열 인덱스 */
	i = 0;
	idx = 1;
	while (idx <= N)
	{
		j = 1;
		while (j <= N)
		{
			if (arr[idx][j] == 1 && visited[idx][j] == 0)
			{
				cnt_ = 0;
				cnt[i] = DFS(arr, visited, idx, j);
				i++;
			}
			j++;
		}
		idx++;
	}
	/* 단지수 출력 */
	printf("%d\n", i);
	/* 집 수 오름차순 */
	idx= 0;
	int tmp;
	while (idx < i)
	{
		j = 0;
		while (j < (i - idx -1))
		{
			if (cnt[j] > cnt[j+1])
			{
				tmp = cnt[j];
				cnt[j] = cnt[j+1];
				cnt[j+1] = tmp;
			}
			j++;
		}
		idx++;
	}
	/* 집 수 출력 */
	idx = 0;
	while (cnt[idx] != 0)
	{
		printf("%d\n",cnt[idx]);
		idx++;
	}
}