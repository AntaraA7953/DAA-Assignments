/*
Write a C program to implement the Kruskal's Algorithm for undirected graph by using following functions:
a)	Define main () to input the cost matrix of a graph.
b)	Define a functions to find Minimum Cost of the Spanning Tree of an undirected graph using Kruskal's algorithm.
c)	Define a function to display the input cost matrix and minimum cost.


 Implementation of Kruskal's algorithm

Enter the no. of vertices:6

Enter the cost adjacency matrix:
0 3 1 6 0 0
3 0 5 0 3 0
1 5 0 5 6 4
6 0 5 0 0 2
0 3 6 0 0 6
0 0 4 2 6 0

Input cost adjacency matrix:

  0  3  1  6  0  0
  3  0  5  0  3  0
  1  5  0  5  6  4
  6  0  5  0  0  2
  0  3  6  0  0  6
  0  0  4  2  6  0

The edges of Minimum Cost Spanning Tree are
1 edge (1,3) =1
2 edge (4,6) =2
3 edge (1,2) =3
4 edge (2,5) =3
5 edge (3,6) =4

        Minimum cost = 13

*/

#include<stdio.h>
#include<limits.h>

int parent[20]={0}, mincost=0;

int find(int i)
{
	while(parent[i])
		i=parent[i];
	return i;
}


int uni(int i,int j)
{
	if(i!=j)
	{
		parent[j]=i;
		return 1;
	}
	return 0;
}


void kruskalMST(int n, int mcost[20][20])
{
   int i, j, min, a, b, u, v, ne=1;
	
	printf("\n\nThe edges of Minimum Cost Spanning Tree are\n");
	while(ne < n)
	{
		for(i=1,min=INT_MAX;i<=n;i++)
		{
			for(j=1;j <= n;j++)
			{
				if(mcost[i][j] < min)
				{
					min=mcost[i][j];
					a=u=i;
					b=v=j;
				}
			}
		}
		u=find(u);
		v=find(v);
		if(uni(u,v))
		{
			printf("%d edge (%d,%d) =%d\n",ne++,a,b,min);
			mincost +=min;
		}
		mcost[a][b]=mcost[b][a]=INT_MAX;
	}	//end while
}


void display(int n, int temp[20][20])
{
	int i, j;
	printf("\nInput cost adjacency matrix:\n");
	for(i=1;i<=n;i++)
	{
 		printf("\n");
		for(j=1;j<=n;j++)
		{
			if(temp[i][j]==INT_MAX)
            	printf("  0");
            else
			   printf("%3d",temp[i][j]);
		}
	}
	printf("\n\tMinimum cost = %d\n",mincost);
}


int main()
{
   	int n, i,j, cost[20][20], temp[20][20];
	printf("\n\tImplementation of Kruskal's algorithm\n");

	printf("\nEnter the no. of vertices:");
	scanf("%d",&n);

	printf("\nEnter the cost adjacency matrix:\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&cost[i][j]);
			if(cost[i][j]==0)
				cost[i][j]=INT_MAX;
		}
	}
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		   temp[i][j]=cost[i][j];
			
 	kruskalMST(n, cost);
 	
 	display(n,temp);

return 0;
}
/* 
 Implementation of Kruskal's algorithm

Enter the no. of vertices:7

Enter the cost adjacency matrix:
0 28 0 0 0 10 0
28 0 16 0 0 0 14
0 16 0 12 0 0 0
0 0 12 0 22 0 18
0 0 0 22 0 25 24
10 0 0 0 25 0 0
0 14 0 18 24 0 0


The edges of Minimum Cost Spanning Tree are
1 edge (1,6) =10
2 edge (3,4) =12
3 edge (2,7) =14
4 edge (2,3) =16
5 edge (4,5) =22
6 edge (5,6) =25

Input cost adjacency matrix:

0 28 0 0 0 10 0
28 0 16 0 0 0 14
0 16 0 12 0 0 0
0 0 12 0 22 0 18
0 0 0 22 0 25 24
10 0 0 0 25 0 0
0 14 0 18 24 0 0

        Minimum cost = 99
---------------------------------------------------
 Implementation of Kruskal's algorithm

Enter the no. of vertices:6

Enter the cost adjacency matrix:
0 3 1 6 0 0
3 0 5 0 3 0
1 5 0 5 6 4
6 0 5 0 0 2
0 3 6 0 0 6
0 0 4 2 6 0

Input cost adjacency matrix:

  0  3  1  6  0  0
  3  0  5  0  3  0
  1  5  0  5  6  4
  6  0  5  0  0  2
  0  3  6  0  0  6
  0  0  4  2  6  0

The edges of Minimum Cost Spanning Tree are
1 edge (1,3) =1
2 edge (4,6) =2
3 edge (1,2) =3
4 edge (2,5) =3
5 edge (3,6) =4

        Minimum cost = 13

*/
