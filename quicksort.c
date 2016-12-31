#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int a[100];
int partition(int low,int high)
{
	int iterator,pivot_final,pivot,tmp;
	iterator=low;
	pivot_final=low;
	pivot=a[high];
	while(iterator<high)
	{	if(a[iterator]<pivot)
		{	tmp=a[pivot_final];
			a[pivot_final]=a[iterator];
			a[iterator]=tmp;
			pivot_final++;
		}
		iterator++;
	}
	a[high]=a[pivot_final];
        a[pivot_final]=pivot;
        return pivot_final;                
}
void quicksort(int low,int high)
{
	int i;
	if(low<high)
	{	i=partition(low,high);
		quicksort(low,i-1);
		quicksort(i+1,high);
		
	}
}
int main()
{	int i,n;

	puts("Enter n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{	srand(time(NULL)+i);
		a[i] = rand()%10+1;
	}
	puts("Before sort");
	for(i=0;i<n;i++)
        {
                printf("%d ",a[i]);
        }

	quicksort(0,n-1);
	puts("");
	puts("After sort");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	puts("");
	return 0;
}
