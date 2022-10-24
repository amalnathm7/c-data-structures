#include <stdio.h>
#include <stdlib.h>

struct node
{
	int DATA;
	struct node* LINK;
};

void display(struct node* ptr)
{
	printf("Stack:\n");
	while(ptr != NULL)
	{
		printf("%d\n", ptr->DATA);
		ptr = ptr->LINK;
	}
}

struct node* push(struct node* HEADER)
{
	struct node* ptr = (struct node*) malloc(1*sizeof(struct node));
	
	int X;
	printf("Enter element\n");
	scanf("%d", &X);
	
	ptr->DATA = X;
	ptr->LINK = HEADER->LINK;
	HEADER->LINK = ptr;
	return ptr;
}

int pop(struct node* HEADER)
{
	if(HEADER->LINK == NULL)
	{
		printf("Stack is empty!\n");
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

void main()
{
	struct node* STACK_HEAD = (struct node*) malloc(1*sizeof(struct node));
	struct node* TOP = NULL;
	STACK_HEAD->LINK = TOP;

	int flag;
L:
	printf("\nChoose the Stack operation\n");
	printf("1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\n\n");
	scanf("%d", &flag);
	
	switch(flag)
	{
		case 1:
			TOP = push(STACK_HEAD);
			goto L;
		case 2:
			pop(STACK_HEAD);
			TOP = STACK_HEAD->LINK;
			goto L;
		case 3:
			display(TOP);
			goto L;
		case 4:
			exit(0);
		default:
			printf("Invalid input!\n");
			goto L;
	}
}
