#include<stdio.h>
#include<stdlib.h>
int findpivot(int A[],int l,int h)
{
   int p =A[h];
   int i=l-1;
   for(int j=l;j<h;j++)
   {
    if(A[j]<=p)
    {i++;
        int t=A[j];
        A[j]=A[i];
        A[i]=t;
    }
   }
   int t=A[i+1];
   A[i+1]=A[h];
   A[h]=t;
   return i+1;
}
void partition(int A[],int l,int h)
{
    if(l>h)
    return;
    int p=findpivot(A,l,h);
    partition(A,l,p-1);
    partition(A,p+1,h);     


}

int main()
{
    int n;
    printf("Enter length of array: ");
    scanf("%d",&n);
    int * A= (int *) malloc(n*sizeof(int));
    printf("\nEnter elements of array: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);

}
printf("\nUnSorted array is: ");
for(int i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }

partition(A,0,n-1);
printf("\nSorted array is: ");
for(int i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }

return 0;
} 
