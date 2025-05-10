/*
Write a C program to implement the chain matrix multiplication algorithm by using Dynamic Programming as follows: 
a) Define main () to read n (>1) number of matrices and their dimensions as integer.
b) Define a function to generate the cost matrix for chain of matrices.
c) Define a function to find the minimum number of scalar multiplication for chain of matrix.
d) Define a function to print optimal Matrix Multiplication Sequence.

Let M[i,j] represent the number of multiplications required for matrix product Ai×⋯×Aj
For 1≤i≤j<n
M[i,i]=0 since no product is required; i=j
The optimal solution of Ai×Aj must break at some point, k, with i≤k<j
Thus, M[i,j]=M[i,k]+M[k+1,j]+di−1dkdj
We are given the sequence {4, 10, 3, 12, 20, and 7}. 
The matrices have size 4 x 10, 10 x 3, 3 x 12, 12 x 20, 20 x 7.
The dimensions ={p0,p1,p2,p3,p4}={4, 10, 3, 12, 20, 7}
 We need to compute M [i,j], 0 ≤ i, j≤ 5. We know M [i, i] = 0 for all i.
Calculation of Product of 2 matrices:
1. m (1,2) = m1  x m2
           = 4 x 10 x  10 x 3
           = 4 x 10 x 3 = 120
		   
2. m (2, 3) = m2 x m3
            = 10 x 3  x  3 x 12
            = 10 x 3 x 12 = 360
			
3. m (3, 4) = m3 x m4 
            = 3 x 12  x  12 x 20
            = 3 x 12 x 20 = 720
			
4. m (4,5) = m4 x m5
           = 12 x 20  x  20 x 7
           = 12 x 20 x 7 = 1680
Calculation of Product of 3 matrices:
1. M [1, 3] = M1 M2 M3
   M[1,3] = min{M[1,2] + M[3,3] + p0p2p3, M[1,1] + M[2,3] + p0p1p3}
          =min{120 +0 +4*3*12, 0 +360 + 4*10*12}
         = min{264, 840} = 264
2. M [2, 4] = M2 M3 M4
   N[2, 4] = min{ M[2,3] + M[4,4] + p1p3p4, M[2,2]+M[3,4]+p1p2p4}
   M [2, 4] =min{2760, 1320} = 1320
3. M [3, 5] = M3  M4  M5
   M [3, 5] = min{M[3,4] + M[5,5] +p2p4p5, M[3,3] + M[4,5]+p2p3p5}
            =min{1140, 1932} = 1140
 
Calculation of Product of 4 matrices:
M [1, 4] = M1  M2 M3 M4
         =min{M[1,3]+M[4,4]+p0p3p4, M[1,2]+M[3,4]+p0p2p4, M[1,1]+M[2,4]+p0p1p4}
         =min{264 + 0 + 4*12*20, 120+720+4*3*20, 0+1320 +4*10*20}
M [1, 4] =min{1224, 1080, 2120} = 1080

Calculation of Product of 5 matrices:
M[1,5]=min{1544, 2016, 1344, 1630} = 1344
*/

#include <stdio.h>
#include<limits.h>
#define INFY 999999999

long int m[20][20];
int s[20][20];
int p[20];

void print_optimal(int i,int j)
{
if (i == j)
printf(" A%d ",i);
else
   {
      printf("( ");
      print_optimal(i, s[i][j]);
      print_optimal(s[i][j] + 1, j);
      printf(" )");
   }
}

void MatrixChainMultiplication(int n)
{
long int q;
int k, i, j;
for(i=n;i>0;i--)
 {
   for(j=i;j<=n;j++)
    {
     if(i==j)
       m[i][j]=0;
     else
       {
        for(k=i;k<j;k++)
        {
         q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
         if(q<m[i][j])
          {
            m[i][j]=q;
            s[i][j]=k;
          }
         }
        }
      }
 }
}

int MatrixChainOrder(int p[], int i, int j)
{
    if(i == j)
        return 0;
    int k;
    int min = INT_MAX;
    int count;
 
    for (k = i; k <j; k++)
    {
        count = MatrixChainOrder(p, i, k) +
                MatrixChainOrder(p, k+1, j) +
                p[i-1]*p[k]*p[j];
 
        if (count < min)
            min = count;
    }
 
    // Return minimum count
    return min;
}

int main()
{
int k, n, i, j;
printf("Enter the no. of matrices: ");
scanf("%d",&n);
for(i=1;i<=n;i++)
   for(j=i+1;j<=n;j++)
   {
    m[i][i]=0;
    m[i][j]=INFY;
    s[i][j]=0;
   }
printf("\nEnter the dimensions: \n");
for(k=0;k<=n;k++)
{
 printf("P%d: ",k);
 scanf("%d",&p[k]);
}

MatrixChainMultiplication(n);

printf("\n************Cost Matrix M*************\n");
for(i=1;i<=n;i++)
 for(j=i;j<=n;j++)
  printf("m[%d][%d]: %ld\n",i,j,m[i][j]);
printf("\n***************************************\n");

i=1,j=n;

printf("\n************Multiplication Sequence*****\n");
print_optimal(i,j);
printf("\n***************************************\n");

printf("\nMinimum number of multiplications is : %d ",
                          MatrixChainOrder(p, 1, n));
return 0;
}

/*
**********output*****************
(1)
Enter the no. of matrix: 4

Enter the dimensions:
P0: 5
P1: 4
P2: 6
P3: 2
P4: 7

********Cost Matrix M ************
m[1][1]: 0
m[1][2]: 120
m[1][3]: 88
m[1][4]: 158
m[2][2]: 0
m[2][3]: 48
m[2][4]: 104
m[3][3]: 0
m[3][4]: 84
m[4][4]: 0

***********************************

*******Multiplication Sequence*******
( (  A1 (  A2  A3  ) ) A4  )
*************************************

Minimum number of multiplications is : 158
(2)
Enter the no. of matrices: 5

Enter the dimensions:
P0: 4
P1: 10
P2: 3
P3: 12
P4: 20
P5: 7

************Cost Matrix M*************
m[1][1]: 0
m[1][2]: 120
m[1][3]: 264
m[1][4]: 1080
m[1][5]: 1344
m[2][2]: 0
m[2][3]: 360
m[2][4]: 1320
m[2][5]: 1350
m[3][3]: 0
m[3][4]: 720
m[3][5]: 1140
m[4][4]: 0
m[4][5]: 1680
m[5][5]: 0

***************************************

************Multiplication Sequence*****
( (  A1  A2  )( (  A3  A4  ) A5  ) )
***************************************

Minimum number of multiplications is : 1344
*/

