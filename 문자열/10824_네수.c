#include <stdio.h>
#include <unistd.h>

int main()
{
    char A;
    char B;
    char C;
    char D;
    scanf("%c %c %c %c", &A,&B,&C,&D);
    write(1, &A, 1);
    write(1, &B, 1);
    write(1, &C, 1);
    write(1, &D, 1);
}