#include <iostream>
#include <queue>
#include <limits>

using namespace std;

class Node
{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

Node* buildTree()
{
    int data;
    cout << "Enter root node data: " ;
    cin>> data;

    if (data <= -1)
    {
        return NULL;
    }

    Node* root = new Node(data);
    cout << "Enter left " << root->data << " data: " ;
    root->left = buildTree();
    cout << "Enter right " << root->data << " data: " ;
    root->right = buildTree();

    return root;
}

void levelOrderTraversal(Node* root)
{
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node* temp = q.front();
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
            cout << temp->data << " ";
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

int treeHeight(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    // ek case
    int leftSubree = treeHeight(root->left);
    int rightSubtee = treeHeight(root->right);

    return 1 + max(leftSubree, rightSubtee);
}

int main()
{
    Node *root = NULL;
    root = buildTree();

    // level order traversal
    // levelOrderTraversal(root);

    // height -> consider nodes
    cout << treeHeight(root) << endl;
    return 0;
}