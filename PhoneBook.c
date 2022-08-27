#include "common.h"
#include "prsninfo.h"
#include "choosetheitem.h"
#include "insertpersoninfo.h"
#include "printall.h"
#include "searchfromname.h"
#include "deletepersoninfo.h"

#include "ifnull.h"
#include "getpersoninfofromfile.h"

#define VERSION "\n *ver 0.2* \n"
/* 
사람의 숫자가 얼마가 될지 모른다. 들어올때마다 공간을 동적할당으로 늘려나가자. 5명씩 끊어서 하는게 좋겠다.
*/
#define PRSN_NUM 20
int main(void)
{
	PrsnInfo * mpi[PRSN_NUM];
	char * ptr1;
	char * ptr2;
	int prsnNum=0;
	
	int num=0;
	int i=0;
	FILE * fp;	
//----------------------------------------------------------------------
	puts(VERSION);
//----------------------------------------------------------------------
	fp=fopen("PhoneBook.txt", "at");
	if(IfNull(fp)==-1)
		return -1;
	fclose(fp);	
			
	fp=fopen("PhoneBook.txt", "rt");
	if(IfNull(fp)==-1)
		return -1;
		
//	제일 처음이라 전달 받은 prsnNum이 쓰레기 값인 경우는?	printf("%d", prsnNum); 결과가 0.
	fscanf(fp, "%d", &prsnNum);	
	for(i=0; i<prsnNum; i++)
		mpi[i]=GetPersonInfoFromFile(fp);
	
	fclose(fp);
	
	while(1)
	{
		num=ChooseTheItem();
		
		if(num==1)
		{
			puts("[INSERT]");
			fp=fopen("PhoneBook.txt", "at");
			if(IfNull(fp)==-1)
				return -1;
			
			if((prsnNum+1)!=PRSN_NUM)
				mpi[prsnNum]=InsertPersonInfo();
			else
				puts("Have no available memory!");
			
			fputs((mpi[prsnNum]->prsnName), fp);
			fputc('\n', fp);
			fputs((mpi[prsnNum]->telNum), fp);
			fputc('\n', fp);
			fclose(fp);				
			prsnNum++;
		}
		else if(num==2)
		{
			puts("[DELETE]");
			SearchFromName(mpi, &prsnNum);
			DeletePersonInfo(mpi, &prsnNum);
		}
		else if(num==3)
		{
			puts("[SEARCH]");
			SearchFromName(mpi, &prsnNum);	
		}	
		else if(num==4)
		{
			puts("[PRINT ALL DATA]");
			PrintAll(mpi, &prsnNum);
		}
		else if(num==5)
		{
			puts("[EXIT THE PHONEBOOK]");
			break;
		}
		else
			puts("[WRONG INPUT]");
	}

	fp=fopen("PhoneBook.txt", "wt");
	if(IfNull(fp)==-1)
		return -1;
	
	fprintf(fp, "%d", prsnNum);	
	for(i=0; i<prsnNum; i++)
	{
		fputs((mpi[i]->prsnName), fp);
		fputc('\n', fp);
		fputs((mpi[i]->telNum), fp);
		fputc('\n', fp);
		free(mpi[i]);
	}
	
	fclose(fp);
	
	
	return 0;
}	