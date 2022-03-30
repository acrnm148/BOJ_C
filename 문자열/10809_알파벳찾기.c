#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h> //for memset
int main()
{
    char * S = malloc(sizeof(char)*101);
    char * atoz = malloc(sizeof(char)*27);

    memset(S, '0', sizeof(char)*101);
    memset(atoz, '-1', sizeof(char)*27);

    scanf("%s", S);

    int idx = 0;
    int idx2;
    while (idx <= 100)
    {
        if (S[idx] != '0')
        {
            idx2 = 1;
            while (idx2 <= 26)
            {
                if (atoz[idx] == '-1'&&(S[idx] - 'a' + 1 == idx2))
                {
                    atoz[idx2] = idx;   
                }
                idx2++;
            }
        }
        idx++;
    }
    idx = 1;
    while (idx <= 26)
    {
        write(1, &atoz[idx], 1);
        write(1, " ", 1);
        //printf("%c ", atoz[idx]);
        idx++;
    }
    free(S);
    free(atoz);
}