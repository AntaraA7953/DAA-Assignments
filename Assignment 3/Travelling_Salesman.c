#include <stdio.h>
#include<limits.h>
int c_matrix[25][25], v_cities[10], no_city, cost = 0;
 
int least_tsp(int c)
{
 int count, nearest_city, nd;
 int minimum = INT_MAX, temp;
 for(count = 0; count < no_city; count++)
  {
   if((!v_cities[count]) && (c_matrix[c][count] != 0)&&(c_matrix[c][count]) <minimum)
    {
          minimum = c_matrix[c][count];
          temp = c_matrix[c][count];
          nearest_city = count;
        
    }
  }
   cost = cost + temp;
   nd=nearest_city;
   return nd;
}
 
void min_cost(int city)
{
 int nearest_city;
 
 v_cities[city] = 1;
 
 printf("%d--->", city+1 );
 
 nearest_city = least_tsp(city);
 
 if(nearest_city == INT_MAX)
 {
   int v = 0;
   printf("%d", v+1);
   cost = cost + c_matrix[nearest_city][v];  
   return;
 }
 min_cost(nearest_city);
}
void display()
{
	printf("\n\nMinimum Cost: \t");
    printf("%d\n", cost);
}
 
int main()
{ 
 int i, j;
 printf("Enter Total Number of Cities:\t");
 scanf("%d", &no_city);
 
 printf("\nEnter Cost Matrix\n");
 for(i = 0; i < no_city; i++)
 {
   printf("\nEnter %d Elements in Row[%d]\n", no_city, i + 1);
   for(j = 0; j < no_city; j++)
   {
     scanf("%d", &c_matrix[i][j]);
   }
   v_cities[i] = 0;
 }
 
 printf("\nEntered Cost Matrix\n");
 for(i = 0; i < no_city; i++)
 {
    printf("\n");
    for(j = 0; j < no_city; j++)
    {
       printf("%d ", c_matrix[i][j]);
    }
}

 printf("\n\n TSP Path:\t\t");

 min_cost(0);
 
 display();
 return 0;
}
