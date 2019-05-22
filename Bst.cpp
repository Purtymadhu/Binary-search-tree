#include<stdio.h>//Binary search Tree with inorder traversal;
#include<stdlib.h>
  
struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int value){
    struct node* newNode =(struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}
  
  
struct node* insert(struct node* root, int data)
{
    if (root == NULL) return createNode(data);

    if (data < root->data)
        root->left  = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);   
 
    return root;
}

void inorder(struct node* root){
    if(root == NULL) return;
    inorder(root->left);
    printf("\n%d\n ->", root->data);
    inorder(root->right);
}
bool Search(struct node* root ,int data) {
	if(root == NULL) {
		return false;
	}
	else if(root->data == data) {
		return true;
	}
	else if(data <= root->data) {
		return Search(root->left,data);
	}
	else {
		return Search(root->right,data);
	}
}

int main(){
    struct node *root = NULL;
    root = insert(root, 8);
    insert(root, 3);
    insert(root, 1);
    insert(root, 6);
    insert(root, 7);
    insert(root, 10);
    insert(root, 14);
    insert(root, 4);

    inorder(root);
    
    	int number;
	printf("%s","Enter number be searched\n");
	scanf("%d",&number);
	if(Search(root,number) == true) 
	{
		printf("%s","FOUND");
	}
	else
	{
		printf("%s","NOT FOUND");
	}
}
