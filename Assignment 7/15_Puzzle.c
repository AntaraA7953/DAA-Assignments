// n puzle problem 

#include<stdio.h>
#include<limits.h>
int cal(int temp[10][10],int t[10][10], int n)
{
	int i,j,m=0;
	for(i=0;i < n;i++)
		for(j=0;j < n;j++)
		{
			if(temp[i][j]!=t[i][j])
			m++;
		}
	return m;
}

int check(int a[10][10],int t[10][10], int n)
{
	int i,j,flag=1;
	for(i=0;i < n;i++)
		for(j=0;j < n;j++)
			if(a[i][j]!=t[i][j])
				flag=0;
	return flag;
}

void display(int r[10][10], int n, int d)
{
	int i, j;
	printf("\nCalculated Intermediate Matrix Value::\n");
		for(i=0;i < n;i++)
		{
			for(j=0;j < n;j++)
			  printf("%d\t",r[i][j]);
			printf("\n");
		}
		printf("Minimum cost : %d\n",d);
}

void puzzle(int a[10][10], int t[10][10], int n)
{
 	int p,i,j,temp[10][10],r[10][10];
	int x=0,y=0,d=INT_MAX, dmin=0,l=0, m=0;

	while(!(check(a,t,n)))
	{
		l++;
		d=INT_MAX;
		for(i=0;i < n;i++)
			for(j=0;j < n;j++)
			{
				if(a[i][j]==0)
				{
					x=i;
					y=j;
				}
			}

							//To move upwards
		for(i=0;i < n;i++)
			for(j=0;j < n;j++)
				temp[i][j]=a[i][j];

		if(x!=0)
		{
			p=temp[x][y];
			temp[x][y]=temp[x-1][y];
			temp[x-1][y]=p;
		}
		m=cal(temp,t,n);
		dmin=l+m;
		if(dmin < d)
		{
			d=dmin;
			for(i=0;i < n;i++)
				for(j=0;j < n;j++)
					r[i][j]=temp[i][j];
		}

							//To move downwards
		for(i=0;i < n;i++)
			for(j=0;j < n;j++)
				temp[i][j]=a[i][j];
		if(x!=n-1)
		{
			p=temp[x][y];
			temp[x][y]=temp[x+1][y];
			temp[x+1][y]=p;
		}
		m=cal(temp,t,n);
		dmin=l+m;
		if(dmin < d)
		{
			d=dmin;
			for(i=0;i < n;i++)
				for(j=0;j < n;j++)
					r[i][j]=temp[i][j];
		}

							//To move right side
		for(i=0;i < n;i++)
			for(j=0;j < n;j++)
				temp[i][j]=a[i][j];
		if(y!=n-1)
		{
			p=temp[x][y];
			temp[x][y]=temp[x][y+1];
			temp[x][y+1]=p;
		}
		m=cal(temp,t,n);
		dmin=l+m;
		if(dmin < d)
		{
			d=dmin;
			for(i=0;i < n;i++)
				for(j=0;j < n;j++)
					r[i][j]=temp[i][j];
		}

							//To move left
		for(i=0;i < n;i++)
			for(j=0;j < n;j++)
				temp[i][j]=a[i][j];
		if(y!=0)
		{
			p=temp[x][y];
			temp[x][y]=temp[x][y-1];
			temp[x][y-1]=p;
		}
		m=cal(temp,t,n);
		dmin=l+m;
		if(dmin < d)
		{
			d=dmin;
			for(i=0;i < n;i++)
				for(j=0;j < n;j++)
					r[i][j]=temp[i][j];
		}

		display(r,n, d);
		
		for(i=0;i < n;i++)
			for(j=0;j < n;j++)
			{
			  a[i][j]=r[i][j];
			  temp[i][j]=0;
			}
	}//End while
}


int main()
{
	int i,j,a[10][10],t[10][10], n;
	
	printf("\n Enter the size of the matrix:");
	scanf("%d", &n);
	
	printf("\nEnter the initial matrix to be solved,space with zero :\n");
	for(i=0;i < n;i++)
		for(j=0;j < n;j++)
			scanf("%d",&a[i][j]);

	printf("\nEnter the target matrix,space with zero :\n");
	for(i=0;i < n;i++)
		for(j=0;j < n;j++)
			scanf("%d",&t[i][j]);

	printf("\nEntered Matrix is(Initial configuration) :\n");
	for(i=0;i < n;i++)
	{
		for(j=0;j < n;j++)
			printf("%d\t",a[i][j]);
		printf("\n");
	}

	printf("\nTarget Matrix is (Solvable Final configuration):\n");
	for(i=0;i < n;i++)
	{
		for(j=0;j < n;j++)
			printf("%d\t",t[i][j]);
		printf("\n");
	}

	puzzle(a,t,n);
		
 return 0;
}
/*
Output:
(1)---------------------------------------------------------------------
 Enter the size of the matrix:3

Enter the matrix to be solved,space with zero :
1
2
3
5
6
0
7
8
4

Enter the target matrix,space with zero :
1
2
3
5
8
6
0
7
4

Entered Matrix is(Initial configuration) :
1       2       3
5       6       0
7       8       4

Target Matrix is (Solvable Final configuration):
1       2       3
5       8       6
0       7       4

Calculated Intermediate Matrix Value :
1       2       3
5       0       6
7       8       4
Minimum cost : 4

Calculated Intermediate Matrix Value :
1       2       3
5       8       6
7       0       4
Minimum cost : 4

Calculated Intermediate Matrix Value :
1       2       3
5       8       6
0       7       4
Minimum cost : 3
(2)----------------------------------------------------------------------
 Enter the size of the matrix:4
 
Enter the matrix to be solved,space with zero:
1
2
3
4
5
6
0
8
9
10
7
11
13
14
15
12

Enter the target matrix,space with zero :
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
0

Entered Matrix is :
1       2       3       4
5       6       0       8
9       10      7       11
13      14      15      12

Target Matrix is :
1       2       3       4
5       6       7       8
9       10      11      12
13      14      15      0

Calculated Intermediate Matrix Value :
1       2       3       4
5       6       7       8
9       10      0       11
13      14      15      12
Minimum cost : 4

Calculated Intermediate Matrix Value :
1       2       3       4
5       6       7       8
9       10      11      0
13      14      15      12
Minimum cost : 4

Calculated Intermediate Matrix Value :
1       2       3       4
5       6       7       8
9       10      11      12
13      14      15      0
Minimum cost : 3
*/
