/* Exp-11: Write a C program to implement the N-Queen problem by using Backtracking method as follows:
a) Define a function to read  number of queens
b) Define two functions – queen() and place() for implementation of n-queen problem using backtracking 
c) Define a function to display the result vectors and place of queens as a table form.

N-Queens Problem
----------------
1. N - Queens problem is to place n - queens in such a manner on an n x n chessboard that 
    no queens attack each other by being in the same row, column or diagonal.
2. It can be seen that for n =1, the problem has a trivial solution, and 
    no solution exists for n =2 and n =3. 

So first we will consider the 4 queens problem and then generate it to n - queens problem.

Given a 4 x 4 chessboard and number the rows and column of the chessboard 1 through 4.
-----------------------------------
	1	2	3	4
1

2

3

4
----------------------------------
Since, we have to place 4 queens such as q1 q2 q3 and q4 on the chessboard, such that no two queens attack each other. 
In such a conditional each queen must be placed on a different row, i.e., we put queen "i" on row "i."

Now, we place queen q1 in the very first acceptable position (1, 1). 
Next, we put queen q2 so that both these queens do not attack each other. 
We find that if we place q2 in column 1 and 2, then the dead end is encountered. 

Thus the first acceptable position for q2 in column 3, i.e. (2, 3) but then no position is left for placing queen 'q3' safely. 

So we backtrack one step and place the queen 'q2' in (2, 4), the next best possible solution. 
Then we obtain the position for placing 'q3' which is (3, 2).
But later this position also leads to a dead end, and no place is found where 'q4' can be placed safely. 

Then we have to backtrack till 'q1' and place it to (1, 2) and 
then all other queens are placed safely by moving q2 to (2, 4), q3 to (3, 1) and q4 to (4, 3). 

That is, we get the solution (2, 4, 1, 3). This is one possible solution for the 4-queens problem. 
For another possible solution, the whole method is repeated for all partial solutions. 

The other solutions for 4 - queens problems is (3, 1, 4, 2) i.e.

	1	2	3	4
1	-	-	q1	-

2	q2	-	-	-

3				q3

4		q4

--------------------------------------------------------------------------------------------------------------
Algorithm:Queen(row, n) // to check for proper positioning of queen, initially row =1 and n is no. of queens 
--------------------------------------------------------------------------------------------------------------

 Steps:
	1. for column=1 to n Do
  		if(Place(row,column)) Then
   			c_board[row]=column      //no conflicts so place queen
   			if(row==n) Then          //dead end
    				Display(n);    //printing the board configuration
   			else                   //try queen with next position
    				Queen(row+1,n);
	2. return

Place(row,column) //to check conflicts , If no conflict for desired postion returns 1 otherwise returns 0
	
Steps:
	1. for i=1 to row-1 Do
  		if (c_board[i]==column) Then //checking column and digonal conflicts
   			return 0
  		else
   			if(abs(c_board[i]-column)==abs(i-row)) Then
    	      return 0
        2. return 1; //no conflicts


 Display(n) //function for printing the solution
  
  Steps: 
	    1. fori=1 to n Do
  		    print i
  		    for j=1 to n Do //for nxn board
   			   if(c_board[i]==j) Then
    				print " Q"     //queen at i,j position
   			   else
    				print "   -" //empty slot
       	    2. return
-------------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
 
int c_board[20],count;

//function for printing the solution
void display(int n)
{
	int i,j;
	printf("\n\nSolution %d:\n\n",++count);
 
	for(i=1;i<=n;++i)
  		printf("\t%d",i);
 
	for(i=1;i<=n;++i)
	{
  		printf("\n\n%d",i);
  		for(j=1;j<=n;++j) //for n x n board
 		 {
   			if(c_board[i]==j)
    				printf("\tQ"); //queen at i,j position
   			else
    				printf("\t-"); //empty slot
  		  }
	}
}
 
/*funtion to check conflicts
If no conflict for desired postion returns 1 otherwise returns 0*/

int place(int row,int column)
{
	int i;
	for(i=1;i<=row-1;++i)
	{
  	//checking column and digonal conflicts
  		if(c_board[i]==column)
   			return 0;
  		else
   			if(abs(c_board[i]-column)==abs(i-row))
    	return 0;
   }
   return 1; //no conflicts
}
 
//function to check for proper positioning of queen

void queen(int row,int n)
{
	int column;

	for(column=1;column<=n;++column)
	{
  		if(place(row,column))
  		{
   			c_board[row]=column;   //no conflicts so place queen
   			if(row==n)           //dead end
    				display(n);    //printing the board configuration
   			else                   //try queen with next position
    				queen(row+1,n);
  		}
	}
}
 

int main()
{
	int n,i,j;

	printf("N-Queens Problem Using Backtracking:");
	printf("\n\nEnter number of Queens:");
	scanf("%d",&n);

	queen(1,n); // 1 is first row and n is no. of queens

	return 0;
}
 
/*
------------------------------------------------------------------------------- 
Output:
-------------------------------------------------------------------------------
 N-Queens Problem Using Backtracking:

Enter number of Queens:4

Solution 1:

        1       2       3       4

1       -       Q       -       -

2       -       -       -       Q

3       Q       -       -       -

4       -       -       Q       -

Solution 2:

        1       2       3       4

1       -       -       Q       -

2       Q       -       -       -

3       -       -       -       Q

4       -       Q       -       -
-----------------------------------------------------------------------------
*/
