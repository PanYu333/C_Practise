/**
 * Binary tree - Level Order Traversal.
 * This time we use the pointer of the pointer to insert the node.
 */

#include <iostream>
#include <queue>
using namespace std;

typedef struct Node {
    char data;
    struct Node* left;
    struct Node* right;
} Node;

class BreadthSearch
{
public:
    Node* root = NULL;

    /*Function to search Nodes in a binary tree in Level order.*/
    string LevelOrder(Node* root) {
        string str = "";
        if (root == NULL)
            return str;

        queue<Node*> Q;     // The queue stores the data address to be retrieved
        Q.push(root);       // Start entering the root node
        while (!Q.empty()) {
            Node* temp = Q.front();
            str += temp->data;
            str += " ";
            if (temp->left != NULL) Q.push(temp->left);
            if (temp->right != NULL) Q.push(temp->right);
            Q.pop();
        }
        return str;
    }

    /*Function to Insert Node in a Binary Search Tree.*/
    void Insert(Node** root, char data) {
        if (*root == NULL) {
            (*root) = new Node;
            (*root)->data = data;
            (*root)->left = (*root)->right = NULL;
        }
        else if (data <= (*root)->data)
            Insert(&(*root)->left, data);
        else
            Insert(&(*root)->right, data);
    }
};

int main()
{
    /*Code To Test the logic
	  Creating an example tree
	            M
			   / \
			  B   Q
			 / \   \
			A   C   Z
    */

    string str = "";
    BreadthSearch BS;
    BS.Insert(&BS.root, 'M'); BS.Insert(&BS.root, 'B');
    BS.Insert(&BS.root, 'Q'); BS.Insert(&BS.root, 'Z');
    BS.Insert(&BS.root, 'A'); BS.Insert(&BS.root, 'C');
    str = BS.LevelOrder(BS.root);
    cout << str << endl;
}