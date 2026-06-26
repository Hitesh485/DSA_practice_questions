#include <iostream>
#include <queue>
#include <vector>

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
    cout << "Enter data : ";
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }

    // Step A, B & C
    Node *root = new Node(data);

    cout << "Enter data for left part -> " << data << endl;
    root->left = buildTree();
    cout << "Enter data for right part -> " << data << endl;
    root->right = buildTree();

    return root;
}

// Node *buildTree(vector<int> &arr, int i)
// {

//     if (arr[i] == -1)
//     {
//         return NULL;
//     }

//     Node *root = new Node(arr[i]);

//     while (i < arr.size())
//     {
//         cout << "Enter data for left part -> " << arr[i] << endl;
//         i = i+1;
//         root->left = buildTree(arr, i);

//         cout << "Enter data for right part -> " << arr[i] << endl;
//         root->right = buildTree(arr, i);
//     }

//     return root;
// }

void inOrderTraversal(Node *root)
{
    if (root == NULL) return;

    // LNR
    // Left
    inOrderTraversal(root->left);

    // N -> print the node data
    cout<< root->data << " ";

    // R
    inOrderTraversal(root->right);
}

int main()
{
    // vector<int> arr = {10, 60, 80, -1, -1, 20, 70, -1, -1, 40, -1, -1, 30, 50, -1, -1, -1};
    // Node *root = buildTree(arr, 0);
    Node *root = buildTree();
    inOrderTraversal(root);

    return 0;
}