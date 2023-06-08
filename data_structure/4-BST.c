/**
 * Binary Search Tree -Implemention in C
 * Simple program to create a BST of integers and search an element in it. 
 * Also can find the max and min in BST.
*/

#include <stdio.h>
#include <stdlib.h>

//Definition of Node for Binary search tree
typedef struct BSTNode
{
    int data;
    struct BSTNode *left;
    struct BSTNode *right;
} BSTNode;

BSTNode* Insert(BSTNode *root, int data);
char Search(BSTNode *root, int data);
int FindMin(BSTNode *root);
int FindMax(BSTNode *root);

int main()
{
    BSTNode *root = NULL;

    root = Insert(root, 15);
    root = Insert(root, 10);
    root = Insert(root, 20);
    root = Insert(root, 30);
    root = Insert(root, 5);

    int number;
    printf("Enter a number be searched: ");
    scanf("%d", &number);
    if (Search(root, number))
        printf("Found.\n");
    else
        printf("No Found.\n");

    int max = FindMax(root);
    int min = FindMin(root);
    printf("Max number is : %d, Min number is : %d\n", max, min);

}

/*Function to create a new Node in heap.*/
BSTNode* GetNewNode(int data) 
{
    BSTNode *temp = (BSTNode *)malloc(sizeof(BSTNode));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

/*To insert data in BST, returns address of root node */
BSTNode* Insert(BSTNode *root, int data) 
{
    if (root == NULL) {
        root = GetNewNode(data);
    }
    else if (data <= root->data) {
        root->left = Insert(root->left, data);
    }
    else {
        root->right = Insert(root->right, data);
    }
    return root;
}

/*To search an element in BST, returns true if element is found.*/
char Search(BSTNode *root, int data)
{
    if (root == NULL)
        return 0;
    else if (data == root->data)
        return 1;
    else if (data < root->data) {
        return Search(root->left, data);
    }
    else {
        return Search(root->right, data);
    }
}

/*Find the minimum in BST*/
int FindMin(BSTNode *root) 
{
    if (root == NULL) {
        return -1;
    }
    else if (root->left == NULL) {
        return root->data;
    }
    return FindMin(root->left);
}

/*Find the maximum in BST*/
int FindMax(BSTNode *root) 
{
    if (root == NULL) {
        return -1;
    }
    else if (root->right == NULL) {
        return root->data;
    }
    return FindMax(root->right);
}