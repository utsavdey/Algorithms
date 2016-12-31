#include <stdio.h>
#include <stdlib.h>
#define INFINITE 9999
void input(int [][10],int);
void print(int [][10],int);
int main()
{
	int D[10][10],S[10][10];
	int row,column,iteration;
	int n;
	puts("Enter n");
	scanf("%d",&n);
	input(D,n);
	for(iteration=0;iteration<n;iteration++)
	{
		for(row=0;row<n;row++)
		{
			for(column=0;column<n;column++)
			{
				if(D[iteration][column]+D[row][iteration]<D[row][column])
				{
					D[row][column]=D[iteration][column]+D[row][iteration];
					S[row][column]=iteration;
					continue;
				}
					S[row][column]=column;
			}
		}
	}
	print(D,n);
	print(S,n);
	
	
}
void print(int nodes[][10],int n)
{
	int i,j;
	puts("Enter negative numbers for non existing edges");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i==j)
			{
				printf(" - ");
				continue;
			}
			if(nodes[i][j]==INFINITE)
			{
				printf(" ∞ ");
				continue;
			}
			printf(" %d ",nodes[i][j]);
		}
		puts("");
	}
	
	
}

void input(int nodes[][10],int n)
{
	int i,j,temp;
	puts("Enter negative numbers for non existing edges");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i==j)
			{
				nodes[i][j]=INFINITE;
				continue;
			}
			printf("Weight of the edge beetween %d and %d = ",i,j);
			scanf("%d",&temp);
			if(temp<0) temp=INFINITE;
			nodes[i][j]=temp; 
		}
	}
	
	
}


 
