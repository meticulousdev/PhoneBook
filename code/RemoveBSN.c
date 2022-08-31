#include "common.h"
#include "prsninfo.h"

void RemoveBSN(char str[])
{
	int len=strlen(str);
	str[len-1]=0;
}
