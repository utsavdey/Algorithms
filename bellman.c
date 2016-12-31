#include <stdio.h>
#include <stdlib.h>
#define INFINITE 9999
struct edge
{
	int v1;
	int v2;
	int weight;
};
struct Node
{
	int predecessor;
	int distanceFromSource;
};
void input(int [][10],int);
int main()
{
	//variable definition
	int nodes[10][10],k,i,j,n,source,v1,v2;
	struct edge edges[30];
	struct Node nodeList[10];
	//input section
	printf("Enter the number of nodes you require\n");
	scanf("%d",&n);
	input(nodes,n);
	// make edge list
	k=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(nodes[i][j]==INFINITE)
			{
				continue;
			}
			edges[k].v1=i;
			edges[k].v2=j;
			edges[k].weight=nodes[i][j];
			k++; 
		}
	}
	// initialise node list
	for(i=0;i<n;i++)
	{
		nodeList[i].predecessor=-1;
		nodeList[i].distanceFromSource=INFINITE;
	}
	//take in the source
	printf("Enter source node\n");
	scanf("%d",&source);
	nodeList[source].distanceFromSource=0;
	//do n-1 iteration on the edge list and relax them
	i=0;
	while(i<n-1)
	{
		for(j=0;j<k;j++)
		{
			v1=edges[j].v1;
			v2=edges[j].v2;
			if(nodeList[v2].distanceFromSource>(nodeList[v1].distanceFromSource+edges[j].weight))
			{
				nodeList[v2].distanceFromSource=nodeList[v1].distanceFromSource+edges[j].weight;
				nodeList[v2].predecessor=v1;
			}

		}
		i++;
	}
	//detect negative edge
	for(j=0;j<k;j++)
	{
		v1=edges[j].v1;
		v2=edges[j].v2;
		if(nodeList[v2].distanceFromSource>(nodeList[v1].distanceFromSource+edges[j].weight))
		{
			puts("Negative edge cycle found");
			return 0;
		}

	}
	for(i=0;i<n;i++)
	{
		printf("Distance = %d Predecessor= %d \n",nodeList[i].distanceFromSource,nodeList[i].predecessor);
	}
	return 0;
	
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
			printf("Weight of the edge beetween %d and %d = ",i+1,j+1);
			scanf("%d",&temp);
			nodes[i][j]=temp;
		}
	}
	
	
}

 
