#include <stdio.h>
#include <stdlib.h>


struct stack
{
	int size;
	int TOP;
	int *arr;
};


int isFull(struct stack *st)
{
	if(st->TOP >= st->size-1)
		return 1;
	return 0;
}

int isEmpty(struct stack *st)
{
	if(st->TOP == -1)
		return 1;
	return 0;
}

void push(struct stack *st)
{
	int x;

	if(isFull(st))
	{
		printf("\nStack Overflow\n\n");
	}
	
	else
	{
		printf("Enter element to push\n");
		scanf("%d", &x);

		st->arr[++st->TOP] = x;
	}
}
int pop(struct stack *st)
{
	if(isEmpty(st))
	{
		printf("\nStack Underflow\n\n");
		return -1;
	}

	else
	{
		int x = st->arr[st->TOP];
		st->TOP--;
		return x;
	}
}

void create(struct stack *st)
{
	printf("Enter stack size\n");
	scanf("%d", &st->size);
	
	st->arr = (int*) malloc (st->size * sizeof(int));
	
	st->TOP = -1;
}

void display(struct stack *st)
{
	printf("\nCURRENT STACK:\n");
	
	for(int i=st->TOP; i>=0; i--)
		printf("%d\n", st->arr[i]);
	printf("\n");
}

void main()
{
	struct stack st;
	int n;
	
	create(&st);
L1:	
	printf("Enter 1 to push, 2 to pop, 3 to display the stack and 4 to exit\n");
	scanf("%d", &n);
	
	switch(n)
	{
		case 1: 
			push(&st);
			goto L1;
		case 2:
			pop(&st);
			goto L1;
		case 3:
			display(&st);
			goto L1;
		case 4:
			exit(-1);
		default:
			printf("Enter valid input\n");
			goto L1;
	}
}

		















	
	
	
	
