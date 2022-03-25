#include <stdio.h>
#include <unistd.h>

int main()
{
    int N;
    scanf("%d", &N);
    int idx;
    int row = 1;
    while (N)
    {
        idx = 1;
        while (idx < row)
        {
            write(1, " ", 1);
            idx++;
        }
        idx = N;
        while (idx > 0)
        {
            write(1, "*", 1);
            idx--;
        }
        write(1, "\n", 1);
        row++;
        N--;
    }
}