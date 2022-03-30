#include <stdio.h>
#include <unistd.h>
#include <stdlib.h> //malloc 
#include <string.h> //fgets

int main()
{
    char small;
    char big;
    char num;
    char space;
    char *str = malloc(sizeof(char)*100);
    memset(str, '.', sizeof(char)*100);
    while (fgets(str, sizeof(char)*100, stdin) != NULL)
    {
        small = '0';
        big = '0';
        num = '0';
        space = '0';
        int idx = 0;
        while (idx <= 100)
        {
            if (str[idx] != '.')
            {
                if (str[idx] >= 'a' && str[idx] <= 'z')
                {
                    small++;
                }
                else if (str[idx] >= 'A' && str[idx] <= 'Z')
                {
                    big++;
                }
                else if (str[idx] >= '0' && str[idx] <= '9')
                {
                    num++;
                }
                else if (str[idx] == ' ')
                {
                    space++;
                }
            }
            idx++;
        }
        write(1, &small, 1);
        write(1, " ", 1);
        write(1, &big, 1);
        write(1, " ", 1);
        write(1, &num, 1);
        write(1, " ", 1);
        write(1, &space, 1);
        write(1, "\n", 1);
        //printf("%d %d %d %d\n", small, big, num, space);
        memset(str, '.', sizeof(char)*100);
    }
}