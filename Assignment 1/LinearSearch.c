#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,k;
    printf("Enter the number of elements in the array:");
    scanf("%d",&n);
    int * A = (int *) malloc (n*sizeof(int));
    printf("Enter the elements of the array:");
    for(int i=0;i<n;i++)
    scanf("%d",(A+i));
    printf("Enter the element to be searched:");
    scanf("%d",&k);
    for(int i=0;i<n;i++)
    {
        if(*(A+i)==k)
        {
        printf("Element found at index %d",i+1);
        return 0;
        }
    }
    printf("Element not found ");
    return 0;

}