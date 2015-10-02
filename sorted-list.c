#include <stdlib.h>
#include <stdio.h>
#include "sorted-list.h"

struct SortedList *head;

SortedList SLCreate(CompareFuncT cf, DestructFuncT df)
{
		struct SortedList *list= malloc(sizeof(SortedList));
		
		if (list == NULL){
		return *list;
		}
        
		list->comp=cf;
		list->dest=df;
		list->node=NULL;
		head=list;
		return *list;
}

void SLDestroy(SortedListPtr list)
{
	struct Node *current = list->node;
	struct Node *next;
	if (current==NULL)
   {
   	free(list);
   	return;
   }
   
   else if (current->next==NULL)
   {
	free(current);
	free(list);
	return;
   }

	else
   {
	   while (current!=NULL)
	   {
		next = current->next;
        free(current);
        current = next;
	   }
	   free(list);
	   return;
   }
}


int SLInsert(SortedListPtr list, void *newObj)
{
    /*  Init the insertion node
        Also inits a traversal node
    */
    
    struct Node *toInsert= malloc(sizeof(Node));
    struct Node *iter=list->node; // holds the head of the list

    toInsert->data=newObj; // holds the void* data
 
    /*  If the list is empty or if the object to be inserted is the largest 
    */
    
	if (iter==NULL || list->comp(newObj,iter->data)<0) // if the node does not exist or if the new data is smaller then the head node
	{ //insert to the top of the list
		
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
	struct Node *current = list->node;
	struct Node *next;
	
	if (current->data == newObj)
    {
	
		if (current->next!=NULL)
        {
			next = current->next;
			free(current);
			current = next;
			return 1;
		}
		else 
        {
		free(current);
		return 1;
		}
		
	}
	
	else{
		
		
		while (current->next!=NULL)
        {
	
			current = current->next;
			
			if (current->data == newObj){
			next = current->next;
			free(current);
			current = next;
			return 1;
			}
		}
	
	}
	
    return 0;
}


SortedListIteratorPtr SLCreateIterator(SortedList *list)
{
		SortedListIteratorPtr iterator = malloc(sizeof(SortedListIterator));
		iterator->iterNode = list->node;
		return iterator;
}

void SLDestroyIterator(SortedListIteratorPtr iter)
{

	free (iter);


}


void * SLNextItem(SortedListIteratorPtr iter)

{
    iter->iterNode=iter->iterNode->next;
    
    if (iter->iterNode==NULL)
        return NULL;
    else
        return iter->iterNode->data;
}


void * SLGetItem( SortedListIteratorPtr iter )
{
   
    if (iter->iterNode==NULL)
        return NULL;
    else
        return iter->iterNode->data;
}
