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

struct node* iterinsert(struct node *root, int x)
{
    struct node *temp = root;
    struct node *new_node;

    if (root == NULL)
    {
        return newnode(x);
    }
    
    while (temp != NULL)
    {
        if (x > temp->data)
        {
            if (temp->right == NULL)
            {
                temp->right = newnode(x);
                break;
            }
            else
            {
                temp = temp->right;
            }
        }
        else
        {
            if (temp->left == NULL)
            {
                temp->left = newnode(x);
                break;
            }
            else
            {
                temp = temp->left;
            }
        }
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


//we get root with min value of right subtree
struct node* getRightMin(struct node *root)
{
	struct node *temp=root;
	root=root->right;
	
	while(root->left!=NULL){
		root=root->left;
	}	
	return root;
}

void bfs(struct node *root)
{
	
}
//3 cases
struct node* del(struct node *root,int x)
{
	if(root==NULL)
	{
		return NULL;
	}
	//first we traverse till x node
	
	else if(x>root->data)
	{
		root->right=del(root->right,x);
	}
	else if(x<root->data)
	{
		root->left=del(root->left,x);
	}
	
	else{//i.e root->data==x
		//case 1: leaf node
		if(root->left==NULL && root->right==NULL)
		{
			free(root);
			return NULL;
		}
		
		//case 2: one child
		else if(root->left==NULL)
		{
			struct node *temp=root->right;
			free(root);
			return temp;
		}
		
		else if(root->right==NULL)
		{
			struct node *temp=root->left;
			free(root);
			return temp;
		}
		
		//case 3: two child
		//taking right subtree
		else{
			struct node *temp=root;
			temp=getRightMin(root);
			
			root->data=temp->data;
			root->right=temp->right;
			root->right=del(root->right,temp->data);
			free(temp);
		}
		//in this method, we first get the min of right subtree
		//then we replace min->data with root->data
		//then proceed to delete root->right with min->data(recursion) value which falls into one of the three cases
		//
		
		//same can be done with max of left subtree
		
	}
	return root;  //important
}


int main()
{
	int choice=0;
	struct node *root=NULL;
	while(choice!=7)
	{
		printf("\n\nMenu\nEnter 1 to Iterative insert\nEnter 2 to insert child\nEnter 3 to delete child\nEnter 4 Preorder Traversal\nEnter 5 Inorder traversal\nEnter 6 PostOrder Traversal\nEnter 7 to Exit\n");
		printf("\nEnter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:{
				printf("How many nodes do you wish to enter : ");
				int n;
				scanf("%d",&n);
				int i,a[n];
				printf("Enter values of nodes : ");
				for(i=0;i<n;i++)
				{
					scanf("%d",&a[i]);
					root=iterinsert(root,a[i]);
				}
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
				printf("Enter element to be deleted : ");
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
