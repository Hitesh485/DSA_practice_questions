#include <iostream>

using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

Node* buildTree ()
{
    int data;
    cout << "Enter root data: ";
    cin >> data;

    if (data <= -1)
    {
        return NULL;
    }

    Node *root = new Node(data);
    root->left = buildTree();
    root->right = buildTree();

    return root;
}

int maxDepth(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    // ek case
    int leftSubree = maxDepth(root->left);
    int rightSubtee = maxDepth(root->right);

    return 1 + max(leftSubree, rightSubtee);
}

int diameterOfBinaryTree(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int op1 = diameterOfBinaryTree(root->left);
    int op2 = diameterOfBinaryTree(root->right);
    // here +1 is for include root node.
    int op3 = maxDepth(root->left) + maxDepth(root->right) + 1;

    //but we have to remove this +1 elsewhere we getting 1 increment ans.
    // instead remove +1 or this diameter fun copy to another fun and return value and then in this fun put that value - 1;

    int ans = max(op1, max(op2, op3));
    return ans;
}

int main ()
{
    Node *root = buildTree();

    // diameter of tree
    cout << diameterOfBinaryTree(root) << endl;
    return 0;
}