//START
//1. Declare n, arr[SIZE], num, count=0, flag=0
//2. Read n
//3. From i=0 till n, read arr[i]
//4. Read the search element num
//5. From i=0 till n, in each iteration, increment count and check if arr[i] is equal to num. 
//6. If true, increment flag and break from the loop. Else, continue the next iteration.
//7. If flag is not equal to 0, print num found. Else, print num not found.
//8. Print count
//STOP

#include<stdio.h>
void main()
{
	int n, arr[100], num, count=0, flag=0;

	printf("Enter the array size\n");
	scanf("%d", &n);

	printf("Enter the array elements\n");
	for(int i=0;i<n;i++)
		scanf("%d", &arr[i]);

	printf("Enter the number to be searched\n");
	scanf("%d", &num);

	for(int i=0;i<n;i++)
	{
		count++;
		if(arr[i]==num)
		{
			flag++;
			break;
		}
	}
	if(flag==0)
		printf("%d Not Found !\n", num);
	else
		printf("%d Found !\n", num);
	printf("\nNo. of comparisons = %d\n", count);
}

