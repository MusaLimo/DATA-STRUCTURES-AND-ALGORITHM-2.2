#include <stdio.h>
#include <stdlib.h>

void findDuplicate (int arr[],int n)
{
    int foundDuplicate=0;
    for(int i=0;i<n;i++)
    {
      for (int j=i+1;j<n;j++)
      {
        if (arr [i]== arr[j])
         {
          foundDuplicate=1;
          break;
         }
      }
    }
    if (foundDuplicate)
    {
        printf("\ntrue");
    }
    if (!foundDuplicate)
    {
        printf("\nfalse");
    }
}

int main()
{
    int arr[]={1,2,3,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);

    printf("Array; ");
    for(int i=0;i<n;i++)
    {
        printf("%d", arr[i]);
    }
    findDuplicate(arr,n);

}