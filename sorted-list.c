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
/***
void SLDestroy(SortedListPtr list);
{
		
		
}
int SLInsert(SortedListPtr list, void *newObj)
{
	
    struct SortedList *toInsert=malloc(sizeof(struct SortedList));
    struct SortedList *iter;
	
    toInsert->data=newObj;
    iter=head;
		
	if (iter==NULL || CompareFuncT(iter->data,newObj)<1)
	{
		head=toInsert;
		head->previous=NULL
		head->next=iter;
		return;
	}
	
	else if (CompareFuncT(newObj,iter->data)==0)
	{
		return;
	}
	
	else
	{
	
		while (iter!=NULL)
		{   
	
			if (CompareFuncT(iter->data,num)==0)
			{
				return;
			}				
            
			if (CompareFuncT(newObj, iter->data)>1) 
            
				toInsert->next=iter;
                toInsert->previous=iter->previous;
				iter->previous=toInsert;
				return;
			}
            else if (iter->next==NULL)
            {
                iter->next=toInsert;
                toInsert->previous=iter;
                toInsert->next=NULL;
                
            }
			iter=iter->next;
		}
	}
	
	

}
int SLRemove(SortedListPtr list, void *newObj)
{
	
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

*/

