#include <stdio.h>
int a[]={2,3,4,9};
int search=4;
int BinarySearch(int low,int high)
{
	int mid=(low+high)/2;
	if(low<high)
	{
		if(search==a[mid])
			 return mid;
		else
		{
			if(a[mid]<search) return BinarySearch(mid,high);
			else		  return BinarySearch(low,mid);
		}
	}
	return -1;
}
int main()
{
	int pos=BinarySearch(0,3);
	printf("%d",a[pos]);
}
