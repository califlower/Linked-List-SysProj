#include "sorted-list.c"
#include <stdlib.h>
#include <stdio.h>

int compareDoubleTest(void *p1, void *p2)
{
	double firstDouble		= *(double *)p1;
	double secondDouble		= *(double *)p2;
	
	if(firstDouble < secondDouble)
	{
		return -1;
	}
	else if(firstDouble > secondDouble)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void destruct(void *a)
{
	free(a);
}
int main(int argc, char **argv) 
{
	/*
		Test cases for ints numbers
	*/
	
	SortedListPtr sortedList = SLCreate(&compareDoubleTest, &destruct);
	double *n1 = malloc(sizeof(double*));
	double *n2 = malloc(sizeof(double*));
	double *n3 = malloc(sizeof(double*));
	double *n4 = malloc(sizeof(double*));
	
	
	*n1 = 1;
	*n2 = 1;
	*n3 = 1;
	*n4 = 1;
	
	
	SLInsert(sortedList, n1);
	SLInsert(sortedList, n2);
	SLInsert(sortedList, n3);
	SLInsert(sortedList, n4);
	displayDouble(sortedList);
	SLRemove(sortedList,n1);
	
	/*2*/
	*n1 = 1;
	*n2 = 2;
	*n3 = 3;
	*n4 = 4;
	
	
	SLInsert(sortedList, n1);
	SLInsert(sortedList, n2);
	SLInsert(sortedList, n3);
	SLInsert(sortedList, n4);
	displayDouble(sortedList);
	SLRemove(sortedList, n1);
	SLRemove(sortedList, n2);
	SLRemove(sortedList, n3);
	SLRemove(sortedList, n4);
	
	
	
	
	/*3*/
	*n1 = 4;
	*n2 = 2;
	*n3 = 4;
	*n4 = 2;
	
	
	SLInsert(sortedList, n1);
	SLInsert(sortedList, n2);
	SLInsert(sortedList, n3);
	SLInsert(sortedList, n4);
	displayDouble(sortedList);
	SLRemove(sortedList, n1);
	SLRemove(sortedList, n2);
	SLRemove(sortedList, n3);
	SLRemove(sortedList, n4);
	
	
	
	/*4*/
	*n1 = 9;
	*n2 = 2;
	*n3 = 10;
	*n4 = 5;
	
	
	SLInsert(sortedList, n1);
	SLInsert(sortedList, n2);
	SLInsert(sortedList, n3);
	SLInsert(sortedList, n4);
	displayDouble(sortedList);
	SLRemove(sortedList, n1);
	SLRemove(sortedList, n2);
	SLRemove(sortedList, n3);
	SLRemove(sortedList, n4);
	
	
	/* Doubles Test */
	printf("\n");
	printf("Doubles Test Case");
	printf("\n");
	/*1*/
	*n1 = 1.4;
	*n2 = 1.4;
	*n3 = 1.4;
	*n4 = 1.4;
	
	
	SLInsert(sortedList, n1);
	SLInsert(sortedList, n2);
	SLInsert(sortedList, n3);
	SLInsert(sortedList, n4);
	displayDouble(sortedList);
	SLRemove(sortedList, n1);
	SLRemove(sortedList, n2);
	SLRemove(sortedList, n3);
	SLRemove(sortedList, n4);
	
	/*2*/
	*n1 = 1.1;
	*n2 = 2.2;
	*n3 = 3.3;
	*n4 = 4.4;
	
	
	SLInsert(sortedList, n1);
	SLInsert(sortedList, n2);
	SLInsert(sortedList, n3);
	SLInsert(sortedList, n4);
	displayDouble(sortedList);
	SLRemove(sortedList, n1);
	SLRemove(sortedList, n2);
	SLRemove(sortedList, n3);
	SLRemove(sortedList, n4);
	
	/*3*/
	*n1 = 4.4;
	*n2 = 2.2;
	*n3 = 4.4;
	*n4 = 2.2;
	
	
	SLInsert(sortedList, n1);
	SLInsert(sortedList, n2);
	SLInsert(sortedList, n3);
	SLInsert(sortedList, n4);
	displayDouble(sortedList);
	SLRemove(sortedList, n1);
	SLRemove(sortedList, n2);
	SLRemove(sortedList, n3);
	SLRemove(sortedList, n4);
	
	
	/*4*/
	*n1 = 9.9;
	*n2 = 2.2;
	*n3 = 10.1;
	*n4 = 5.5;
	
	
	SLInsert(sortedList, n1);
	SLInsert(sortedList, n2);
	SLInsert(sortedList, n3);
	SLInsert(sortedList, n4);
	displayDouble(sortedList);
	SLRemove(sortedList, n1);
	SLRemove(sortedList, n2);
	SLRemove(sortedList, n3);
	SLRemove(sortedList, n4);
	
	return 1;	
}
