#include <stdio.h>
int isNotSafe(int,int);
int findQueensRow(int);
int solveNQ(int);
void initialise();
void print(int);
static int board[10][10];
static int n;
int main()
{	n=4;
	initialise();
	solveNQ(0);
	print(n);
	return 0;
	
}
int solveNQ(int column)
{	
	int i;
	/*return true when n columns has been covered*/
	if(column>=n)
	{
		return 1;
	}
	for(i=0;i<n;i++)
	{	
		if(!isNotSafe(i,column))
		{	/*place the queen in valid row*/
			board[i][column]=1;
			/*solve for next column if in that column queen is placed successfully and returns true then this column will also return 				true*/
			if(solveNQ(column+1))
				return 1;
			/*backtracking when above statement turns out to be false, and loop continues to find next row in the column*/
			board[i][column]=0;
		}
	}
	/* return 0 if unsuccful to place the queen and all rows has been exhausted*/
	return 0;
}

int isNotSafe(int row,int column)
{	/*always check the left side as no queen has beenplaced on the right*/
	int i,j;
	/*left side of a row*/
	for(i=column;0<=i;i--)
	{
		if(board[row][i])
			return board[row][i]; 
	}
	/*left upper diagonal*/
	for(i=row,j=column;0<=i&&0<=j;i--,j--)
	{
		if(board[i][j])
			return board[i][j]; 
	}
	/*left lower diagonal*/
	for(i=row,j=column;0<=j&&i<n;i++,j--)
	{
		if(board[i][j])
			return board[i][j]; 
	}
	return 0;

}
void initialise()
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			board[i][j]=0;
			
		}
	}
}
void print(int n1)
{
	int i,j;
	
	for(i=0;i<n1;i++)
	{
		for(j=0;j<n1;j++)
		{
			printf("%d ",board[i][j]);
		}
		puts("");
	}
}
