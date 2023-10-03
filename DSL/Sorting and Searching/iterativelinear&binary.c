#include<stdio.h>

int lsearch(int l,int a[],int num);
void sort(int l,int a[]);
int bsearch(int l,int a[],int num);

int main()
{
	int i,key,n,arr[100];
	printf("Enter number of elements: ");
	scanf("%d",&n);
	
	printf("\nEnter elements of array: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("Enter number to be found: ");
	scanf("%d",&key);
	
	printf("\nLinear Search\n");	
	int z=lsearch(n,arr,key);
	
	if(z==0)
	{
		printf("Not found.");
	}
	else
	{
		printf("%d found at %d position",key,z+1);
	}
	
	sort(n,arr);
	printf("\nSorted array: ");
	for(int i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	int m=bsearch(n,arr,key);
	
	printf("\n\nBinary Search\n");
	if(m==0)
	{
		printf("Not found.");
	}
	else
	{
		printf("%d found at %d position",key,m+1);
	}
	
}

int lsearch(int l,int a[],int num)
{
	int c=0;
	for(int i=0;i<l;i++)
	{
		if(a[i]==num)
		{
			c++;
			return i;
			break;
		}
	}
	if(c==0)
	{
		return 0;
	}	
}

void sort(int l,int a[])
{
	int i,j;
	for(i=0;i<l-1;i++)
	{
		for(j=0;j<l-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}
int bsearch(int l,int a[],int num)
{
	int s=0,d=0;
	int mid=(s+l)/2;
	while(s<l)
	{
		if(num>a[mid])
		{
			s=mid+1;
			mid=(s+l)/2;
		}
		else if(num<a[mid])
		{
			l=mid;
			mid=(s+l)/2;
		}
		else if(num==a[mid])
		{
			d++;
			return mid;
			break;
		}
	}
	if(d==0)
	{
		return 0;
	}
}
