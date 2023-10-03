//Recursive


#include<stdio.h>
#include<stdlib.h>

int reclinear(int arr[],int index,int key);

int main()
{
	int z,i,n,key,a[50];
	
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
	z=reclinear(a,index,key);
	
	if(z==-1)
	{
		printf("Element not found.");
	}
	else
	{
		printf("Found at %d position",z+1);
	}
	

}


int reclinear(int arr[],int index,int key)
{
	int arrlength;
	arrlength=5;
	
	if(index>arrlength)
	{
		return -1;
	}
	
	if(arr[index]==key)
	{
		return index;
	}
	
	else
	{
		return reclinear(arr,index+1,key);
	}
}
