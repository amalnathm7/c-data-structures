#include <stdio.h>
#include <stdlib.h>

struct sparse 
{
	int row, col;
	int arr[10][10];
	int tuple[100][3];
};


void readArray(struct sparse *sp, int i)
{
	printf("Enter no. of rows and columns of matrix %d\n", i);
	scanf("%d%d", &sp->row, &sp->col);	
	
	printf("Enter the matrix %d elements\n", i);
	for(int i=0;i<sp->row;i++)
		for(int j=0;j<sp->col;j++)
			scanf("%d", &sp->arr[i][j]);
}

void dispArray(struct sparse *sp, int i)
{
	printf("Matrix %d:\n", i);
	
	for(int i=0;i<sp->row;i++)
	{
		for(int j=0;j<sp->col;j++)
			printf("%d ", sp->arr[i][j]);
		printf("\n");
	}
}

	
void dispTuple(struct sparse *sp, int i)
{
	printf("Tuple representation of Sparse Matrix %d:\n",i);
	for(int i=0;i<=sp->tuple[0][2];i++)
	{
		for(int j=0;j<3;j++)
			printf("%d ", sp->tuple[i][j]);
		printf("\n");
	}
}


void makeTuple(struct sparse *sp)
{
	int k=0;
	sp->tuple[0][0] = sp->row;
	sp->tuple[0][1] = sp->col;
	
	for(int i=0;i<sp->row;i++)
		for(int j=0;j<sp->col;j++)
			if(sp->arr[i][j] != 0)
			{
				k++;
				sp->tuple[k][0] = i;
				sp->tuple[k][1] = j;
				sp->tuple[k][2] = sp->arr[i][j];
			}
	sp->tuple[0][2] = k;
}


void makeArray(struct sparse *sp)
{
	sp->row = sp->tuple[0][0];
	sp->col = sp->tuple[0][1];
	
	for(int i=0; i<sp->row;i++)
		for(int j=0;j<sp->col;j++)
			sp->arr[i][j] = 0;
	
	for(int i=1;i<=sp->tuple[0][2];i++)
			sp->arr[sp->tuple[i][0]][sp->tuple[i][1]] = sp->tuple[i][2];
}	


void transTuple(struct sparse *sp1, struct sparse *sp2, int a)
{
	
	if(sp1->tuple[0][2] == 0)
		printf("Matrix %d cannot be transposed!\n", a);
	else
	{
		sp2->tuple[0][0] = sp1->tuple[0][1];
		sp2->tuple[0][1] = sp1->tuple[0][0];
		sp2->tuple[0][2] = sp1->tuple[0][2];
		
		
		int k=1;
		
		for(int i=0;i<sp1->tuple[0][1];i++)
			for(int j=1;j<=sp1->tuple[0][2];j++)
				if(i == sp1->tuple[j][1])
				{
					sp2->tuple[k][0] = sp1->tuple[j][1];
					sp2->tuple[k][1] = sp1->tuple[j][0];
					sp2->tuple[k][2] = sp1->tuple[j][2];
					k++;
				}
		printf("Transpose of\n"); 
		dispTuple(sp2, a);
	}
}

void addTuple(struct sparse *sp1, struct sparse *sp2, struct sparse *sp3, int a, int b)
{
	int i=1, j=1, k=1; 
	
	if(sp1->tuple[0][0] != sp2->tuple[0][0] || sp1->tuple[0][1] != sp2->tuple[0][1])
		printf("Matrix %d and Matrix %d cannot be added!\n", a, b);
		
	else
	{
		while(i<=sp1->tuple[0][2] || j<=sp2->tuple[0][2])
		{
			if(i>sp1->tuple[0][2])
			{	
				sp3->tuple[k][0] = sp2->tuple[j][0];
				sp3->tuple[k][1] = sp2->tuple[j][1];
				sp3->tuple[k][2] = sp2->tuple[j][2];
				k++, j++;
			}
			else if(j>sp2->tuple[0][2])
			{
				sp3->tuple[k][0] = sp1->tuple[i][0];
				sp3->tuple[k][1] = sp1->tuple[i][1];
				sp3->tuple[k][2] = sp1->tuple[i][2];
				k++, i++;
			}
			else if(sp1->tuple[i][0] == sp2->tuple[j][0])
			{
				if(sp1->tuple[i][1] == sp2->tuple[j][1])
				{
					sp3->tuple[k][2] = sp1->tuple[i][2] + sp2->tuple[j][2];
					sp3->tuple[k][1] = sp1->tuple[i][1];
					sp3->tuple[k][0] = sp1->tuple[i][0];
					k++, i++, j++;
				}
				else if(sp1->tuple[i][1] < sp2->tuple[j][1])
				{
					sp3->tuple[k][0] = sp1->tuple[i][0];
					sp3->tuple[k][1] = sp1->tuple[i][1];
					sp3->tuple[k][2] = sp1->tuple[i][2];
					k++, i++;
				}
				else
				{
					sp3->tuple[k][0] = sp2->tuple[j][0];
					sp3->tuple[k][1] = sp2->tuple[j][1];
					sp3->tuple[k][2] = sp2->tuple[j][2];
					k++, j++;
				}
			}
			
			else if(sp1->tuple[i][0] < sp2->tuple[j][0])
			{
				sp3->tuple[k][0] = sp1->tuple[i][0];
				sp3->tuple[k][1] = sp1->tuple[i][1];
				sp3->tuple[k][2] = sp1->tuple[i][2];
				k++, i++;
			}
			else
			{
				sp3->tuple[k][0] = sp2->tuple[j][0];
				sp3->tuple[k][1] = sp2->tuple[j][1];
				sp3->tuple[k][2] = sp2->tuple[j][2];
				k++, j++;
			}  	
		}
		sp3->tuple[0][0] = sp1->tuple[0][0];
		sp3->tuple[0][1] = sp1->tuple[0][1];
		sp3->tuple[0][2] = k-1;
		
		printf("Sum of Matrix %d and %d:\n", a, b);
		dispTuple(sp3, 3);
	}		
}


void main()
{
	struct sparse sp1, sp2, transp1, transp2, sumsp3;	
	
	readArray(&sp1, 1);
	readArray(&sp2, 2);
	
	makeTuple(&sp1);
	makeTuple(&sp2);
	
	dispTuple(&sp1, 1);
	dispTuple(&sp2, 2);
	
	transTuple(&sp1, &transp1, 1);
	transTuple(&sp2, &transp2, 2);
	
	addTuple(&sp1, &sp2, &sumsp3, 1, 2);
}	
	



