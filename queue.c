#include<stdio.h>
#include<stdlib.h>

struct queue
{
	int FRONT;
	int REAR;
	int *arr;
	int SIZE;
	int count;
	int *prioarr;
};

void insert_rear_dq(struct queue *q)
{
	int X;
	
	if(q->REAR == q->SIZE-1)
		printf("Queue is full!\n");
	else
	{
		printf("Enter the number to be inserted\n"); 
		scanf("%d", &X);
		
		if(q->FRONT == -1)
			q->FRONT = 0;
		q->REAR += 1;
		q->arr[q->REAR] = X;
	}
}

void insert_front_dq(struct queue *q)
{
	int X;
	
	if(q->FRONT == 0)
		printf("Cannot perform insertion at FRONT!\n");
		
	else if(q->FRONT == -1)
	{
		printf("Enter the number to be inserted\n"); 
		scanf("%d", &X);
		
		q->FRONT = 0;
		q->REAR = 0;
		q->arr[q->FRONT] = X;
	}
	else
	{
		printf("Enter the number to be inserted\n"); 
		scanf("%d", &X);
		
		q->FRONT -= 1;
		q->arr[q->FRONT] = X;
	}
}

int delete_rear_dq(struct queue *q)
{
	if(q->REAR == -1)
		printf("Queue is empty!\n");
	else 
	{
		int X = q->arr[q->REAR];
		
		if(q->FRONT == q->REAR)
		{
			q->FRONT = -1;
			q->REAR = -1;
		}
		else
			q->REAR -= 1;
		return X;	
	}
}

int delete_front_dq(struct queue *q)
{
	if(q->FRONT == -1)
		printf("Queue is empty!\n");
	else
	{
		int X = q->arr[q->FRONT];
		
		if(q->FRONT == q->REAR)
		{
			q->FRONT = -1;
			q->REAR = -1;
		}
		else
			q->FRONT += 1;
		return X;
	}
}

void insert_rear_cdq(struct queue *q)
{
	int X;
	
	if(q->FRONT == (q->REAR + 1) % q->SIZE)
		printf("Queue is full!\n");
		
	else if(q->FRONT == -1)
	{
		printf("Enter the number to be inserted\n"); 
		scanf("%d", &X);
		
		q->FRONT = 0;
		q->REAR = 0;
		q->arr[q->REAR] = X;
	}
	else
	{	
		printf("Enter the number to be inserted\n"); 
		scanf("%d", &X);
		
		q->REAR = (q->REAR+1) % q->SIZE;
		q->arr[q->REAR] = X;
	}
}

void insert_front_cdq(struct queue *q)
{
	int X;
	
	if(q->FRONT == (q->REAR + 1) % q->SIZE)
		printf("Queue is full!\n");
		
	else if(q->FRONT == -1)
	{
		printf("Enter the number to be inserted\n"); 
		scanf("%d", &X);
		
		q->FRONT = 0;
		q->REAR = 0;
		q->arr[q->FRONT] = X;
	}
	else
	{
		printf("Enter the number to be inserted\n"); 
		scanf("%d", &X);
		
		q->FRONT = (q->FRONT + q->SIZE-1) % q->SIZE;
		q->arr[q->FRONT] = X;
	}
}

void insert_rear_pq(struct queue *q)
{
	int X;
	int priority;
	
	if(q->FRONT == (q->REAR + 1) % q->SIZE)
		printf("Queue is full!\n");
		
	else if(q->FRONT == -1)
	{
		printf("Enter the number to be inserted\n"); 
		scanf("%d", &X);
		
		printf("Enter the index priority of the element (Most priority = 0)\n");			
		scanf("%d", &priority);
		
		q->FRONT = 0;
		q->REAR = 0;
		
		q->arr[q->REAR] = X;
		q->prioarr[q->REAR] = priority;
	}
	else
	{	
		printf("Enter the number to be inserted\n"); 
		scanf("%d", &X);
		
		printf("Enter the index priority of the element (Most priority = 0)\n");			
		scanf("%d", &priority);
		
		q->REAR = (q->REAR+1) % q->SIZE;
		
		q->arr[q->REAR] = X;
		q->prioarr[q->REAR] = priority;
	}
}	

void pq_sort(struct queue *q)
{
	if(q->FRONT == q->REAR)
	{
		//do nothing
	}	
	else if(q->FRONT < q->REAR)
		for(int i = (q->FRONT+1)%q->SIZE; i <= q->REAR; i++)
		{
			int j = i;
			
			while(j > q->FRONT && q->prioarr[j] < q->prioarr[j-1])
			{
				//swap prioarr
				q->prioarr[j] += q->prioarr[j-1];
				q->prioarr[j-1] = q->prioarr[j] - q->prioarr[j-1];
				q->prioarr[j] -= q->prioarr[j-1];
				
				//swap queue
				q->arr[j] += q->arr[j-1];
				q->arr[j-1] = q->arr[j] - q->arr[j-1];
				q->arr[j] -= q->arr[j-1];
				
				j--;
			}
		}
	else
		for(int i = (q->FRONT+1)%q->SIZE; ; i = ((i+1) % q->SIZE))
		{
			int j = i;
			
			while(q->prioarr[j] < q->prioarr[(j+q->SIZE-1) % q->SIZE])
			{
				//swap prioarr
				q->prioarr[j] += q->prioarr[(j+q->SIZE-1) % q->SIZE];
				q->prioarr[(j+q->SIZE-1) % q->SIZE] = q->prioarr[j] - q->prioarr[(j+q->SIZE-1) % q->SIZE];
				q->prioarr[j] -= q->prioarr[(j+q->SIZE-1) % q->SIZE];
				
				//swap queue
				q->arr[j] += q->arr[(j+q->SIZE-1) % q->SIZE];
				q->arr[(j+q->SIZE-1) % q->SIZE] = q->arr[j] - q->arr[(j+q->SIZE-1) % q->SIZE];
				q->arr[j] -= q->arr[(j+q->SIZE-1) % q->SIZE];
				
				j = (j+q->SIZE-1)%q->SIZE;
				
				if(j == q->FRONT)
					break;
			}
			
			if(i == q->REAR)
				break;
		}
}

int delete_rear_cdq(struct queue *q)
{
	if(q->REAR == -1)
		printf("Queue is empty!\n");
	else 
	{
		int X = q->arr[q->REAR];
		
		if(q->FRONT == q->REAR)
		{
			q->FRONT = -1;
			q->REAR = -1;
		}
		else
			q->REAR = (q->REAR + q->SIZE-1) % q->SIZE;
		return X;	
	}
}

int delete_front_cdq(struct queue *q)
{
	if(q->FRONT == -1)
		printf("Queue is empty!\n");
	else
	{
		int X = q->arr[q->FRONT];
		
		if(q->FRONT == q->REAR)
		{
			q->FRONT = -1;
			q->REAR = -1;
		}
		else
			q->FRONT = (q->FRONT+1) % q->SIZE;
		return X;
	}
}

void create(struct queue *q, int flag)
{
	printf("\nEnter size of queue\n");
	scanf("%d", &q->SIZE);
	
	if(flag == 7)
		q->prioarr = malloc(q->SIZE * sizeof(int));
		
	q->arr = malloc(q->SIZE * sizeof(int));
	
	q->FRONT = -1;
	q->REAR = -1;
}

void display(struct queue *q)
{
	printf("\nCurrent queue:\n");
	
	if(q->FRONT == -1)
		printf("\n");
	else
	{
		if(q->FRONT <= q->REAR)
			for(int i=q->FRONT; i <= q->REAR; i++)
				printf("%d\n", q->arr[i]);
		else
		{
			for(int i=q->FRONT; i < q->SIZE; i++)
				printf("%d\n", q->arr[i]);
			for(int i=0; i <= q->REAR; i++)
				printf("%d\n", q->arr[i]);
		}
	}
}

void main()
{
	int flag;
	struct queue q;
	
L:	
	printf("Which type of queue do you want to use ? \n(Enter the corresponding number)\n");
	
	printf("1.Simple Queue\n2.Circular Queue\n3.Double-ended Queue (Deque)\n4.Circular Deque\n5.Input-restricted Queue\n6.Output-restricted Queue\n7.Priority Queue\n");
	
	scanf("%d", &flag);
	
	create(&q, flag);
	
	switch(flag)
	{
		case 1 :
L1:
			printf("\nEnter the corresponding number for the given operations:\n");
			
			printf("\t1.ENQUEUE\n\t2.DEQUEUE\n\t3.DISPLAY Queue\n\t4.EXIT Program\n");
			
			scanf("%d", &flag);
			
			switch(flag)
			{
				case 1 :
					insert_rear_dq(&q);
					goto L1;
				case 2 :
					delete_front_dq(&q);
					goto L1;
				case 3 :
					display(&q);
					goto L1;
				case 4 :	
					exit(0);
				default :
					printf("Enter valid number!\n");
					goto L1;
			}
			
		case 2 :
L2:
			printf("\nEnter the corresponding number for the given operations:\n");
			
			printf("\t1.ENQUEUE\n\t2.DEQUEUE\n\t3.DISPLAY Queue\n\t4.EXIT Program\n");
			
			scanf("%d", &flag);
			
			switch(flag)
			{
				case 1 :
					insert_rear_cdq(&q);
					goto L2;
				case 2 :
					delete_front_cdq(&q);
					goto L2;
				case 3 :
					display(&q);
					goto L2;
				case 4 :	
					exit(0);
				default :
					printf("Enter valid number!\n");
					goto L2;
			}
			
		case 3 :
L3:
			printf("\nEnter the corresponding number for the given operations:\n");
			
			printf("\t1.INSERT at FRONT\n\t2.INSERT at REAR\n\t3.DELETE from FRONT\n\t4.DELETE from REAR\n\t5.DISPLAY Queue\n\t6.EXIT Program\n");
			
			scanf("%d", &flag);
	
			switch(flag)
			{
				case 1 :
					insert_front_dq(&q);
					goto L3;
				case 2 :
					insert_rear_dq(&q);
					goto L3;
				case 3 :
					delete_front_dq(&q);
					goto L3;
				case 4 :
					delete_rear_dq(&q);
					goto L3;
				case 5 : 
					display(&q);
					goto L3;
				case 6 :	
					exit(0);
				default :
					printf("Enter valid number!\n");
					goto L3;
			}
		
		case 4 :
L4:
			printf("\nEnter the corresponding number for the given operations:\n");
			
			printf("\t1.INSERT at FRONT\n\t2.INSERT at REAR\n\t3.DELETE from FRONT\n\t4.DELETE from REAR\n\t5.DISPLAY Queue\n\t6.EXIT Program\n");
			
			scanf("%d", &flag);
	
			switch(flag)
			{
				case 1 :
					insert_front_cdq(&q);
					goto L4;
				case 2 :
					insert_rear_cdq(&q);
					goto L4;
				case 3 :
					delete_front_cdq(&q);
					goto L4;
				case 4 :
					delete_rear_cdq(&q);
					goto L4;
				case 5 : 
					display(&q);
					goto L4;
				case 6 :	
					exit(0);
				default :
					printf("Enter valid number!\n");
					goto L4;
			}
			
		case 5 : 
L5:
			printf("\nEnter the corresponding number for the given operations:\n");
			
			printf("\t1.INSERT at REAR\n\t2.DELETE from FRONT\n\t3.DELETE from REAR\n\t4.DISPLAY Queue\n\t5.EXIT Program\n");
			
			scanf("%d", &flag);
	
			switch(flag)
			{
				case 1 :
					insert_rear_cdq(&q);
					goto L5;
				case 2 :
					delete_front_cdq(&q);
					goto L5;
				case 3 :
					delete_rear_cdq(&q);
					goto L5;
				case 4 : 
					display(&q);
					goto L5;
				case 5 :	
					exit(0);
				default :
					printf("Enter valid number!\n");
					goto L5;
			}	
			
		case 6 : 
L6:
			printf("\nEnter the corresponding number for the given operations:\n");
			
			printf("\t1.INSERT at FRONT\n\t2.INSERT at REAR\n\t3.DELETE from FRONT\n\t4.DISPLAY Queue\n\t5.EXIT Program\n");
			
			scanf("%d", &flag);
	
			switch(flag)
			{
				case 1 :
					insert_front_cdq(&q);
					goto L6;
				case 2 :
					insert_rear_cdq(&q);
					goto L6;
				case 3 :
					delete_front_cdq(&q);
					goto L6;
				case 4 : 
					display(&q);
					goto L6;
				case 5 :	
					exit(0);
				default :
					printf("Enter valid number!\n");
					goto L6;
			}
		case 7 :
L7:
			printf("\nEnter the corresponding number for the given operations:\n");
			
			printf("\t1.ENQUEUE\n\t2.DEQUEUE\n\t3.DISPLAY Queue\n\t4.EXIT Program\n");
			
			scanf("%d", &flag);
			
			switch(flag)
			{
				case 1 :
					insert_rear_pq(&q);
					pq_sort(&q);	
					goto L7;
				case 2 :
					delete_front_cdq(&q);
					goto L7;
				case 3 :
					display(&q);
					goto L7;
				case 4 :	
					exit(0);
				default :
					printf("Enter valid number!\n");
					goto L7;
			}
			
		default :
			printf("Enter valid number!");
			goto L;	
	}
}
