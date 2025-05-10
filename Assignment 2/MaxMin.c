/* Write a C program to implement the Maximum-Minimum Algorithms by using following functions:
a)	Define main () to store n number of unsorted integers in an array.
b)	Define a function to implement the Maximum and Minimum integer from the array by using Divide & Conquer.
c)	Define a function to display the Maximum and Minimum integer.

Divide and Conquer Algorithm for this problem would proceed as follows:

a. Let P = (n, a [i],……,a [j]) denote an arbitrary instance of the problem.

b. Here ‘n’ is the no. of elements in the list (a [i],….,a[j]) and we are interested in finding the maximum and minimum of the list.

c. If the list has more than 2 elements, P has to be divided into smaller instances.

d. For example, we might divide ‘P’ into the 2 instances, P1=([n/2],a[1],……..a[n/2]) & P2= ( n-[n/2], a[[n/2]+1],….., a[n]) After having divided ‘P’ into 2 smaller sub problems, we can solve them by recursively invoking the same divide-and-conquer algorithm.
*/

#include <stdio.h>

void minmax (int* a, int i, int j, int* min, int* max) 
{
  int lmin, lmax, rmin, rmax, mid;
  if (i == j) 
   {
    *min = a[i];
    *max = a[j];
   } 
  else if (j == i + 1) 
        {
         if (a[i] > a[j]) 
          {
           *min = a[j];
           *max = a[i];
          } 
         else 
         {
          *min = a[i];
          *max = a[j];
         }
      } 
     else 
      {
       mid = (i + j) / 2;
       minmax(a, i, mid, &lmin, &lmax);
       minmax(a, mid + 1, j, &rmin, &rmax);
      *min = (lmin > rmin) ? rmin : lmin;
      *max = (lmax > rmax) ? lmax : rmax;
     }
}
void display(int *min, int *max, int n, int *A)
{
  int i;
  printf("\n***********Input list:***********\n");
  for(i=0; i<n; i++)
   printf("%4d",A[i]);
  printf("\n*************Output***********");
  printf ("\nMin = %d and Max= %d\n", *min, *max);
  printf("\n******************************");
}

int main ()
 {
  int a [100], n,i; //= {3, 4, 2, 6, 8, 1, 9, 12, 15, 11};
  int min, max;
  printf("\nEnter the number of elements");
  scanf("%d",&n);
  printf("\nEnter the element in the array:");
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);
  minmax (a, 0, n-1, &min, &max);
  display(&min, &max, n, a); 
return 0;
}
/*
Input (1)
Enter the number of elements10

Enter the element in the array:
34 23 11 67 90 91 9 24 56 19

***********Input list:***********
  34  23  11  67  90  91   9  24  56  19
*************Output**************
Min = 9 and Max= 91

*********************************
Input(2)
Enter the number of elements5

Enter the element in the array:
6 1 9 2 7

***********Input list:***********
   6   1   9   2   7
*************Output***********
Min = 1 and Max= 9

******************************
*/