#include <stdlib.h>
#include <stdio.h>
#include "sorted-list.h"



SortedListPtr SLCreate(CompareFuncT cf, DestructFuncT df)
{
	SortedListPtr list =malloc(sizeof(SortedListPtr));
	Node *listNode = malloc(sizeof(Node));
        
	list->comp=						cf;
	list->dest=						df;
	list->node=						listNode;
	list->node->next=					NULL;
		
	return list;
}

void SLDestroy(SortedListPtr list)
{
	struct Node *current=					list->node;
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
			next = 					current->next;
			free(current);
			current=				next;
		}
	   
	free(list);
	return;
   }
}
int SLInsert(SortedListPtr list, void *newObj)
{
	/*  
		Init the insertion node
		Also inits a traversal node
		Node to be inserted and iterator node respectively 
	*/
	
	struct Node *toInsert= 					malloc(sizeof(Node));
	struct Node *iter = malloc(sizeof(Node));
	iter = list->node; 

	toInsert->data=						newObj;
    
	/* 
		If the list is empty
	*/
	if (iter==NULL || iter->data == NULL)
	{ 
		
		toInsert->previous=				NULL;
		toInsert->next=					NULL;
		list->node=					toInsert;
		return 1;
	}
	/*
		If the object is the largest immediatley
	*/
	else if (list->comp(newObj,iter->data)==1)
	{
		toInsert->previous=				NULL;
		toInsert->next=					iter;
		iter->previous=					toInsert;
		list->node=					toInsert;
		return 1;		
	}
	/* 
		If the object is already in the list, and it's the first thing there
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
                if it exists already, don't insert. Return failure to insert
	*/
			if (list->comp(iter->data,newObj)==0)
			{
				return 0;
			}
	/*
		If the next object is smaller. Insert there
	*/
			else if (list->comp(newObj,iter->next->data)==1)
			{
	
				toInsert->next=			iter->next;
				toInsert->previous=		iter;
				toInsert->next->previous=	toInsert;
				iter->next=toInsert;
				return 1;	
			}
			else if (iter->next==NULL)
			{	
				iter->next=			toInsert;
				toInsert->previous=		iter;
				toInsert->next=			NULL;
				
				return 1;

		}
			
		iter=						iter->next;
	}
        return 1;
	}
}
int SLRemove(SortedListPtr list, void *newObj)
{
	struct Node *current=					list->node;
	
	if (list->comp(current->data,newObj)==0)
	{
	/*
		Assuming the head is the object to remove 
	*/
		if (current->next!=NULL)
		{
			current->next->previous=		NULL;
			list->node=				current->next;
			free(current);
			return 1;
		}
		else 
		{
			list->node=				NULL;
			free(current);
			return 1;
		}
	}
	else
	{	
		while (current->next!=NULL)
		{
			current = 				current->next;

			if (list->comp(current->data,newObj)==0)
			{
				current->previous->next=	current->next;
				free(current);
				return 1;
			}
		}
		return 0;
	}
}


SortedListIteratorPtr SLCreateIterator(SortedList *list)
{
	SortedListIteratorPtr iterator= 			malloc(sizeof(SortedListIteratorPtr));
	iterator->iterNode=					list->node;
	return iterator;
}

void SLDestroyIterator(SortedListIteratorPtr iter)
{
	free (iter);
}


void * SLNextItem(SortedListIteratorPtr iter)
{
	iter->iterNode=						iter->iterNode->next;
    
    if (iter->iterNode==NULL)
        return NULL;
    else
        return iter->iterNode->data;
}

void * SLGetItem(SortedListIteratorPtr iter)
{   
    if (iter->iterNode==NULL)
        return NULL;
    else
        return iter->iterNode->data;
}

void displayDouble(SortedList *list)
{
    Node *root=							list->node;
	
    if(root==NULL)
    {
		return;
    }
    while(root->next!=NULL)
    {
		double v=*(double*)(root->data);
		printf("%g",v);
		
		if (root->next!=NULL)
			printf("	");
		root=root->next;
    }
    printf("\n");
}
void displayInt(SortedList *list)
{
    Node *root=							list->node;
	
    if(root==NULL)
    {
		return;
    }
    while(root->next!=NULL)
    {
		int v=*(int*)(root->data);
		printf("%g",v);
		
		if (root->next!=NULL)
			printf("	");
		root=root->next;
    }
    printf("\n");
    
}
