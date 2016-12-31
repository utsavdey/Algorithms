#include <stdio.h>
#include <stdlib.h>
#define INFINITE 9999
struct edge
{
	int v1;
	int v2;
	int weight;
	int inMST;
};
struct mstNode
{
	int key;
	int cluster;
};
void input(int [][10],int);
void bubbleSort(struct edge[] , int );
void print(int [][10],int [][10],int);
void swap(struct edge *,struct edge* );
void joinCluster(struct mstNode*,int ,int,int );
int main()
{
	//variable definition
	int nodes[10][10],k,i,j,n,visited[10];
	struct edge edges[30];
	struct mstNode mst[10];
	//input section
	printf("Enter the number of nodes you require\n");
	scanf("%d",&n);
	input(nodes,n);
	// make edge list
	k=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<=i;j++)
		{
			if(nodes[i][j]==INFINITE)
			{
				continue;
			}
			edges[k].v1=i;
			edges[k].v2=j;
			edges[k].weight=nodes[i][j];
			edges[k].inMST=0;
			k++; 
		}
	}
	// initialise
	for(i=0;i<n;i++)
	{
		mst[i].key=i;
		mst[i].cluster=i;
	}
	//sort
	bubbleSort(edges,k);
	//build the MST
	for(i=0;i<k;i++)
	{	
		if(mst[edges[i].v1].cluster!=mst[edges[i].v2].cluster)
		{	
			joinCluster(mst,mst[edges[i].v1].cluster,mst[edges[i].v2].cluster,n);
			edges[i].inMST=1;
		}

	}
	//print
	for(i=0;i<k;i++)
	{
		if(edges[i].inMST==1)
		{
			printf("Edge (%d %d) weight = %d\n",edges[i].v1,edges[i].v2,edges[i].weight);
		}

	}
}
void joinCluster(struct mstNode* mst,int i,int j,int n)
{	int k;
	for(k=0;k<n;k++)
	{
		if(mst[k].cluster==j)
			mst[k].cluster=i;
	}
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
void swap(struct edge *p1,struct edge *p2)
{
    struct edge  *temp = p1;
    p1=p2;
    p2=temp;
}
void bubbleSort(struct edge edges[], int n)
{	
	int i, j;
	struct edge temp;
	for (i = 0; i < n; i++)      
	{	//last ith elements already in place  
		for (j = i+1; j < n; j++) 
		{	if (edges[i].weight>edges[j].weight)
			{
				  	temp=edges[i];
				  	edges[i]=edges[j];
					edges[j]=temp;
				 
				
			}
		}
	}
	
}

 
