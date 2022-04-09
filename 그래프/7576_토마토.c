#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N; /* 세로 */
int M; /* 가로 */
int dir_x[4] = {0,1,0,-1};
int dir_y[4] = {1,0,-1,0};
struct dir{
	int x;
	int y;
};

int BFS(int ** arr, int ** visited, struct dir * queue, int **check)
{
	int day;
	day = 0;
	int front;
	int rear;
	int pop_x;
	int pop_y;
	front = 0;
	rear = 1;
	int next_x;
	int next_y;
	while (front < rear)
	{
		pop_x = queue[front].x;
		pop_y = queue[front].y;
		
		/* 방향 체크 */
		int idx;
		idx = 0;
		while (idx < 4)
		{
			next_x = pop_x + dir_x[idx];
			next_y = pop_y + dir_y[idx];
			/* 범위 벗어나면 오류난다 */
			if (!(next_x <= 0 || next_x > M || next_y <= 0 || next_y > N))
			{
				if (arr[next_y][next_x] == 0 && visited[next_y][next_x] == 0)
				{
					/* 익는 일수 체크 */
					check[next_y][next_x] = check[pop_y][pop_x] + 1;
					day = check[next_y][next_x];
					/* 방문기록 추가 */
					visited[next_y][next_x] = 1;
					/* 안익음 -> 익음 */
					arr[next_y][next_x] = 1;
					/* 큐에 추가 */
					queue[rear].x = next_x;
					queue[rear].y = next_y;
					rear++;
				}
			}
			idx++;
		}
		front++;
	}
	return day;
}

int main()
{
	scanf("%d %d", &M, &N);
	struct dir* queue = (struct dir*)malloc(sizeof(struct dir)*(M*N));
	int i;
	int j;
	/* 그래프 동적할당 */
	i = 0;
	int **arr = (int**)malloc(sizeof(int*)*(N+1));
	while (i <= N)
	{
		arr[i] = (int*)malloc(sizeof(int)*(M+1));
		i++;
	}
	/* 방문기록 동적할당 */
	i = 0;
	int **visited = (int**)malloc(sizeof(int*)*(N+1));
	while (i<=N)
	{
		visited[i] = (int*)malloc(sizeof(int)*(M+1));
		memset(visited[i], 0, sizeof(int)*(M+1));
		i++;
	}
	/* 익는 일수 체크 배열(check) 동적할당 */
	int idx;
	idx = 0;
	int** check = (int**)malloc(sizeof(int*)*(N+1));
	while (idx <= N)
	{
		check[idx] = (int*)malloc(sizeof(int)*(M+1));
		memset(check[idx], 0, sizeof(int)*(M+1));
		idx++;
	}
	/* 입력 */
	int state_all;
	state_all = 1;
	int front;
	front = 0;
	i=1;
	while (i <= N)
	{
		j = 1;
		while (j <= M)
		{
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 1) /* 1이 여러개일 때를 생각 - 값이 1이면 큐에 넣어줌 */
			{
				check[j][i] = 1;
				queue[front].x = j;
				queue[front].y = i;
				front++;
			}
			else if (arr[i][j] != 1)
			{
				state_all = 0; /* 안익은 토마토가 1개라도 있다면 */
			}
			j++;
		}
		i++;
	}

	/* 탐색 */
	printf("why??");
	int day;
	day = BFS(arr, visited, queue, check); 

	/* 출력 */
	if (state_all == 1)
	{
		printf("1");
	}
	else if (state_all == 0)
	{
		i = 1; 
		while (i <= N)
		{
			j = 1;
			while (j <= M)
			{
				if (arr[i][j] == 0)
				{
					printf("-1\n");
					return 0;
				}
				printf("%d ", check[i][j]);
				j++;
			}
			printf("\n");
			i++;
		}
		if (day != 0) 
			printf("%d\n", day-1);
		else
			printf("%d\n", day);
	}
}
