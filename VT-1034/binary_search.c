#include <stdio.h>
int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid; 
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x); 
        return binarySearch(arr, mid + 1, r, x);
    }

    return -1;
}

int main(void)
{
/*    int arr[] = { 2, 3, 4, 10, 40 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;*/
	
int i, count,x,t;
printf("how many elements u want to enter?: ");
   scanf("%d",&count);
   int number[count];

   printf("Enter %d elements: ", count);
   for(i=0;i<count;i++)
      scanf("%d",&number[i]);
printf("enter the num to search\n");
scanf("%d",&x);

    int result = binarySearch(number, 0, count - 1, x);
    (result == -1) ? printf("Element is not present in array")
                   : printf("Element is present at index %d",
                            result);
    return 0;
}

