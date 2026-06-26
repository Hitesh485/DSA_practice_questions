#include <iostream>

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

int main()
{
    buildTree();

    return 0;
}