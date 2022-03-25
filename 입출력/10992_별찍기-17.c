#include <stdio.h>
#include <unistd.h>

int main()
{
    int N;
    scanf("%d", &N);
    const int max = N;
    int idx;
    int row = 0;
    while (N)
    {
        idx = 1;
        if (N == 1)
        {
            while (idx < (2 * max))
            {
                write(1, "*", 1);
                idx++;
            }
        }
        else
        {
            while (idx <= (max + row))
            {
                if (idx == N)
                {
                    write(1, "*", 1);
                }
                else if (idx == (max + row))
                {
                    write(1, "*", 1);
                }
                else
                {
                    write(1, " ", 1);
                }
                idx++;
            }
        }
        write(1, "\n", 1);
        row++;
        N--;
    }
}