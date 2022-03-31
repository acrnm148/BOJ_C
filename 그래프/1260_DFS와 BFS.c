#include <stdio.h>
#include <stdlib.h>
#include <string.h> //memset
int arr[1001][1001];
int visited[1001];
int queue[1001]; // queue 이름의 배열 생성
int N;			 /* 정점 개수 */
int M;			 /* 간선 개수 */

/* DFS */
void DFS(int start)
{
	visited[start] = 1;
	printf("%d ", start); /* 방문한점 출력 */
	int idx;
	idx = 1;
	while (idx <= N)
	{
		if (arr[start][idx] == 1 && visited[idx] == 0)
		{
			DFS(idx);
		}
		idx++;
	}
}

/* BFS */
void BFS(int start)
{
	visited[start] = 1;
	printf("%d ", start);
	int idx;
	int front;
	int rear;
	int pop;
	front = 0;
	rear = 1;
	queue[front] = start;
	while (front < rear)
	{
		pop = queue[front];
		idx = 0;
		while (idx <= N)
		{
			if (arr[pop][idx] == 1 && visited[idx] == 0)
			{
				visited[idx] = 1;
				printf("%d ", idx);
				queue[rear] = idx;
				rear++;
			}
			idx++;
		}
		front++;
	}
}

int main()
{
	int V; /* 시작정점 번호 */
	int idx;
	int n;
	int v;
	scanf("%d %d %d", &N, &M, &V);

	/* 요소 입력 */
	idx = 1;
	while (idx <= M)
	{
		scanf("%d %d", &n, &v);
		arr[n][v] = 1;
		arr[v][n] = 1;
		idx++;
	}

	/* DFS로 탐색 */
	DFS(V);
	/* 초기화 */
	memset(visited, 0, sizeof(visited));
	printf("\n");
	/* BFS로 탐색 */
	BFS(V);
}