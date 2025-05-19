#include <iostream>
#include <queue>

using namespace std;

// using recursion

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
    cout << "Enter data: ";
    cin >> data;

    // base case
    if (data == -1)
    {
        return NULL;
    }

    // step a,b,c
    // step a-> root node
    // step b-> root->left = rec call
    // step c-> root->right = rec call

    Node *root = new Node(data);

    cout << "left node data of " << root->data << ": ";
    root->left = buildTree();

    cout << "right node data of " << root->data << ": ";
    root->right = buildTree();

    return root;
}

void levelOrderTrav(Node *root)
{
    // Using queue
    queue<Node *> q;

    // initially
    q.push(root);
    q.push(NULL); // at first level only one node, so direct push null.

    while (!q.empty())
    {
        // A
        Node *temp = q.front();
        // B
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            // C
            cout << temp->data << " ";
            // D
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

int main()
{
    // test case:
    // {20, 30, 50, -1, 60, -1, -1, 40, -1, -1, 100, -1, -1};
    Node *n1 = NULL;
    n1 = buildTree();

    // level order traversal ->
    cout << endl;
    levelOrderTrav(n1);
    cout << endl;

    return 0;
}