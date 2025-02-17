#include<stdio.h>
#include<stdlib.h>
void merge(int A[], int l,int m, int h)
{
    int n1=m-1+1;
    int n2=h-m;
    int *x=(int *)malloc(n1*sizeof(int));
    int *y=(int *)malloc(n2*sizeof(int));
    for(int i=0;i<n1;i++)
    x[i]=A[l+i];
    for(int i=0;i<n2;i++)
    y[i]=A[m+1+i];
    int i=0,j=0,k=l;
    while(i!=n1 && j!=n2)
    {
        if(x[i]<y[j])
        {
            A[k]=x[i];
            i++;
        }
        else if(x[i]>y[i])
        {
            A[k]=y[j];
            j++;
        }
        k++;
    }
    while(i!=n1)
    {
        A[k]=x[i];
        i++;
        k++;
    }
    while(j!=n2)
    {
        A[k]=y[j];
        j++;
        k++;
        }

}

void MergeSort(int A[],int l,int h)
{
    if(l>h)
    return;
    int m=(l+h)/2;
    MergeSort(A,l,m);
    MergeSort(A,m+1,h);
    merge(A,l,m,h);
    
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

mergesort(A,0,n-1);
printf("\nSorted array is: ");
for(int i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }
return 0;
} 
