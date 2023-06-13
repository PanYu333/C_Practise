/* Deleting a node from Binary search tree. */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *Insert(Node *root, int data);
Node *Delete(Node *root, int data);
void Inorder(Node *root);

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

	// Deleting node with value 5, change this value to test other cases
	root = Delete(root,5);

	//Print Nodes in Inorder
    printf("Inoder: ");
    Inorder(root);
    printf("\n");
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

/*Delete a Node in BST. */
Node* Delete(Node *root, int data) {
    if (root == NULL)
        return root;

    if (data < root->data) {
        root->left = Delete(root->left, data);
    }
    else if (data > root->data) {
        root->right = Delete(root->right, data);
    }
    else {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            root = NULL;
        }

        else if (root->left == NULL) {
            Node *temp = root;
            root = root->right;
            free(temp);
        }
        else if (root->right == NULL) {
            Node *temp = root;
            root = root->left;
            free(temp);
        }
        else {
            Node *temp = FindMin(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }
    }
    return root;
}

/*visit nodes in Inorder.*/
void Inorder(Node *root) {
    if (root == NULL)
        return;
    Inorder(root->left);
    printf("%d ", root->data);
    Inorder(root->right);
}