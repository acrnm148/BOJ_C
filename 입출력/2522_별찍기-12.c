#include <stdio.h>
#include <unistd.h>

int main()
{
    int N;
    scanf("%d", &N);
    int max = N;
    N = N * 2;
    int row = 1;
    int idx;
    while (N > 1)
    {
        idx = 1;
        while (idx <= max)
        {
            if (idx <= (max - row))
            {
                write(1, " ", 1);
            }
            else
            {
                write(1, "*", 1);
            }
            idx++;
        }
        write(1, "\n", 1);
        if (N > (max + 1))
        {
            row++;
        }
        else if (N <= (max + 1))
        {
            row--;
        }
        N--;
    }
}