#include<stdio.h>
#include<stdlib.h>
void BinarySearch(int * A,int l , int u,int k)
{ if(l>u)
    {
    printf("Element not found!");      
    return;
    }
    int m=(l+u)/2;
    if(*(A+m)==k)
    {
    printf("Element found!");
    return;
    }
    else if(*(A+m)>k)
    return BinarySearch(A,l,m-1,k);
    else if(*(A+m)<k)
    return BinarySearch(A,m+1,u,k);   
}

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
    BinarySearch(A,0,n-1,k);
}