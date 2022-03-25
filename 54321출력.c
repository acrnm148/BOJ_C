#include <stdio.h>
#include <unistd.h>

int main()
{
	char N;
	scanf ("%c", &N);
	
	while ((N -'0') > 0)
	{
		write (1, &N, 1);
		write (1, "\n", 1);
		N--;
	}
}