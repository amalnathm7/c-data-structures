#include<stdio.h>
#include<stdlib.h>

struct node
{
	int DATA;
	struct node* LINK;
};

struct queue
{
	struct node* FRONT;
	struct node* REAR;
};

void display(struct node* ptr)
{
	printf("Queue:\n");
	while(ptr != NULL)
	{
		printf("%d\n", ptr->DATA);
		ptr = ptr->LINK;
	}
}

void enqueue(struct queue *q, struct node* HEADER)
{	
	int X;
	printf("Enter element\n");
	scanf("%d", &X);
	
	if(q->REAR == NULL)
	{
		q->FRONT = (struct node*) malloc(1*sizeof(struct node));
		HEADER->LINK = q->FRONT;
		q->REAR = q->FRONT;
		q->REAR->DATA = X;
		q->REAR->LINK = NULL;
	}
	else
	{
		q->REAR->LINK = (struct node*) malloc(1*sizeof(struct node));
		q->REAR->LINK->DATA = X;
		q->REAR->LINK->LINK = NULL;
		q->REAR = q->REAR->LINK;
	}
}

int dequeue(struct queue *q, struct node* HEADER)
{
	if(q->FRONT == NULL)
	{
		printf("Queue is empty!\n");
	}
	else
	{
		int X = q->FRONT->DATA;
		HEADER->LINK = q->FRONT->LINK;
		
		free(q->FRONT);
				
		q->FRONT = HEADER->LINK;
		
		if(q->FRONT == NULL)
			q->REAR = NULL;
		
		return X;
	}
}

void main()
{
	struct node* QUEUE_HEAD = (struct node*) malloc(1*sizeof(struct node));
	struct queue q;
	q.FRONT = NULL;
	q.REAR = NULL;
	QUEUE_HEAD->LINK = q.FRONT;

	int flag;
L:
	printf("\nChoose the Queue operation\n");
	printf("1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n4.EXIT\n\n");
	scanf("%d", &flag);
	
	switch(flag)
	{
		case 1:
			enqueue(&q, QUEUE_HEAD);
			goto L;
		case 2:
			dequeue(&q, QUEUE_HEAD);
			goto L;
		case 3:
			display(q.FRONT);
			goto L;
		case 4:
			exit(0);
		default:
			printf("Invalid input!\n");
			goto L;
	}
}
