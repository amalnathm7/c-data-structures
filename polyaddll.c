#include<stdio.h>
#include<stdlib.h>

struct node
{
	int COEFF;
	int EXPO;
	struct node* LINK;
};

void insertList(struct node* HEADER, int coeff, int expo)
{
	struct node* ptr = HEADER->LINK;
	
	HEADER->LINK = malloc(1*sizeof(struct node));
	
	HEADER->LINK->COEFF = coeff;
	HEADER->LINK->EXPO = expo;
	HEADER->LINK->LINK = ptr;
}

void display(struct node* ptr)
{
	if(ptr == NULL)
	{
		printf("0 ");
	}
	while(ptr != NULL)
	{
		printf("%dx^%d ", ptr->COEFF, ptr->EXPO);
		ptr = ptr->LINK;
	}
	printf(")");
}

void addList(struct node* ptr1, struct node* ptr2, struct node* ptr3)
{
	while(ptr1 != NULL && ptr2 != NULL)
	{
		if(ptr1->EXPO == ptr2->EXPO)
		{
			if(ptr1->COEFF + ptr2->COEFF != 0)
			{
				ptr3->LINK = malloc(1*sizeof(struct node));
				ptr3->LINK->EXPO = ptr1->EXPO;
				ptr3->LINK->COEFF = ptr1->COEFF + ptr2->COEFF;
				ptr3->LINK->LINK = NULL;
				ptr3 = ptr3->LINK;
			}
			ptr1 = ptr1->LINK;
			ptr2 = ptr2->LINK;
		}
		else if(ptr1->EXPO < ptr2->EXPO)
		{
			ptr3->LINK = malloc(1*sizeof(struct node));
			ptr3->LINK->EXPO = ptr1->EXPO;
			ptr3->LINK->COEFF = ptr1->COEFF;
			ptr3->LINK->LINK = NULL;
			ptr1 = ptr1->LINK;
			ptr3 = ptr3->LINK;
		}
		else
		{
			ptr3->LINK = malloc(1*sizeof(struct node));
			ptr3->LINK->EXPO = ptr2->EXPO;
			ptr3->LINK->COEFF = ptr2->COEFF;
			ptr3->LINK->LINK = NULL;
			ptr2 = ptr2->LINK;
			ptr3 = ptr3->LINK;
		}
	}
	if(ptr1 != NULL && ptr2 == NULL)
	{
		while(ptr1 != NULL)
		{
			ptr3->LINK = malloc(1*sizeof(struct node));
			ptr3->LINK->EXPO = ptr1->EXPO;
			ptr3->LINK->COEFF = ptr1->COEFF;
			ptr3->LINK->LINK = NULL;
			ptr1 = ptr1->LINK;
			ptr3 = ptr3->LINK;
		}
	}
	else if(ptr1 == NULL && ptr2 != NULL)
	{
		while(ptr2 != NULL)
		{
			ptr3->LINK = malloc(1*sizeof(struct node));
			ptr3->LINK->EXPO = ptr2->EXPO;
			ptr3->LINK->COEFF = ptr2->COEFF;
			ptr3->LINK->LINK = NULL;
			ptr2 = ptr2->LINK;
			ptr3 = ptr3->LINK;
		}
	}
}

void productList(struct node* ptr1, struct node* HEADER2, struct node* HEADER4)
{
	while(ptr1 != NULL)
	{
		struct node* ptr2 = HEADER2;

		while(ptr2 != NULL)
		{	
			int C = ptr1->COEFF * ptr2->COEFF;
			int E = ptr1->EXPO + ptr2->EXPO;

			struct node* ptr = malloc(1*sizeof(struct node*));
			struct node* ptr3 = HEADER4;
			
			while(ptr3->LINK != NULL)
			{
				if(ptr3->LINK->EXPO == E)
				{
					ptr3->LINK->COEFF += C;
					break;
				}
				else if(ptr3->LINK->EXPO > E)
				{
					ptr->EXPO = E;
					ptr->COEFF = C;
					ptr->LINK = ptr3->LINK;
					ptr3->LINK = ptr;
					break;
				}
				ptr3 = ptr3->LINK;
			}
			
			if(ptr3->LINK == NULL)
			{
				ptr3->LINK = ptr;
				ptr->COEFF = C;
				ptr->EXPO = E;
				ptr->LINK = NULL;
			}
			
			ptr2 = ptr2->LINK;
		}
			
		ptr1 = ptr1->LINK;
	}
}

int sortList(struct node* ptr)
{
	if(ptr == NULL)
	{
		return 0;
	}
	else if(ptr->LINK == NULL)
	{
		return 1;
	}
	
	while(ptr->LINK != NULL)
	{
		int min = ptr->EXPO;
		struct node* ptr1 = ptr->LINK;
		struct node* minNode = ptr;

		while(ptr1 != NULL)
		{
			if(ptr1->EXPO < min)
			{
				min = ptr1->EXPO;
				minNode = ptr1; 
			}
			ptr1 = ptr1->LINK;
		}

		int temp = minNode->EXPO;
		minNode->EXPO = ptr->EXPO;
		ptr->EXPO = temp; 

		temp = minNode->COEFF;
		minNode->COEFF = ptr->COEFF;
		ptr->COEFF = temp;
		
		ptr = ptr->LINK;
	}
}

void main()
{
	int x, coeff, expo;
	struct node* HEADER1 = malloc(1*sizeof(struct node));
	struct node* HEADER2 = malloc(1*sizeof(struct node));
	struct node* HEADER3 = malloc(1*sizeof(struct node));
	struct node* HEADER4 = malloc(1*sizeof(struct node));
	HEADER1->LINK = NULL;
	HEADER2->LINK = NULL;
	HEADER3->LINK = NULL;
	HEADER4->LINK = NULL;
	
	printf("Enter the no. of terms in the first polynomial\n");
	scanf("%d", &x);
	printf("\nEnter the coefficient and then exponent of each terms respectively in the first polynomial\n");
	
	for(int i=0; i<x; i++)
	{
		scanf("%d", &coeff);
		scanf("%d", &expo);
		if(coeff != 0)
			insertList(HEADER1, coeff, expo);
	}
	
	printf("\nEnter the no. of terms in the second polynomial\n");
	scanf("%d", &x);
	printf("\nEnter the coefficient and then exponent of each terms respectively in the second polynomial\n");
	
	for(int i=0; i<x; i++)
	{
		scanf("%d", &coeff);
		scanf("%d", &expo);
		if(coeff != 0)
			insertList(HEADER2, coeff, expo);
	}
	
	sortList(HEADER1->LINK);
	sortList(HEADER2->LINK);
	
	addList(HEADER1->LINK, HEADER2->LINK, HEADER3);
	productList(HEADER1->LINK, HEADER2->LINK, HEADER4);
	
	printf("\nSUM :\n( ");
	display(HEADER1->LINK);
	printf(" +\n( ");
	display(HEADER2->LINK);
	printf(" =\n( ");
	display(HEADER3->LINK);
	printf("\n");

	printf("\nPRODUCT :\n( ");
	display(HEADER1->LINK);
	printf(" *\n( ");
	display(HEADER2->LINK);
	printf(" =\n( ");
	display(HEADER4->LINK);
	printf("\n");
}
