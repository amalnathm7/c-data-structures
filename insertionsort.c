//START
//1.Declare n, temp, flag, count, arr[SIZE]
//2.Read n
//3.i=0 till n, read arr[i]
//4.flag=0, count=0, i=1
//5.If i<=n-1, goto 6. Else, goto 10.
//6.Assign j=i
//7.If j>0 and arr[j-1]>arr[j](increment count during each comparison), goto 8. Else, increment i and goto 5.
//8.Swap arr[j-1] and arr[j] using temp. 
//9.Increment flag, decrement j and goto 7.
//10.i=0 till n, print arr[i]
//11.Print count and flag
//STOP

#include <stdio.h>

void main()

{

    int n, i, j, temp, flag = 0, count=0;
    int arr[50];

    printf("Enter number of elements\n");
    scanf("%d", &n);

    printf("Enter %d integers\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for (i = 1 ; i <= n - 1; i++)
    {
	    j = i;
	    
            while ( j > 0 && count++ >= 0 && arr[j-1] > arr[j] )
            {	        
                temp     = arr[j];
                arr[j]   = arr[j-1];
                arr[j-1] = temp;
                j--;
                flag++;
            }
            
    }

    printf("Sorted list in ascending order:\n");

    for (i = 0; i < n ; i++)
        printf("%d\n", arr[i]);
    
    printf("Number of comparisons = %d\nNo. of swaps = %d\n", count, flag);    
}
