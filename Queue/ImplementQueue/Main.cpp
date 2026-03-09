#include <iostream>
#include <vector>

using namespace std;

class Queue
{
public:
    vector<int> queue;
    int front;
    int rear;
    int data;
    int queueSize;

    Queue(int n)
    {
        queueSize = n;
        queue.resize(n);
        front = 0;
        rear = 0;
        data = -1;
    }

    bool isFull()
    {
        if (rear == queueSize)
        {
            return true;
        }
        return false;
    }

    bool isEmpty()
    {
        if (front == rear)
        {
            return true;
        }
        return false;
    }

    void push(int data)
    {
        if (!isFull())
        {
            // insert
            queue[rear] = data;
            rear++;
        }
        else
        {
            cout << "Queue is full" << endl;
            return;
        }
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }

        queue[front] = -1;
        front++;
        if (front == rear)
        {
            front = rear = 0;
        }
    }

    int getFront()
    {
        if (!isEmpty())
        {
            return queue[front];
        }
        cout << "Queue is empty";
        return -1;
    }

    int size()
    {
        return rear - front;
    }

};

int main()
{
    Queue q(5);
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    cout << q.size() << endl;

    while (!q.isEmpty())
    {
        cout << q.getFront() << " ";
        q.pop();
    }

    cout << endl;

    return 0;
}