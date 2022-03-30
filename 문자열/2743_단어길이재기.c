#include <stdio.h>
#include <unistd.h> //write()
#include <stdlib.h> //malloc()
#include <string.h> //memset()
int main()
{
    char *str = malloc(sizeof(char) * 100);
    memset(str, '0', sizeof(char) * 100);
    scanf("%s",str);
    int idx = 0;
    char cnt = '0';
    while (idx <= 100)
    {
        if(str[idx] != '0')
        {
            cnt++;
        }
        idx++;
    }
    cnt -=2;
    write(1, &cnt, 1);
}