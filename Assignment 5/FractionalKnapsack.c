#include<stdio.h>
#include<stdlib.h>
void input(int *x,int *w,int *v,float *r,int n,int *c)
{
    for(int i=0;i<n;i++)
    {
        printf("Enter weight and value of item %d:",i+1);
        scanf("%d %d",&w[i],&v[i]);
        r[i] = (float)v[i]/w[i];
        x[i]=i+1;
    }
    printf("Enter capacity of knapsack:");
    scanf("%d",c);
}
void sort(int *x,int *w,int *v,float *r,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(r[i]<r[j])
            {
                float t = r[i];
                r[i] = r[j];
                r[j] = t;
                int temp = w[i];
                w[i] = w[j];
                w[j] = temp;
                temp = v[i];
                v[i] = v[j];
                v[j] = temp;
                temp= x[i];
                x[i] = x[j];
                x[j] = temp;
            }
        }
    }
}
void KS(int *x,int *w,int *v,float *r,float * x1,int n,int c,float *profit)
{
    for(int i=0;i<n;i++)
    {
        if(w[i]<=c)
        {
            c = c - w[i];
            *profit += v[i];
            x1[x[i]-1]=1.0;
        }
        else
        {
            *profit += (c*r[i]);
            x1[x[i]-1]=(float)c/w[i];
            break;
        }
        
    }
}

void printItems(int *x,int *w,int *v,float *r,int n)
{
    printf("Items in knapsack are:\n");
    for(int i=0;i<n;i++)
    {
        printf("Item %d: weight = %d, value = %d, ratio = %.2f\n",x[i],w[i],v[i],r[i]);
    }
} 
void final(int *x,int *w,int *v,float *r,float * x1,int n,int c,float  profit)  
{ 
    KS(x,w,v,r,x1,n,c,&profit);
    printf("Maximum profit is %.2f\n",profit);
    printf("Resultant Vector\n");
    for(int i=0;i<n;i++)
    {
        printf("Item %d  Part %.3f\n",i+1,x1[i]);
    }
    printf("\n");
}

int main()
{
    int n ,*w,*v,*x,c; float profit=0.0;
    printf("Enter number of items:");
    scanf("%d",&n);
    w = (int *)malloc(n*sizeof(int));
    v = (int *)malloc(n*sizeof(int));
    float *r = (float *)malloc(n*sizeof(float));
    x = (int *)malloc(n*sizeof(int));
    float *x1 = (float *)calloc(n,sizeof(float));
    input(x,w,v,r,n,&c);
    printItems(x,w,v,r,n);
    sort(x,w,v,r,n);
    final(x,w,v,r,x1,n,c,profit);
    free(w);
    free(v);
    free(r);
    free(x);
    return 0;
    
   
}