#include "common.h"
#include "removebsn.h"

void DeletePersonInfo(PrsnInfo ** dptr, int * ptr)
{
	int i=0;
	int len=0;
	char str[STR_LEN];
	
	fputs("Input full name: ", stdout);
	fgets(str, STR_LEN, stdin);
	RemoveBSN(str);
	len=strlen(str);
	
	while(i<(*ptr))
	{
		if(strncmp(str, (dptr[i]->prsnName), len)!=0)
		{
			if((i+1)==(*ptr))
			{
				puts("[INCONSISTENCY]");
				DeletePersonInfo(dptr, ptr);
				break;
			}		
			i++;
		}
		else
		{
			if(len!=strlen((dptr[i]->prsnName)))
			{
				puts("[INCONSISTENCY]");
				DeletePersonInfo(dptr, ptr);
				break;
			}
			else
			{
				strcpy((dptr[i]->prsnName), (dptr[(*ptr)-1]->prsnName));
				strcpy((dptr[i]->telNum), (dptr[(*ptr)-1]->telNum));
				(*ptr)--;
				break;
			}
		}
	}
}
