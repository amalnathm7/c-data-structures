//START
//1. Declare n, arr[SIZE], temp, i, j, count
//2. Read n
//3. i=0 till n, read arr[i]
//4. i=0, count=0, flag=0
//5. If i<n-1, goto 6. Else, goto 10.
//6. j=0 
//7. If j<n-i-1, increment flag and goto 8. Else, goto 9.
//8. If arr[j]>arr[j+1], swap these elements using temp, increment count and j and goto 7. Else, increment j and goto 7.
//9. If flag is equal to 0, goto 10. Else, increment i and goto 5.
//10. i=0 till n, print arr[i]
//11. Print count and flag
//STOP

#include<stdio.h>
void main()
{
	int i,n,a[100],temp,count=0,flag=0;
	
	printf("Enter the no. of integers\n");
	scanf("%d",&n);
	
	printf("Enter the array elements\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
		
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				count++;
			}
			flag++;
		}
		
		if(count==0)
			break;
	}
	
	printf("The elements in ascending order are\n");
	for(i=0;i<n;i++)
		printf("%d\n",a[i]);
	printf("\nNo. of swaps = %d\nNo. of iterations = %d\n", count,flag);
}



