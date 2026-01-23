#include <iostream>
#include <vector>

// Leetcode  - 2

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        data = 0;
        next = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList
{
    Node *head = NULL;

public:
    LinkedList()
    {
        head = NULL;
    }

    void insertAtHead(int data)
    {
        Node *newNode = new Node(data);

        if (head == NULL)
        {
            head = newNode;
            return;
        }

        newNode->next = this->head;
        this->head = newNode;
    }

    void insertNode(vector<int> &arr)
    {

        if (head == NULL)
        {
            int data = arr[0];
            insertAtHead(data);
        }

        // we must use start from arr[1].
        for (int i = 1; i < arr.size(); i++)
        {
            Node *newNode = new Node(arr[i]);
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newNode;
            newNode = temp;
        }
    }

    void print()
    {
        Node *temp = head;
        if (head == NULL)
            cout << "List is empty" << endl;

        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Destructor
    ~LinkedList()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            Node *nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
        head = NULL;
    }
};

int main()
{
    // LinkedList l1 = LinkedList(10);
    // l1.print();

    LinkedList *list = new LinkedList();
    // list->insertAtHead(10);
    // list->insertAtHead(20);
    // list->insertAtHead(30);
    // list->insertAtHead(40);

    LinkedList *l2 = new LinkedList();

    vector<int> arr = {10, 20, 30, 40, 50, 80};

    l2->insertNode(arr);

    l2->print();

    delete l2;

    return 0;
}

/*
#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // singly linked list
    Node()
    {
        this->data = 0;
        this->next = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};


void print(Node* &head)
{
    Node* temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Node insert at head
void insertAtHead(Node* &head, int data)
{
    // if linked list is empty

    // create node
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

void insertAtTail(Node* &head, int data)
{
    // if linked list is empty

    Node* newNode = new Node(data);

    // traverse till get tail
    Node* temp = head;
    while(temp->next != NULL) // we need temp to stop at node not at NULL
    {
        temp = temp->next;
    }

    // now temp pointer is at last position of linked list
    temp->next = newNode;
    // temp is pointing to last ele, newNode is now equals to temp.
    newNode = temp;
}

void insertAtTailWithLastNode(Node* &tail, int data)
{
    // if linked list is empty


    Node* newNode = new Node(data);
    tail->next = newNode;
    tail = newNode;
}

void insertAtMiddle(Node* &head, int index, int data)
{
    // if linked list is empty



    // if index is 0
    if (index == 0)
    {
        insertAtHead(head, data);
    }


    // insert at middle
    Node* newNode = new Node(data);
    // travse till index
    Node* temp = head;
    index = index - 1; // jha insert krna h uske ek node peeche khada hona padega.
    while (index > 0)
    {
        temp = temp->next;
        index--;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    temp = newNode;
}


int main()
{
    Node *first = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *fourth = new Node(40);

    first->next = second;
    second->next = third;
    third->next = fourth;

    // Node insert at head
    // int data = 100;
    // insertAtHead(first, data);
    // insertAtHead(first, 400);

    // Node insert at tail
    // insertAtTail(first, 45);
    // OR
    // insertAtTailWithLastNode(fourth, 80);

    // Insert at middle
    int index = 4;
    insertAtMiddle(first, index, 2);

    print(first);
    return 0;
}
*/