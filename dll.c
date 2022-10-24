#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct node
{
	char DATA;
	struct node* LLINK;
	struct node* RLINK;
};

void display(struct node* ptr)
{
	while(ptr!=NULL)
	{
		printf("%c", ptr->DATA);
		ptr = ptr->RLINK;
	}
}

struct node* insertList(struct node* ptr, char X)
{
	while(ptr->RLINK != NULL)
	{
		ptr = ptr->RLINK;
	}
	
	ptr->RLINK = (struct node*) malloc(1*sizeof(struct node));
	
	ptr->RLINK->DATA = X;
	ptr->RLINK->RLINK = NULL;
	ptr->RLINK->LLINK = ptr;
	
	return ptr->RLINK;
}

int checkPalindrome(struct node* ptr)
{
	struct node* ptr1 = ptr->LLINK;
	ptr = ptr->RLINK;
	
	while(ptr != ptr1)
	{
		if(tolower(ptr->DATA) != tolower(ptr1->DATA))
			return 0;
		else if(ptr->RLINK == ptr1)
			return 1;
		ptr = ptr->RLINK;
		ptr1 = ptr1->LLINK;
	}

	return 1;
}

void main()
{
	struct node* HEADER = (struct node*) malloc(1*sizeof(struct node));
	HEADER->RLINK = NULL;
	HEADER->LLINK = NULL;

	char str[20];

	printf("Enter a string\n");
	fgets(str, 20, stdin);

	for(int i=0; i<strlen(str)-1; i++)
		HEADER->LLINK = insertList(HEADER, str[i]);	

	display(HEADER->RLINK);
	
	if(checkPalindrome(HEADER))
		printf(" is a Palindrome\n");
	else
		printf(" is not a Palindrome\n");
}
