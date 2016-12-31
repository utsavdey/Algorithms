#include <stdio.h>
#include <stdlib.h>
#define INFINITE 9999

struct mstNode
{
	int key;
	int parent;
	int isVisited;
	int inMST;
};
void input(int [][10],int);
void relax(struct mstNode *,int [][10],int,int );
int findMin(struct mstNode *,int );

int main()
{
	//variable definition
	int nodes[10][10],k,i,j,n,min;
	struct mstNode mst[10];
	//input section
	printf("Enter the number of nodes you require\n");
	scanf("%d",&n);
	input(nodes,n);
	// initialise MST node list list
	k=n-1;
	for(i=0;i<n;i++)
	{
		mst[i].key=INFINITE;
		mst[i].parent=-1;
		mst[i].isVisited=0;
		mst[i].inMST=0;
	}
	
	//start
	 relax(mst,nodes,0,n);
	//build the MST
	while(k--)
	{
		min=findMin(mst,n);
		mst[min].inMST=1;
		relax(mst,nodes,min,n);
	}
	//print
	for(i=0;i<n;i++)
	{
		if(mst[i].inMST==1)
		{
			printf("Edge (%d %d) weight = %d\n",mst[i].parent,i,mst[i].key);
		}

	}
}
 void relax(struct mstNode *mst,int nodes[][10],int node,int n)
{	int k,i;
	for(k=0;k<n;k++)
	{	
		if(mst[k].isVisited==0&&(nodes[node][k]<mst[k].key)&&node!=k)
		{	mst[k].key=nodes[node][k];
			mst[k].parent=node;
			
		}
	}
	mst[node].isVisited=1;
}
int findMin(struct mstNode* mst,int n)
{	int minPos,min=INFINITE,i;
	for(i=0;i<n;i++)
	{	
		if(min>mst[i].key&&mst[i].isVisited==0)
		{
			minPos=i;
			min=mst[i].key;
			
		}
	}

	return minPos;
}

void input(int nodes[][10],int n)
{
	int i,j,temp;
	puts("Enter negative numbers for non existing edges");
	for(i=0;i<n;i++)
	{
		for(j=0;j<=i;j++)
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
			nodes[j][i]=nodes[i][j]; 
		}
	}
	
	
}

 
