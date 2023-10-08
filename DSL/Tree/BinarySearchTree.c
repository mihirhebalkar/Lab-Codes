#include<stdio.h>
#include<stdlib.h>

//creating a binary search tree
struct node{
	struct node *left, *right;
	int data;
};

//performing basic operations

struct node* newnode(int x)
{
	struct node *temp = malloc(sizeof(struct node));
	temp->data = x;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

struct node* insert(struct node *root, int x)
{
	if(root == NULL)
	{
		return newnode(x);
	}
	else if(x > root->data)
	{
		root->right = insert(root->right, x);
	}
	else if(x <= root->data)
	{
		root->left = insert(root->left, x);
	}
	return root;	
}

struct node* del(struct node *root, int x)
{
	if(root == NULL)
	{
		return NULL;
	}
	else if(x > root->data)
	{
		root->right = del(root->right, x);
	}
	else if(x < root->data)
	{
		root->left = del(root->left, x);
	}
	else
	{
		// Case 1: Node with only one child or no child
		if (root->left == NULL)
		{
			struct node *temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL)
		{
			struct node *temp = root->left;
			free(root);
			return temp;
		}
		// Case 2: Node with two children
	
		struct node* temp = root->right;
		while (temp->left != NULL)
		{
			temp = temp->left;
		}

		root->data = temp->data;

		root->right = del(root->right, temp->data);
	}
	return root;
}

int height(struct node *root)
{
	if(root==NULL)
	{
		return 0;
	}
	else{
		int lh=height(root->left);
		int rh=height(root->right);
	
	    if(rh>lh)
	    {
	    	return (rh+1);
	    }
	    
	    else{
	    	return (lh+1);
	    }
	}
	
}

void pre(struct node *root)
{
	if(root!=NULL){
		printf("%d ",root->data);
		pre(root->left);
		pre(root->right);
	}
}

void in(struct node *root)
{
	if(root!=NULL){
		in(root->left);
		printf("%d ",root->data);
		in(root->right);
	}
}

void post(struct node *root)
{
	if(root!=NULL){
		post(root->left);
		post(root->right);
		printf("%d ",root->data);		
	}
}


int main()
{
	int choice=0;
	struct node *root=NULL;
	while(choice!=7)
	{
		printf("\n\nMenu\nEnter 1 to create BST\nEnter 2 to insert child\nEnter 3 to delete child\nEnter 4 Preorder Traversal\nEnter 5 Inorder traversal\nEnter 6 PostOrder Traversal\nEnter 7 to Exit\n");
		printf("\nEnter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:{
				
				printf("\nEnter value of root node : ");
				int x;
				scanf("%d",&x);
				root=newnode(x);
				break;
			}
			
			case 2:{
				printf("How many nodes do you wish to enter : ");
				int n;
				scanf("%d",&n);
				int i,a[n];
				printf("Enter values of nodes : ");
				for(i=0;i<n;i++)
				{
					scanf("%d",&a[i]);
					root=insert(root,a[i]);
				}
				break;
			}
			
			case 3:{
				int z;
				printf("Enter value of element to be deleted : ");
				scanf("%d",&z);
				root=del(root,z);
				break;
			}
			
			case 4:
				printf("\nPreorder Traversal : ");
				pre(root);
				break;
			
			case 5:
				printf("\nInorder Traversal : ");
				in(root);
				break;
				
			case 6:
				printf("\nPostorder Traversal : ");
				post(root);
				break;
				
			case 7:
				break;
				
			default:
				printf("\nNo such option.");
		}
	}
	
	return 0;
	

}
