#include <stdio.h>
#include <unistd.h>

int main()
{
    int N;
    scanf("%d", &N);
    const int max = N;
    int idx;
    int row = 1;
    while (N)
    {
        idx = 1;
        while (idx <= (max + row - 1))
        {
            if (idx <= (max - row))
            {
                write(1, " ", 1);
            }
            else if (idx > (max - row))
            {
                if ((max + row - 1) % 2 == 1)
                {
                    if (idx % 2 == 1)
                    {
                        write(1, "*", 1);
                    }
                    else
                    {
                        write(1, " ", 1);
                    }
                }
                else if ((max + row - 1) % 2 == 0)
                {
                    if (idx % 2 == 1)
                    {
                        write(1, " ", 1);
                    }
                    else
                    {
                        write(1, "*", 1);
                    }
                }
            }
            idx++;
        }
        write(1, "\n", 1);
        row++;
        N--;
    }
}