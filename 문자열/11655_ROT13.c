#include <stdio.h>
#include <unistd.h> /* write() */
#include <stdlib.h> /* malloc() */
#include <string.h> /* memset() */

int main()
{
    char *str = malloc(sizeof(char)*100);
    memset(str, '.', 1);
    scanf("%[^\n]s", str);
    int idx = 0;
    while (idx <= 100)
    {
        if (str[idx] != '.')
        {
            /* 소문자 */
            if (str[idx] >= 'a' && str[idx] <= 'z')
            {
                if (str[idx] >= 'n' && str[idx] <= 'z')
                {
                    str[idx]-=13;
                }
                else
                {
                    str[idx]+=13;
                }
            }
            /* 대문자 */
            else if (str[idx] >= 'A' && str[idx] <= 'Z')
            {
                if (str[idx] >= 'N' && str[idx] <= 'Z')
                {
                    str[idx]-=13;
                }
                else
                {
                    str[idx]+=13;
                }
            }
        }
        else 
        {
            break;
        }
        write(1, &str[idx], 1);

        idx++;
    }
}