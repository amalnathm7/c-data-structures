#include<stdio.h>
#include<stdlib.h>

struct node
{
	int DATA;
	struct node* LINK;
};

void display(struct node* ptr)
{
	printf("The list:\n");
	while(ptr!=NULL)
	{
		printf("%d\n", ptr->DATA);
		ptr = ptr->LINK;
	}
}

void insertFront(struct node* HEADER)
{
	struct node* ptr = (struct node*) malloc(1* sizeof(struct node*));
	
	int X;
	printf("Enter element\n");
	scanf("%d", &X);

	ptr->DATA = X;
	ptr->LINK = HEADER->LINK;
	HEADER->LINK = ptr;
}

void insertEnd(struct node* ptr)
{	
	int X;
	printf("Enter element\n");
	scanf("%d", &X);
	
	while(ptr->LINK != NULL)
	{
		ptr = ptr->LINK;
	}
	
	ptr->LINK = (struct node*) malloc(1* sizeof(struct node*));
	ptr->LINK->DATA = X;
	ptr->LINK->LINK = NULL;
}

void insertAny(struct node* ptr)
{

	if(ptr == NULL)
	{
		printf("Cannot be inserted! (List is empty)\n");
	}
	else
	{
		int X, KEY;
		printf("Enter element\n");
		scanf("%d", &X);
		printf("Enter the KEY element\n");
		scanf("%d", &KEY);
	
		while(ptr->DATA != KEY)
		{
			if(ptr->LINK == NULL)
			{
				printf("Cannot be inserted at specified position! (KEY not found)\n");
				break;
			}
			else
				ptr = ptr->LINK;
		}
		
		if(ptr->DATA == KEY)
		{
			struct node* ptr1 = (struct node*) malloc(1*sizeof(struct node*));
			ptr1->DATA = X;
			ptr1->LINK = ptr->LINK;
			ptr->LINK = ptr1;
		}
	}	
}

int deleteFront(struct node* HEADER)
{
	if(HEADER->LINK == NULL)
	{
		printf("Cannot be deleted! (List is empty)\n");
	}
	else
	{
		struct node* ptr = HEADER->LINK;
		
		int X = ptr->DATA;
		HEADER->LINK = ptr->LINK;
		free(ptr);
		
		return X;
	}
}

int deleteEnd(struct node* ptr)
{	
	if(ptr->LINK == NULL)
	{
		printf("Cannot be deleted! (List is empty)\n");
	}
	else
	{
		while(ptr->LINK->LINK != NULL)
		{
			ptr = ptr->LINK;
		}
		
		int X = ptr->LINK->DATA;
		free(ptr->LINK);
		ptr->LINK = NULL;
		
		return X;
	}	
}

void deleteAny(struct node* ptr1)
{
	struct node* ptr = ptr1->LINK;
	
	if(ptr == NULL)
	{
		printf("Cannot be deleted! (List is empty)\n");
	}
	else
	{
		int KEY;
		printf("Enter the KEY element\n");
		scanf("%d", &KEY);
	
		while(ptr->DATA != KEY && ptr->LINK != NULL)
		{
			ptr1 = ptr;
			ptr = ptr->LINK;
		}

		if(ptr->DATA == KEY)
		{
			ptr1->LINK = ptr->LINK;
			free(ptr);
		}
		else
		{
			printf("Cannot be deleted from specified position! (KEY not found)\n");
		}
	}	
}

void main()
{
	struct node* HEADER = (struct node*) malloc(1*sizeof(struct node));
	HEADER->LINK = NULL;
	
	int flag;
L:
	printf("\nChoose the Linked List operation\n");
	printf("1.Display\n2.Insert at Beginning\n3.Insert at End\n4.Insert at a Specified Position\n");
	printf("5.Delete from Beginning\n6.Delete from End\n7.Delete from a Specified Position\n8.Exit Program\n\n");
	scanf("%d", &flag);
	
	switch(flag)
	{
		case 1:
			display(HEADER->LINK);
			goto L;
	
		case 2:
			insertFront(HEADER);
			goto L;
	
		case 3:
			insertEnd(HEADER);
			goto L;
		
		case 4:
			insertAny(HEADER->LINK);
			goto L;
		
		case 5:
			deleteFront(HEADER);
			goto L;
		
		case 6:
			deleteEnd(HEADER);
			goto L;
		
		case 7:
			deleteAny(HEADER);
			goto L;
			
		case 8:
			exit(0);
				
		default:
			printf("Invalid input\n\n");
			goto L;
	}
}
