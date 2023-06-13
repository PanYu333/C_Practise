/* C program to find Inorder successor in a BST */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *Insert(Node *root, int data);
void Inorder(Node *root);
Node *Getsuccessor(Node *root, int data);

int main()
{
    /*Code To Test the logic
	  Creating an example tree
	            5
			   / \
			  3   10
			 / \   \
			1   4   11
    */
	Node* root = NULL;
	root = Insert(root,5); root = Insert(root,10);
	root = Insert(root,3); root = Insert(root,4); 
	root = Insert(root,1); root = Insert(root,11);

	//Print Nodes in Inorder
    printf("Inoder: ");
    Inorder(root);
    printf("\n");

    Node *nextnode = Getsuccessor(root, 4);
    if (nextnode == NULL)
        printf("No successor Found.");
    else 
        printf("the successor is: %d\n", nextnode->data);
}

Node* GetNewNode(int data) {
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
}

/*Insert Node in a Binary Search Tree.*/
Node* Insert(Node *root, int data) {
    if (root == NULL) {
        root = GetNewNode(data);
    }
    else if (data <= root->data) {
        root->left = Insert(root->left, data);
    }
    else if (data > root->data) {
        root->right = Insert(root->right, data);
    }
    return root;
}

/*Find minimum in a tree.*/
Node* FindMin(Node *root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}


Node* Find(Node *root, int data) {
    if (root == NULL)
        return root;
    if (data == root->data)
        return root;
    else if (data < root->data)
        return Find(root->left, data);
    else
        return Find(root->right, data);
}

/*Find Inorder Successor in a BST.*/
Node* Getsuccessor(Node *root, int data) { 
    Node *currect = Find(root, data);
    if (currect == NULL)
        return NULL;
    if (currect->right != NULL) {
        return FindMin(currect->right);
    }
    else {
        Node *successor = NULL;
        Node *ancestor = root;
        while (currect != ancestor) {   // The successor will only be the parent node or grandparent
            if (currect->data < ancestor->data) {
                successor = ancestor;
                ancestor = ancestor->left;
            }
            else {
                ancestor = ancestor->right;
            }
        }
        return successor;
    }
}

/*visit nodes in Inorder.*/
void Inorder(Node *root) {
    if (root == NULL)
        return;
    Inorder(root->left);
    printf("%d ", root->data);
    Inorder(root->right);
}