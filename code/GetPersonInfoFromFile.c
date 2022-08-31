#include "common.h"
#include "prsninfo.h"
#include "removebsn.h"

PrsnInfo * GetPersonInfoFromFile(FILE * fp)
{
	PrsnInfo * ipi=(PrsnInfo*)malloc(sizeof(PrsnInfo));
	
	fgets((ipi->prsnName), STR_LEN, fp);
	RemoveBSN((ipi->prsnName));
	
	fgets((ipi->telNum), STR_LEN, fp);
	RemoveBSN((ipi->telNum));

	return ipi;
}
