#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
	int NUM;
	char* NAME;
	float MARK;
	struct node* LINK;
};

void insertList(struct node* HEADER)
{	
	struct node* ptr = HEADER->LINK;
	
	HEADER->LINK = malloc(1*sizeof(struct node));
	
	printf("\nEnter student name\n");
	scanf("\n");
	HEADER->LINK->NAME = malloc(20*sizeof(char));
	fgets(HEADER->LINK->NAME, 20, stdin);
	HEADER->LINK->NAME[strlen(HEADER->LINK->NAME)-1] = '\0';
	
	printf("Enter student roll no.\n");
	scanf("%d", &HEADER->LINK->NUM);
	
	printf("Enter student total-marks\n");
	scanf("%f", &HEADER->LINK->MARK);
	
	HEADER->LINK->LINK = ptr;
}

int deleteList(struct node* ptr)
{
	if(ptr->LINK == NULL)
	{
		printf("\nList is empty!\n");
		return 0;
	}
	
	int KEY;
	
	printf("\nEnter the student roll no. to be deleted\n");
	scanf("%d", &KEY);
	
	while(ptr->LINK != NULL)
	{
		if(ptr->LINK->NUM == KEY)
		{
			struct node* ptr1 = ptr->LINK->LINK;
			printf("\n%s's details has been deleted\n", ptr->LINK->NAME);
			free(ptr->LINK);
			ptr->LINK = ptr1;
			return 1;
		}
		else
			ptr = ptr->LINK;
	}
	
	if(ptr->LINK == NULL)
		printf("\nStudent not found!\n");
}

int searchList(struct node* ptr)
{
	if(ptr->LINK == NULL)
	{
		printf("\nList is empty!\n");
		return 0;
	}
	
	int KEY;
	
	printf("\nEnter the student roll no. to be searched\n");
	scanf("%d", &KEY);
	
	while(ptr->LINK != NULL)
	{
		if(ptr->LINK->NUM == KEY)
		{
			printf("\nStudent found!\nName = %s\n", ptr->LINK->NAME);
			printf("Roll No. = %d\n",ptr->LINK->NUM);
			printf("Total Marks = %0.2f\n",ptr->LINK->MARK);
			return 1;
		}
		else
			ptr = ptr->LINK;
	}
	
	if(ptr->LINK == NULL)
		printf("\nStudent not found!\n");
}

int sortList(struct node* ptr)
{
	if(ptr == NULL)
	{
		printf("\nList is empty!\n");
		return 0;
	}
	else if(ptr->LINK == NULL)
	{
		printf("\nList is sorted successfully!\n");
		return 1;
	}
	
	while(ptr->LINK != NULL)
	{
		int min = ptr->NUM;
		struct node* ptr1 = ptr->LINK;
		struct node* minNode = ptr;

		while(ptr1 != NULL)
		{
			if(ptr1->NUM < min)
			{
				min = ptr1->NUM;
				minNode = ptr1; 
			}
			ptr1 = ptr1->LINK;
		}

		int num = minNode->NUM;
		minNode->NUM = ptr->NUM;
		ptr->NUM = num; 
		
		char* name = minNode->NAME;
		minNode->NAME = ptr->NAME;
		ptr->NAME = name;
		
		float mark = minNode->MARK;
		minNode->MARK = ptr->MARK;
		ptr->MARK = mark;
		
		ptr = ptr->LINK;
	}
	printf("\nList is sorted successfully!\n");
}

int display(struct node* ptr)
{
	if(ptr == NULL)
	{
		printf("\nList is empty!\n");
		return 0;
	}
	
	int i=1;
	
	while(ptr!=NULL)
	{
		printf("\nStudent %d Details:\nName = %s\n", i, ptr->NAME);
		printf("Roll No. = %d\n",ptr->NUM);
		printf("Total Marks = %0.2f\n",ptr->MARK);
		ptr=ptr->LINK;
		i++;
	}
}

void main()
{
	struct node* HEADER = (struct node*) malloc(1*sizeof(struct node));
	HEADER->LINK = NULL;
	
	int flag;
L:	
	printf("\nChoose the option:\n");
	printf("1.INSERT\n2.DELETE\n3.SEARCH\n4.SORT\n5.DISPLAY\n6.EXIT\n");
	scanf("%d", &flag);
	
	switch(flag)
	{
		case 1:
			insertList(HEADER);
			goto L;
		case 2:
			deleteList(HEADER);
			goto L;
		case 3:
			searchList(HEADER);
			goto L;
		case 4:
			sortList(HEADER->LINK);
			goto L;
		case 5:
			display(HEADER->LINK);
			goto L;
		case 6:
			printf("\nEXIT.\n");
			exit(0);
		default:
			printf("INVALID INPUT!\n");
			goto L;
	}
}
