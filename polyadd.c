#include<stdio.h>
#include<stdlib.h>

struct poly
{
	int coeff[20];
	int exp[20];
};

void main()
{
	struct poly p1, p2, p3;	
	int t1, t2, i=0, j=0, k=0;

	printf("Enter the no. of terms in first polynomial\n");
	scanf("%d", &t1);

	printf("Enter the no. of terms in second polynomial\n");
	scanf("%d", &t2);

	printf("Enter the first polynomial (Eg:- ax^2 + b^x + c) in the decreasing order of the powers of the terms \nand in such a way that the coefficient of the first term (Here,a) is entered first \nand then the power of the variable in the same term (Here,2)\n");

	for(i=0;i<t1;i++)
	{
		scanf("%d", &p1.coeff[i]);
		scanf("%d", &p1.exp[i]);
	}
	
	printf("Enter the second polynomial as mentioned above\n");

	for(j=0;j<t2;j++)
	{
		scanf("%d", &p2.coeff[j]);
		scanf("%d", &p2.exp[j]);
	}
	
	i=0, j=0;
	
	while (i<t1 || j<t2)
	{
		if (i>=t1)
		{
			p3.exp[k] = p2.exp[j];
			p3.coeff[k] = p2.coeff[j];
			j++, k++;
		}
		
		else if (j>=t2)
		{
			p3.exp[k] = p1.exp[i];
			p3.coeff[k] = p1.coeff[i];
			i++, k++;
		}	
		else if (p1.exp[i] == p2.exp[j])
		{
			p3.coeff[k] = p1.coeff[i] + p2.coeff[j];
			p3.exp[k] = p1.exp[i];
			i++, j++, k++;
		}
		
		else if (p1.exp[i] > p2.exp[j])
 		{
			p3.exp[k] = p1.exp[i];
			p3.coeff[k] = p1.coeff[i];
			i++, k++;
		}
		
		else
		{
			p3.exp[k] = p2.exp[j];
			p3.coeff[k] = p2.coeff[j];
			j++, k++;
		}
	}
	
	printf("The sum of\n");
	
	for(i=0;i<t1;i++)
	{
		printf("(%dx^%d) ", p1.coeff[i], p1.exp[i]);
	}
	
	printf("and\n");
	
	for(j=0;j<t2;j++)
	{
		printf("(%dx^%d) ", p2.coeff[j], p2.exp[j]);
	}
	
	printf("is\n");
	
	for(i=0;i<k;i++)
	{
		printf("(%dx^%d) ", p3.coeff[i], p3.exp[i]);
	}
	
	printf("\n");
}



