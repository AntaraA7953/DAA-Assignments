/*
Write a C program to implement the graph coloring problem by using Backtracking method as follows:
a) Define main () to read number of vertices, edges  and assign 0 and/or 1 to all index of adjacency matrix
b) Define a function– next-color() to solve the graph coloring problem using backtracking 
c) Define a function to displaying the color of each vertex.

Graph-Coloring : In this problem, for any given graph G 
we will have to color each of the vertices in G in such a way that
no two adjacent vertices get the same color and the least number of colors are used.

In this problem, an undirected graph is given. 
There is also provided m colors. The problem is to find if it is possible to assign nodes with m different colors, 
such that no two adjacent vertices of the graph are of the same colors. 
If the solution exists, then display which color is assigned on which vertex.

Starting from vertex 0, we will try to assign colors one by one to different nodes. 
But before assigning, we have to check whether the color is safe or not. 
A color is not safe whether adjacent vertices are containing the same color.

How to solve the problem?????
 
First take input number of vertices and edges in graph G. 
Then input all the indexes of adjacency matrix of G whose value is 1.
Now we will try to color each of the vertex. 
A next_color(k) function takes in index of the kth vertex which is to be colored. 
First we assign color1 to the kth vertex.Then we check whether it is connected to any of previous (k-1) vertices using backtracking. 
If connected then assign a color x[i]+1 where x[i] is the color of ith vertex that is connected with kth vertex.

Enter no. of vertices : 4

     v0-------------v1
     |            /  |
     |          /    |
     |        /      |
     |     /         |  
     |   /           |
     | /             |
     v2-------------v3    
         Graph G
Input:
The adjacency matrix of a graph G(V, E) and an integer m, 
which indicates the maximum number of colors that can be used.
Adjacency matrix:
   0	1	2	3
--|------------------------
0 | 0	1	1	0
1 | 1	0	1	1
2 | 1	1	0	1
3 | 0	1	1	0

Enter no. of edges : 5

Enter indexes where value is 1-->
1 0
2 0
2 1
3 1
3 2

Let the maximum color m = 3.
This algorithm will return which node will be assigned with which color. If the solution is not possible, it will return false.
For this input the assigned colors are:
Colors of vertices -->
Vertex[1] : 1
Vertex[2] : 2
Vertex[3] : 3
Vertex[4] : 1

Algorithm:

 GraphColour(G, no, eg) // G is the adjacency matrix of a graph whose initial assign 0 to all index of adjacency matrix, 
                         //no is the total number of vertices 
                        //and eg is the number of edges 
Steps:
  1. for i=0 to eg-1              //Enter indexes where value is 1
       read u, v
       G[u][v]=1
       G[v][u]=1
  2. Next_color(0, no);           //coloring each vertex, 0 is starting vertex
  3. return


Next_color(k, n) // check and find unique colour 
Steps:
   1. if k==n Then
        display(n)                       
        return
   2. x[k]=1  				//coloring vertex with color 1
   3. for i=0 to k-1 Do           	//checking all k-1 vertices-backtracking
        if(G[i][k]!=0 && x[k]==x[i]) Then  	//if connected and has same color
            x[k]=x[i]+1  		//assign higher color than x[i]
   4. next_color(k+1, n)
   5. return 

Display(n)  // // display n number of vertices with unique colours of adjacency vertices 
Steps:
   1. write "Colors of vertices:"
   2. for i=0 to n-1 Do			 //displaying color of each vertex
         write "Vertex", i+1,"Colour", x[i]
   3. return

*/
//------------------------------------------------------------------------------------------------
#include<stdio.h>

int G[50][50], x[50];  			//G:adjacency matrix,x:colors

void display(int n)
{
   int i;
   printf("Colors of vertices -->\n");
   for(i=0;i<n;i++)  			//displaying color of each vertex
     printf("Vertex[%d] : %d\n",i+1,x[i]);
}

void next_color(int k, int n)
{
   int i,j;
   if(k==n)
    {
     display(n);                       // calling the display()
     return;
    }
   x[k]=1;  				//coloring vertex with color1
   for(i=0;i<k;i++)
   { 					//checking all k-1 vertices-backtracking
     if(G[i][k]!=0 && x[k]==x[i])  	//if connected and has same color
       x[k]=x[i]+1;  			//assign higher color than x[i]
   }
   next_color(k+1, n);
}


int main()
{
  int no,eg,i,j,k,l;

  printf("\nEnter no. of vertices : ");
  scanf("%d",&no);  			//total vertices

  printf("\nEnter no. of edges : ");
  scanf("%d",&eg);  			//total edges
 
  for(i=0;i<no;i++)
    for(j=0;j<no;j++)
      G[i][j]=0;  			//assign 0 to all index of adjacency matrix
     
  printf("Enter indexes where value is 1-->\n");
  for(i=0;i<eg;i++)
  {
    scanf("%d %d",&k,&l);
    G[k][l]=1;
    G[l][k]=1;
  }
 
    next_color(0, no);  			//coloring each vertex

  return 0;
}

/*
-------------------------------Input Output -----------------------------------
Enter no. of vertices : 4

Enter no. of edges : 5
Enter indexes where value is 1-->
1 0
2 0
2 1
3 1
3 2
Colors of vertices -->
Vertex[1] : 1
Vertex[2] : 2
Vertex[3] : 3
Vertex[4] : 1
----------------------------------------------------------------------------------
*/
