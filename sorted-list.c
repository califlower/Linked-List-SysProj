#include <stdlib.h>
#include <stdio.h>
#include "sorted-list.h"



SortedListPtr SLCreate(CompareFuncT cf, DestructFuncT df)
{
		SortedListPtr list=         malloc(sizeof(SortedListPtr));
		Node *listNode=             malloc(sizeof(Node));
        
        
        
		list->comp=cf;
		list->dest=df;
		list->node=listNode;
		
		return list;
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
    
    /* 
        Node to be inserted and iterator node respecitvely 
    */
    struct Node *toInsert= malloc(sizeof(Node));
    struct Node *iter=list->node; 

    toInsert->data=newObj;
 
    /*  If the list is empty or if the object to be inserted is the largest 
    */
    
    /* 
        If list is empty, or if the objected to be inserted is the largest 
        object. Both cases are the same
    */
	if (iter==NULL || list->comp(newObj,iter->data)==1)
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

            /* 
                if it exists
            */
            
            if (list->comp(iter->data,newObj)==0)
			{
				return 0;
			}

			if (list->comp(newObj,iter->data)==-1)
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
        return 1;
	}
}
int SLRemove(SortedListPtr list, void *newObj)
{
	struct Node *current = list->node;
	
	if (list->comp(current->data,newObj)==0)
    {
        /*Assuming the head is the object to remove */
        
		if (current->next!=NULL)
        {
            current->next->previous=    NULL;
            list->node=                 current->next;
			free(current);
			return 1;
		}
		else 
        {
            list->node=NULL;
            free(current);
            return 1;
		}
		
	}
	
	else
    {
		
		while (current->next!=NULL)
        {
	
			current = current->next;
			
			if (list->comp(current->data,newObj)==0)
            {
                current->previous->next=current->next;
                free(current);
                return 1;
			}
		}
        return 0;
	}
    /*
    return 0;
    */
}


SortedListIteratorPtr SLCreateIterator(SortedList *list)
{
		SortedListIteratorPtr iterator      = malloc(sizeof(SortedListIteratorPtr));
		iterator->iterNode                  = list->node;
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
