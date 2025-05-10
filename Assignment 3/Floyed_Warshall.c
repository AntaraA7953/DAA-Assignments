/*
Write a C program to implement all pair of Shortest path for a graph by using Floyd -Warshall Algorithm ( Dynamic Programming) as follows: 
a) Define main () to input the number of vertices, edges, corresponding weights of edges and cost matrix of the graph.
b) Define a function floyd() to implement all pair of shortest Path for the graph.
c) Define a function to display transitive closure and the optimal all pair shortest paths.

Example,  This allows the following recursive formula for dij, the weight of the minimal path from node i to node j

1. dkij = wij, if k=0
2. dkij = min(dk-1ij, dk-1ik + dk-1kj), if k= 1

If k=0, then there are no intermediate nodes, and the distance is the edge weight
If k=1, then the best path from i to j either: doesn't go through vertex k (ie dk-1ij), or does go through vertex k (ie dk-1ik + dk-1kj)
Choose the best of these two
Imagine a picture of vi, vk, vj and the 3 optimal paths among them:
d(k-1)ij
d(k-1)ik
d(k-1)kj

The above recursive equation gives this algorithm:
    D = W
    for k in 1 .. n loop
        for i in 1 .. n loop
            for j in 1 .. n loop
                d(i, j) := min(D(i, j), D(i, k) + D(k, j))
            end loop
        end loop
    end loop
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int a[100][100], cost[100][100];

void floyd_all_paths(int cost[100][100],int a[100][100], int n)
{
 int i,j,k;
 for(i=1;i<=n;i++)
  for(j=1;j<=n;j++)
    a[i][j]=cost[i][j];
 
 for(k=1;k<=n;k++)
   for(i=1;i<=n;i++)
     for(j=1;j<=n;j++)
        a[i][j]=min1(a[i][j],a[i][k]+a[k][j]);
}
int min1(int a,int b)
{
   return(a<b)?a:b;
}

void display_optimal(int cost[100][100],int a[100][100], int n)
{
	int i, j;
 printf("\n****The adjacency matrix of the given graph*****\n");
 for(i=1;i<=n;i++)
 {
   for(j=1;j<=n;j++)
	  if (cost[i][j]==99999)
	     printf("\tinf");
	  else
        printf("\t%d",cost[i][j]);
   printf("\n");
 }
 printf("\n ................................................\n ");
 printf("\n*****All the shortest paths obtained is******\n");
 for(i=1;i<=n;i++)
  {
   for(j=1;j<=n;j++)
    if (a[i][j]==99999)
	     printf( "\tinf");
	  else
        printf("\t %d",a[i][j]);
   printf("\n");
  }
  printf("\n ...............................................\n ");
}

int main()
{
 int i,j,n;
 printf("\nEnter the number of vertices::");
 scanf("%d",&n);
 printf("\nEnter the adjacency matrix\n");
 printf("(Enter 99999 if there is no path)\n");
 for(i=1;i<=n;i++)
   for(j=1;j<=n;j++)
      scanf("%d",&cost[i][j]);

 floyd_all_paths(cost, a, n);
 
 display_optimal(cost, a,n);
  return 0;
}
/*
(1)
Enter the number of vertices::4

Enter the adjacency matrix
(Enter 99999 if there is no path)
0 3 99999 7
8 0 2 99999
5 99999 0 1
2 99999 99999 0

****The adjacency matrix of the given graph*****
        0       3       inf     7
        8       0       2       inf
        5       inf     0       1
        2       inf     inf     0

 ...............................................

*****All the shortest paths obtained is******
         0       3       5       6
         5       0       2       3
         3       6       0       1
         2       5       7       0

 ..............................................
*/
