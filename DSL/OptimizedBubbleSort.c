#include<stdio.h>

void Bubble(int a[],int n);
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
	Bubble(a,n);
	return 0;
}
void Bubble(int a[],int n)
{
	int r=0,i,j;
	for(i=0;i<n-1;i++)
	{
		int flag=0;
		r++;
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				flag=1;
				int temp;
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
		if(flag==0)
		{
			break;
		}
	}
	printf("\nSorted Array(using bubble sort) : ");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\nNumber of passes = %d",r);
}
