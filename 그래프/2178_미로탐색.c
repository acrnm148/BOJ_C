#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int N; /* 세로 */
int M; /* 가로 */
int cnt;

int dir_x[4] = {0,1,0,-1};
int dir_y[4] = {1,0,-1,0};

struct dir{
	int x;
	int y;
};

void BFS(int **arr, int **visited, int ** check)
{
	int i;
	struct dir * queue = (struct dir *)malloc(sizeof(struct dir) * (N * M));
	int front;
	int rear;
	int pop_x;
	int pop_y;
	int next_x;
	int next_y;
	front = 0;
	rear = 1;
	queue[front].x = 1;
	queue[front].y = 1;
	check[1][1] = 1;
	while (front < rear)
	{
		pop_x = queue[front].x;
		pop_y = queue[front].y;
		i = 0;
		while (i < 4)
		{
			next_x = pop_x + dir_x[i];
			next_y = pop_y + dir_y[i];
			
			if (!(next_x <= 0 || next_x > M || next_y <= 0 || next_y > N))
			{
				if (arr[next_y][next_x] == 1 && visited[next_y][next_x] == 0)
				{
					if (next_x == M && next_y == N)
					{
						check[N][M] = check[pop_y][pop_x] + 1;
						return;
					}
					else
					{
						visited[next_y][next_x] = 1;
						check[next_y][next_x] = check[pop_y][pop_x] + 1;
						queue[rear].x = next_x;
						queue[rear].y = next_y;
						rear++;
						
						//printf("[%d][%d]\n", next_y, next_x);
					}
				}
			}
			i++;
		}
		front++;
	}
}

int main()
{
	int i;
	int j;
	scanf("%d %d", &N, &M);
	/* 그래프 동적할당 */
	int **arr = (int **)malloc(sizeof(int*) * (N+1));
	i = 0;
	while (i <= N)
	{
		arr[i] = (int*)malloc(sizeof(int)*(M+1));
		i++;
	}
	/* 방문기록 동적할당 */
	int **visited = (int**)malloc(sizeof(int)*(N+1));
	i = 0;
	while (i<=N)
	{
		visited[i] = (int*)malloc(sizeof(int)*(M+1));
		memset(visited[i], 0, sizeof(int)*(M+1));
		i++;
	}
	/* 이동한 칸 수 저장하는 배열 동적할당 */
	int **check = (int **)malloc(sizeof(int) *(N+1));
	i = 0;
	while (i <= N)
	{
		check[i] = (int*)malloc(sizeof(int)*(M+1));
		memset(check[i], 0, sizeof(int)*(M+1));
		i++;
	}
	/* 값 입력 */
	char * input = (char*)malloc(sizeof(char)*(M));
	i = 1;
	while (i<=N)
	{
		scanf("%s", input);
		j = 0;
		while (j <= M)
		{
			arr[i][j] = input[j-1] - '0';
			j++;
		}
		i++;
	}
	/* 탐색 */
	visited[1][1] = 1;
	BFS(arr, visited, check);

	printf("%d", check[N][M]);
}