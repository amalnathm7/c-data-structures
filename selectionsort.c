//START
//1. Declare n, arr[SIZE], temp, i, j, count, flag, min
//2. Read n
//3. i=0 till n, read arr[i]
//4. i=0, count=0, flag=0
//5. If i<n-1, goto 6. Else, goto 10
//6. min=i, j=i+1
//7. If j<n, increment flag and goto 8. Else, goto 9
//8. If arr[j]>arr[j+1], assign min=j, increment j and goto 7. Else, increment j and goto 7.
//9. if min!=1, swap arr[min] and arr[i], increment count and i and goto 5.
//10. i=0 till n, print arr[i]
//11. Print count and flag
//STOP

#include<stdio.h>

void main()
{
	int n,arr[100],min,temp,count=0,flag=0;

	printf("Enter the no. of elements\n");
	scanf("%d",&n);

	printf("Enter array elements\n");
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	
	for(int i=0;i<n-1;i++)
	{
		min=i;

		for(int j=i+1;j<n;j++)
		{
			flag++;
			if(arr[j]<arr[min])
			{
				min=j;
			}
		}
		
		if(min!=i)
		{
			temp=arr[min];
			arr[min]=arr[i];
			arr[i]=temp;
			count++;
		}
	}

	printf("The sorted elements are\n");
	for(int i=0;i<n;i++)
		printf("%d\n",arr[i]);
	printf("\nNo. of swaps = %d\nNo. of iterations = %d\n", count,flag);
}


