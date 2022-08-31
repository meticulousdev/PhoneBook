#include "common.h"
#include "prsninfo.h"
#include "removebsn.h"

PrsnInfo * InsertPersonInfo(void)
{
	PrsnInfo * ipi=(PrsnInfo*)malloc(sizeof(PrsnInfo));
	
	fputs("Input Name: ", stdout);
	fgets((ipi->prsnName), STR_LEN, stdin);
	RemoveBSN((ipi->prsnName));
	
	fputs("Input Tel Number: ", stdout);
	fgets((ipi->telNum), STR_LEN, stdin);
	RemoveBSN((ipi->telNum));

	puts("Data Inserted");
	
	return ipi;
}
