
#include <stdio.h>
#include<stdlib.h>

struct bst{
    int data ;
    struct node *left,
	struct node *right;
};


struct bst *pre(struct bst * root){
    if(root==0){
        return 0;
    }
    printf("%d",root->data);
    pre(root->left);
    pre(root->right);
}

struct bst *in(struct bst * root){
    if(root==0){
        return 0;
    }
    in(root->left);
    printf("%d",root->data);
    in(root->right);
}

struct bst *post(struct bst * root){
    if(root==0){
        return 0;
    }
    post(root->left);
    post(root->right);
    printf("%d",root->data);
}

struct bst *create(){
    int x;
    struct bst * newnode = (struct bst*)malloc(sizeof(struct bst));
    printf("Enter data : ");
    scanf("%d",&x);
    if(x == -1){
        return 0;
    }
    newnode->data = x;
    printf("Enter left child of %d",x);
    newnode->left = create();
    printf("Enter right child of %d",x);
    newnode->right = create();
    return newnode;
}


int main() {
    int option=0;
    
    struct bst * root;
    while(option!=5){
    	printf("\nEnter your option : ");
    	scanf("%d",&option);
    	printf("Option 1 Create \nOption 2 Inorder \nOption 3 Preorder \nOption 4 Postorder \Option 5 Quit \n");
        switch(option){
            case 1:
               root = create();
               break;
            case 2:
            	//In-order Traversal
               root = in(root);
               break;
            case 3:
            	//Pre-order Traversal
			   root = pre(root);
               break;
            case 4:
            	//Post-order Traversal
               root = post(root);
               break;
            case 5:
               break;
               
            default:
            	printf("No such option!");
        }
    }
    
    return 0;
}
