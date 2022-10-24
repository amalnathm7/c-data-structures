#include<stdio.h>
#include<stdlib.h>

struct node
{
	int DATA;
	struct node* RC;
	struct node* LC;
};

void buildTree(struct node* ptr)
{
	if(ptr != NULL)
	{
		printf("Enter data\n");
		scanf("%d", &ptr->DATA);
		
		char c;
		printf("Does %d have a left child ? (Y/N)\n", ptr->DATA);
L1:
		scanf("\n%c", &c);
		
		if(c == 'y' || c == 'Y')
		{
			ptr->LC = (struct node*) malloc(sizeof(struct node));
			buildTree(ptr->LC);
		}
		else if(c == 'n' || c == 'N')
		{
			ptr->LC = NULL;
		}
		else
		{
			printf("Enter Y/N\n");
			goto L1;
		}
		
		printf("Does %d have a right child ? (Y/N)\n", ptr->DATA);
L2:
		scanf("\n%c", &c);
		
		if(c == 'y' || c == 'Y')
		{
			ptr->RC = (struct node*) malloc(sizeof(struct node)); 
			buildTree(ptr->RC);
		}
		else if(c == 'n' || c == 'N')
		{
			ptr->RC = NULL;
		}
		else
		{
			printf("Enter Y/N!\n");
			goto L2;
		}
	}
}

void preOrder(struct node* ptr)
{
	if(ptr == NULL)
		printf(" Tree is empty!");
	else
	{
		printf(" %d", ptr->DATA);
		if(ptr->LC != NULL)
			preOrder(ptr->LC);
		if(ptr->RC != NULL)
			preOrder(ptr->RC);
	}
}

void inOrder(struct node* ptr)
{
	if(ptr == NULL)
		printf(" Tree is empty!");
	else
	{
		if(ptr->LC != NULL)
			inOrder(ptr->LC);
		printf(" %d", ptr->DATA);
		if(ptr->RC != NULL)
			inOrder(ptr->RC);
	}
}

void postOrder(struct node* ptr)
{
	if(ptr == NULL)
		printf(" Tree is empty!");
	else
	{
		if(ptr->LC != NULL)
			postOrder(ptr->LC);
		if(ptr->RC != NULL)
			postOrder(ptr->RC);
		printf(" %d", ptr->DATA);
	}
}

struct node* searchParent(struct node* ptr, int KEY, struct node* parent)
{
	if(ptr->DATA != KEY)
	{
		if(ptr->LC != NULL)
		{
			parent = searchParent(ptr->LC, KEY, ptr);
			if(parent != NULL)
				return parent;
		}
		if(ptr->RC != NULL)
		{
			parent = searchParent(ptr->RC, KEY, ptr);
			if(parent != NULL)
				return parent;
		}
		return NULL;
	}
	else
		return parent;
}

void insertTree(struct node* ptr, int KEY)
{	
	if(ptr == NULL)
		printf("\n%d not found!\n", KEY);
	else
	{
		if(ptr->LC == NULL || ptr->RC == NULL)
		{
			char c;
			printf("\nDo you want to insert as left child or right child of %d ? (L/R)\n", ptr->DATA);
L3:					
			scanf("\n%c", &c);
		
			if(c == 'l' || c == 'L')
			{
				if(ptr->LC == NULL)
				{
					ptr->LC = (struct node*) malloc(sizeof(struct node));
					ptr->LC->LC = NULL;
					ptr->LC->RC = NULL;
					printf("\nEnter data\n");
					scanf("%d", &ptr->LC->DATA);
					printf("\n%d inserted successfully!\n", ptr->LC->DATA);
				}
				else
					printf("\n%d has a left child already!\n", KEY);
			}
			else if(c == 'r' || c == 'R')
			{
				if(ptr->RC == NULL)
				{
					ptr->RC = (struct node*) malloc(sizeof(struct node));
					ptr->RC->LC = NULL;
					ptr->RC->RC = NULL;
					printf("\nEnter data\n");
					scanf("%d", &ptr->RC->DATA);
					printf("\n%d inserted successfully!\n", ptr->RC->DATA);
				}
				else
					printf("\n%d has a right child already!\n", KEY);
			}
			else
			{
				printf("\nEnter L/R!\n");
				goto L3;
			}
		}
		else
			printf("\n%d has both left and right children!\n", KEY);
	}
}

void deleteTree(struct node* parent, int KEY)
{	
	if(parent == NULL)
		printf("\n%d not found!\n", KEY);
	else
	{
		if(parent->LC != NULL && parent->LC->DATA == KEY)
			if(parent->LC->LC == NULL && parent->LC->RC == NULL)
			{
				free(parent->LC);
				parent->LC = NULL;
				printf("\n%d deleted successfully!\n", KEY);
			}
			else
				printf("\n%d is not a leaf node!\n", KEY);
		else
			if(parent->RC->LC == NULL && parent->RC->RC == NULL)
			{
				free(parent->RC);
				parent->RC = NULL;
				printf("\n%d deleted successfully!\n", KEY);
			}
			else
				printf("\n%d is not a leaf node!\n", KEY);
	}
}

struct node* searchLink(struct node* ptr, int KEY)
{
	struct node* ptr1;

	if(ptr->DATA != KEY)
	{
		if(ptr->LC != NULL)
		{
			ptr1 = searchLink(ptr->LC, KEY);
			if(ptr1 != NULL)
				return ptr1; 
		}
		if(ptr->RC != NULL)
		{
			ptr1 = searchLink(ptr->RC, KEY);
			if(ptr1 != NULL)
				return ptr1;
		}
		return NULL;
	}
	else
		return ptr;
}

void main()
{
	struct node* ROOT = (struct node*) malloc(sizeof(struct node));
	
	int n;
	
	printf("Build your tree\n\n");
	buildTree(ROOT);
L:
	printf("\nChoose the operation\n\n");
	printf("1. Insert a node\n");
	printf("2. Delete a node\n");
	printf("3. Inorder traversal\n");
	printf("4. Preorder traversal\n");
	printf("5. Postorder traversal\n");
	printf("6. Exit\n");
	
	scanf("%d", &n);
	switch(n)
	{
		case 1:
			if(ROOT == NULL)
			{
				ROOT = (struct node*) malloc(sizeof(struct node));
				ROOT->LC = NULL;
				ROOT->RC = NULL;
				printf("\nEnter data\n");
				scanf("%d", &ROOT->DATA);
				printf("\n%d inserted successfully!\n", ROOT->DATA);
			}
			else
			{
				printf("\nEnter the KEY data\n");
				scanf("%d", &n);
				insertTree(searchLink(ROOT, n), n);
			}
			goto L;
		case 2:
			if(ROOT == NULL)
				printf("\nTree is empty!\n");
			else
			{
				printf("\nEnter the data to be deleted\n");
				scanf("%d", &n);
				if(n == ROOT->DATA)
				{
					if(ROOT->LC == NULL && ROOT->RC == NULL)
					{
						free(ROOT);
						ROOT = NULL;
						printf("\n%d deleted successfully!\n", n);
					}
					else
						printf("\n%d is not a leaf node!\n", n);
				}
				else
					deleteTree(searchParent(ROOT, n, ROOT), n);
			}
			goto L;
		case 3:
			printf("\nInorder :");
			inOrder(ROOT);
			printf("\n");
			goto L;
		case 4:
			printf("\nPreorder :");
			preOrder(ROOT);
			printf("\n");
			goto L;
		case 5:
			printf("\nPostorder :");
			postOrder(ROOT);
			printf("\n");
			goto L;
		case 6:
			exit(0);
		default:
			printf("Invalid entry!\n");
			goto L;
		}
}
