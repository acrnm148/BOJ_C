#include <stdio.h>
#include <unistd.h>

int main()
{
    int N;
    scanf("%d", &N);
    int row = 1;
    int idx;
    while (N)
    {
        idx = 1;
        while (idx <= N)
        {
            write(1, "*", 1);
            idx++;
        }
        write(1, "\n", 1);
        N--;
    }
}