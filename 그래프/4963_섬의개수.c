#include <stdio.h> /* printf */
#include <string.h>
#include <stdlib.h>
int w;
int h;

int dir_w[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dir_h[8] = {1, 1, 1, 0, 0, -1, -1, -1};

struct dir{
	int x;
	int y;
};

void BFS(int **arr, int **visited, int i, int j)
{
	visited[i][j] = 1;
	/* BFS 준비물 queue, front, rear, pop */
	/* x,y좌표가 있기 때문에 큐는 구조체로 선언 */
	struct dir *queue = (struct dir *)malloc(sizeof(struct dir) * (w*h));
	int front;
	int rear;
	int pop_x;
	int pop_y;
	front = 0;
	rear = 1;
	/* 큐의 front에 첫 값 넣어줌 */
	queue[front].x = j;
	queue[front].y = i;
	/* 주변 노드 탐색 */
	int next_w;
	int next_h;
	int idx;
	/* 큐의 시작원소(front)에서 마지막원소(rear)까지 - 큐가 빌 때 까지 */
	while (front < rear) /* rear에는 값을 넣어줘야 하므로 < */
	{
		/* 큐 처음에 넣은 값을 pop */
		pop_y = queue[front].y;
		pop_x = queue[front].x;

		idx = 0;
		while (idx < 8)
		{
			next_w = pop_x + dir_w[idx];
			next_h = pop_y + dir_h[idx];
			if (!(next_w <= 0 || next_w > w || next_h <= 0 || next_h > h)) /* 범위 */
			{
				if (arr[next_h][next_w] == 1 && visited[next_h][next_w] == 0) /* 그래프 값이 1이고 방문기록이 0일 때 */
				{
					visited[next_h][next_w] = 1;
					queue[rear].x = next_w;
					queue[rear].y = next_h;
					rear++;
				}
			}
			idx++;
		}
		front++;
	}
}

int main()
{
	int cnt; /* 섬의 개수 */
	int i;
	int j;
	while (scanf("%d %d", &w, &h))
	{
		if (w == 0 && h == 0)
			return 0;
		/* 그래프 동적할당 */
		int **arr = (int **)malloc(sizeof(int *) * (h + 1));
		i = 0;
		while (i <= h)
		{
			arr[i] = (int *)malloc(sizeof(int) * (w + 1));
			i++;
		}
		/* 방문기록 동적할당 */
		int **visited = (int **)malloc(sizeof(int *) * (h + 1));
		i = 0;
		while (i <= h)
		{
			visited[i] = (int *)malloc(sizeof(int) * (w + 1));
			memset(visited[i], 0, sizeof(int) * (w + 1));
			i++;
		}
		/* 입력 */
		i = 1;
		while (i <= h)
		{
			j = 1;
			while (j <= w)
			{
				scanf("%d", &arr[i][j]);
				j++;
			}
			i++;
		}
		/* BFS로 탐색 */
		cnt = 0;
		i = 1;
		while (i <= h)
		{
			j = 1;
			while (j <= w)
			{
				if (arr[i][j] == 1 && visited[i][j] == 0)
				{
					cnt++;
					BFS(arr, visited, i, j);
				}
				j++;
			}
			i++;
		}
		/* 출력 */
		printf("%d\n",cnt);
		/* 동적할당 해제 */
		i = 0;
		while (i <= h)
		{
			free(arr[i]);
			i++;
		}
		free(arr);
		i = 0;
		while (i <= h)
		{
			free(visited[i]);
			i++;
		}
		free(visited);
	}
}