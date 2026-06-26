#include <iostream>
#include <queue>
#include <limits>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

Node *buildTree()
{
    int data;
    cout << "Enter root node data: ";
    cin >> data;

    if (data <= -1)
    {
        return NULL;
    }

    Node *root = new Node(data);
    cout << "Enter left " << root->data << " data: ";
    root->left = buildTree();
    cout << "Enter right " << root->data << " data: ";
    root->right = buildTree();

    return root;
}

// int treeHeight(Node *root)
// {
//     if (root == NULL)
//     {
//         return 0;
//     }

//     // ek case
//     int leftSubree = treeHeight(root->left);
//     int rightSubtee = treeHeight(root->right);

//     return 1 + max(leftSubree, rightSubtee);
// }

int treeHeight(Node *root)
{
    if (root == NULL) return 0;

    int LH = treeHeight(root->left);
    int RH = treeHeight(root->right);

    return max(LH, RH) + 1;
}

    int main()
{
    Node *root = NULL;
    root = buildTree();

    // height -> consider nodes
    cout << treeHeight(root) << endl;
    return 0;
}