//SelectionSort

#include<stdio.h>
void Selection(int a[],int n);
int main()
{
	int i,a[50],n;
	printf("Enter number of elements : ");
	scanf("%d",&n);
	
	printf("Enter array elements : ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	Selection(a,n);
	return 0;	
}

void Selection(int a[],int n)
{
	int i,j,imin;
	
	for(i=0;i<n-1;i++)
	{
		imin=i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[imin])
			{
				imin=j;
			}
		}
		int temp;
		temp=a[i];
		a[i]=a[imin];
		a[imin]=temp;
	}
	printf("\nSorted Array(using selection sort) : ");
	for(i=0;i<n;i++)
	{
	    printf("%d ",a[i]);
	    
	}		
	
}
