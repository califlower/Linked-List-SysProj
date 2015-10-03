#include "sorted-list.c"
#include <stdlib.h>
#include <stdio.h>

int compareDubs(void *p1, void *p2)
{
	double d1 = *(double *)p1;
	double d2 = *(double *)p2;
	
	if(d1 < d2)
	{
		return -1;
	}
	else if(d1 > d2)
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
	SortedListPtr sortedList = SLCreate(&compareDubs, &destruct);
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
	
	display(sortedList);
	
	
	
	
	return 0;
}