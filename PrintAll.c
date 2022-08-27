#include "common.h"
#include "prsninfo.h"

void PrintAll(PrsnInfo ** dptr, int * ptr)
{
	int i=0;

	for(i=0; i<(*ptr); i++)
	{
		printf("Name: %-10s \t", (dptr[i]->prsnName));
 		printf("Tel: %-10s \n", (dptr[i]->telNum));
	}
}
