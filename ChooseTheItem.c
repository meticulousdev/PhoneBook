#include "common.h"

int ChooseTheItem(void)
{
	int num=0;
	puts("\n*****MENU****");
	puts("1. Insert");
	puts("2. Delete");
	puts("3. Search");
	puts("4. Print All");
	puts("5. Exit");
	fputs("Choose the item: ", stdout);
	scanf("%d", &num);
	getchar();
	return num;
}
