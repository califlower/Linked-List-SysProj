#include "sorted-list.c"
#include <stdlib.h>
#include <stdio.h>

int compareIntegerTest(void *p1, void *p2)
{
	int firstInt 			= *(int *)p1;
	int secondInt 			= *(int *)p2;
	
	if(firstInt < secondInt)
	{
		return -1;
	}
	else if(firstInt > secondInt)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
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
		Test cases for double numbers
	*/
	
	SortedListPtr sortedList = SLCreate(&compareDoubleTest, &destruct);
	double *n1 = malloc(sizeof(double*));
	double *n2 = malloc(sizeof(double*));
	double *n3 = malloc(sizeof(double*));
	double *n4 = malloc(sizeof(double*));
	double *n5 = malloc(sizeof(double*));
	double *n6 = malloc(sizeof(double*));
	
	*n1 = 5.0;
	*n2 = 10.0;
	*n3 = 3.0;
	*n4 = 8.0;
	*n5 = 11.0;
	*n6 = 1.0;
	
	SLInsert(sortedList, n1);
	SLInsert(sortedList, n2);
	SLInsert(sortedList, n5);
	SLInsert(sortedList, n3);
	SLInsert(sortedList, n6);
	displayDouble(sortedList);
	
	/*
	SLRemove(sortedList, n1);
	SLRemove(sortedList, n2);
	SLRemove(sortedList, n5);
	SLRemove(sortedList, n3);
	SLRemove(sortedList, n6);
	
	
	display(sortedList);
	
	*/
	
	
	return 0;
}
