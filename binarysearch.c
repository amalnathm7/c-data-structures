//START
//1. Declare n, arr[SIZE], num, r=0, flag=0, count=0
//2. Read n
//3. From i=0 till n, read arr[i]
//4. Read search element num
//5. If n greater than or equal to r(index of first element), goto 6. Else, goto 10.
//6. Assign mid=(n+r)/2
//7. If arr[mid] equal to num, increment count and flag, then break and goto 10. Else, goto 8.
//8. If arr[mid] less than num, assign r=mid+1, increment count and continue the next iteration by jumping to 5. Else, goto 9.
//9. If arr[mid] greater than num, assign n=mid-1, increment count and continue the next iteration by jumping to 5.
//10. If flag equal to zero, print num not found. Else, print num found.
//11. Print count
//STOP

#include <stdio.h>

void main()
{
	int n, mid, r=0, arr[100], num, flag=0, count=0;

	printf("Enter the array size\n");
	scanf("%d", &n);

	printf("Enter the array elements in ascending order\n");
	for(int i=0;i<n;i++)
		scanf("%d", &arr[i]);

	printf("Enter the number to be searched\n");
	scanf("%d", &num);

	while(n>=r)
	{
		mid=(n+r)/2;

		if(arr[mid]==num)
		{
			count++;
			flag++;
			break;
		}
		else if(arr[mid]<num)
		{
			r=mid+1;
			count++;
			continue;
		}
		else
		{
			n=mid-1;
			count++;
			continue;
		}
	}


	if(flag==0)
		printf("\n%d not found!\n", num);
	else
		printf("\n%d found!\n", num);

	printf("No. of comparisons = %d\n", count);
}

