#include <stdio.h>
#include <stdlib.h> /* malloc */
#include <string.h> /* memset */

int N; /* 노드 개수 */
int M; /* 간선 개수 */

void DFS(int start, int ** arr, int * visited);
void BFS(int start, int ** arr, int * visited);

int main()
{
	int idx;
	int u;
	int v;
	int cnt; /* 연결 요소 개수 */
	int **arr;	  /* 그래프 */
	int *visited; /* 방문기록 */

	scanf("%d %d", &N, &M);

	/* 인접행렬 동적할당 */
	arr = (int **)malloc(sizeof(int) * (N + 1));
	idx = 0; /* 0부터 할당해줘야한다!!! 1부터 할당하면 오류남*/
	while (idx <= N)
	{
		arr[idx] = (int *)malloc(sizeof(int*) * (N + 1));
		/* 초기화 */
		int idx2;
		idx2 = 0;
		while (idx2 <= N)
		{
			arr[idx][idx2] = 0;
			idx2++;
		}
		idx++;
	}

	/* 방문기록 동적할당 */
	visited = (int *)malloc(sizeof(int) * (N + 1));
	memset(visited, 0, sizeof(int) * (N + 1));

	/* 요소 입력 */
	idx = 0;
	while (idx < M)
	{
		scanf("%d %d", &u, &v);
		arr[u][v] = 1;
		arr[v][u] = 1;
		idx++;
	}

	/* DFS & BFS 각각 주석해서 실행 */
	/* 빠짐없이 탐색하기 위해 노드 1부터 N까지 다 돌려봄 */
	idx = 1;
	cnt = 0;
	while (idx <= N)
	{
		if (visited[idx] == 0)
		{
			//DFS(idx, arr, visited);
			BFS(idx, arr, visited);
			cnt++;
		}
		idx++;
	}
	/* 연결요소 개수 */
	printf("%d", cnt);

	/* 할당 해제 */
	//free(visited);
	//free(arr);
}

void DFS(int start, int **arr, int *visited)
{
	/* 방문기록 남김 */
	visited[start] = 1;
	/* 인접 노드 탐색하러 감 */
	int idx;
	idx = 1;
	while (idx <= N)
	{
		if (arr[start][idx] == 1 && visited[idx] == 0)
		{
			DFS(idx, arr, visited);
		}
		idx++;
	}
}

void BFS(int start, int **arr, int *visited)
{
	/* 방문기록 표시 */
	visited[start] = 1;
	/* 큐 생성 */
	int *queue;
	queue = (int *)malloc(sizeof(int) * (N+1));
	int front;
	int rear;
	int pop;
	/* 큐에 시작값 넣어주고 탐색 시작 */
	front = 0;
	rear = 1;
	queue[front] = start;
	
	int idx;
	while (front < rear) /* 큐 원소 다 방문할 때까지 반복 */
	{
		idx = 1;
		/* 맨 앞에 원소 pop 예정 */
		pop = queue[front]; 
		/* 맨 앞에 원소와 인접한 노드 모두 큐에 넣어줌 */
		while (idx <= N)
		{
			if (arr[pop][idx] == 1 && visited[idx] == 0)
			{
				visited[idx] = 1;
				queue[rear] = idx;
				rear++;
			}
			idx++;
		}
		front++;
	}
}