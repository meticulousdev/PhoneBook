#include "common.h"
#include "prsninfo.h"
#include "removebsn.h"

void SearchFromName(PrsnInfo ** dptr, int * ptr)
{
	int i=0;
	int j=0;
	int k=0;
	int len=0;
	char str[STR_LEN];
	
	fputs("Input name: ", stdout);
	fgets(str, STR_LEN, stdin);
	RemoveBSN(str);
	len=strlen(str);
	
	for(k=0; k<(*ptr); k++)
	{
		i=j=0;
		while(1)
		{
			if(str[i]!=((dptr[k]->prsnName)[j]))
			{
				if(((dptr[k]->prsnName)[j])!=0)
				{
					i=0;
					j++;
				}
				else
					break;
			}
			
			else	//	(str[i]==(dptr[k]->prsnName)[j])
			{					
 				if(str[i+1]!=0)	// 이 부분수식이 처음에 잘못 뭐랑 비교하든 i가 아니라 i+1
				{
					i++;
					j++;
				}
				else
				{
					printf("Name: %-10s \t", (dptr[k]->prsnName));
 					printf("Tel: %-10s \n", (dptr[k]->telNum));
 					break;
 				}
 			}
 		}
 	}
}
