#include <stdio.h>

void CleanLineFromReadBuffer(void)
{
	while(getchar()!='\n');
}
