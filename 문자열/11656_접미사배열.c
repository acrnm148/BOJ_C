#include <stdio.h>
#include <stdlib.h> //malloc
#include <unistd.h> //write
#include <string.h> //memset
int main()
{
    char *str = malloc(sizeof(char) * 1000);
    memset(str, '0', sizeof(char) * 1000);
    scanf("%s", str);
    int idx = 0;
    int cnt = 0;
    /* 문자열 길이 카운트 */
    while (idx <= 1000)
    {
        if (str[idx] != '0')
        {
            cnt++;
        }
        else
        {
            break;
        }
        idx++;
    }
    cnt--;
    //printf("%d", cnt);
    
    /* 동적할당 */
    char **tails = (char**)malloc(sizeof(char*) * cnt); /* 높이동적할당 */
    idx = 0;
    while (idx < cnt) /* 너비동적할당 */
    {
        tails[idx] = (char*)malloc(sizeof(char) * cnt);
        idx++;
    }

    /* 값넣어주기 */
    idx = 0;
    while(idx < cnt)
    {
        int idx2 = idx;
        while(idx2 < cnt)
        {
            tails[idx][idx2] = str[idx2];
            idx2++;
        }
        idx++;
    }
    

    printf("here:==========%s", tails[1]);
    /* 정렬============ */
    char * tmp = malloc(sizeof(char) * cnt);
    idx = 0;
    int idx2 = idx;
    while (idx < cnt)
    {
        while (idx2 < cnt-1)
        {
            if (tails[idx][idx2] > tails[idx][idx2 + 1])
            {
                
            }
            idx2++;
        }
        idx++;
    }

    /* 배열 출력 */
    idx = 0;
    while(idx < cnt)
    {
        int idx2 = idx;
        while(idx2 < cnt)
        {
            //printf("%c", tails[idx][idx2]);
            write(1, &tails[idx][idx2], 1);
            idx2++;
        }
        idx++;
        write(1, "\n", 1);
    }

    /* 동적 할당 해제 */
    idx = 0;
    while(idx < cnt)
    {
        free(tails[idx]);
        idx++;
    }
    free(tails);
}