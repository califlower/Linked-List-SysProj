#ifndef SORTED_LIST_H
#define SORTED_LIST_H

#include <stdlib.h>


typedef int (*CompareFuncT)( void *, void * );
typedef void (*DestructFuncT)( void * );
typedef struct Node Node;
typedef struct SortedList* SortedListPtr;
typedef struct SortedList SortedList;
typedef struct SortedListIterator* SortedListIteratorPtr;
typedef struct SortedListIterator SortedListIterator;

struct Node 
{
    void *data;
    struct Node *next;
    struct Node *previous;
};

struct SortedList
{
	CompareFuncT comp;
	DestructFuncT dest;
	struct Node *node;
};

struct SortedListIterator
{

        struct Node *iterNode;
};
	
#endif
