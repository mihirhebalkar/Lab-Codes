#include<stdio.h>
#define V 4


void init(int arr[V][V])
{
	int i,j;
	for(i=0;i<V;i++)
	{
		for(j=0;j<V;j++)
		{
			arr[i][j]=0;
		}
	}
}

void addEdge(int arr[V][V])
{
	int i,j,w;
	printf("Enter vertices of edge : ");
	scanf("%d %d",&i,&j);
	printf("Enter weight : ");
	scanf("%d",&w);
	arr[i][j]=w;
	arr[j][i]=w;
}

printMatrix(int arr[V][V])
{
	int i,j;
	for(i=0;i<V;i++)
	{
		printf("\n");
		for(j=0;j<V;j++)
		{
			printf("%d ",arr[i][j]);
		}
	}
}

int main()
{
	int adj[V][V];
	init(adj);
	
	int choice=-1;
	while(choice!=0)
	{
		printf("\nEnter 1 to add Edge\nEnter 2 to print Matrix\nEnter choice : ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:{
				addEdge(adj);
				break;
			}
			
			case 2:{
			    printf("Adjacency Matrix :	");
				printMatrix(adj);
				break;
			}
		}
		
		
	}
	return 0;
}
