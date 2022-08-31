#include "common.h"

int IfNull(FILE * fp)
{
	if(fp==NULL)
	{
		puts("File Open Fail");
		return -1;
	}
	return 0;
}
