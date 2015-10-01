#include <stdlib.h>
#include <stdio.h>
#include "sorted-list.h"



struct SortedList *head;

SortedListPtr SLCreate(CompareFuncT cf, DestructFuncT df)
{
		SortedList *list= malloc(sizeof(SortedList));
        Node *node=malloc(sizeof(Node));
		list->comp=cf;
		list->dest=df;
		list->node->next=NULL;
        list->node->previous=NULL;
		head=list;
		return list;
}

void SLDestroy(SortedListPtr list)
{


}
int SLInsert(SortedListPtr list, void *newObj)
{
    /*  Init the insertion node
        Also inits a traversal node
    */
    
    struct Node *toInsert= malloc(sizeof(Node));
    struct Node *iter=list->node;

    toInsert->data=newObj;
 
    /*  If the list is empty or if the object to be inserted is the largest 
    */
    
	if (iter==NULL || list->comp(iter->data,newObj)<1)
	{
		
        toInsert->previous=NULL;
		toInsert->next=iter;
        list->node=toInsert;
		return 1;
	}
    
    /* if the object is already in the list, and it's the first thing there
    */
	else if (list->comp(newObj,iter->data)==0)
	{
		return 0;
	}

	else
	{

		while (iter!=NULL)
		{

            if (list->comp(iter->data,newObj)==0)
			{
				return 0;
			}

			if (list->comp(newObj,iter->data)>1)
            {

				toInsert->next=iter;
                toInsert->previous=iter->previous;
				iter->previous=toInsert;
                return 1;
				
			}
            else if (iter->next==NULL)
            {
                iter->next=toInsert;
                toInsert->previous=iter;
                toInsert->next=NULL;
                return 1;

            }
			iter=iter->next;
		}
	}
}
int SLRemove(SortedListPtr list, void *newObj)
{
    return 0;
}


SortedListIteratorPtr SLCreateIterator(SortedListPtr list)
{

}

void SLDestroyIterator(SortedListIteratorPtr iter)
{

}


void * SLNextItem(SortedListIteratorPtr iter)
{

}


void * SLGetItem( SortedListIteratorPtr iter )
{

}
