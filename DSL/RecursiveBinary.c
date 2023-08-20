#include<stdio.h>
#include<stdlib.h>
int recbinary(int arr[],int l,int h,int key);
void sort(int l,int a[]);

int main()
{
	int x,i,n,key,a[50];
	
	printf("Enter number of elements: ");
	scanf("%d",&n);
	
	printf("Enter elements of array: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Enter element to be found : ");
	scanf("%d",&key);
	int index=0;

	
	sort(n,a);
	
	printf("\nAfter sorting\n");
	int l=0;
	x=recbinary(a,l,n,key);
	if(x==-1)
	{
		printf("Element not found");
	}
	else
	{
		printf("Element found at position : %d",x+1);
	}
	return 0;
}


void sort(int l,int a[])
{
	int i,j;
	for(i=0;i<l-1;i++)
	{
		for(j=0;j<l;j++)
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

recbinary(int arr[],int l,int h,int key)
{
	if(l<h)
	{
		int mid;
		mid=(l+h)/2;
		if(arr[mid]<key)
		{
			return recbinary(arr,l,mid-1,key);
		}
		if(arr[mid]>key)
		{
			return recbinary(arr,mid+1,h,key);
		}
		if(arr[mid]==key)
		{
			return mid;
		}
	}
	else{
		return -1;
	}
	
}
