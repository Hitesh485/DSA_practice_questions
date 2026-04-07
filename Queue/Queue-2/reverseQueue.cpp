#include <iostream>
#include <queue>

using namespace std;

// 1. using stack

// 2. using recursion
void reverseQueue(queue<int> &q)
{
    if (q.empty())
    {
        return;
    }

    int var = q.front();
    q.pop();
    reverseQueue(q);
    q.push(var);
}

int main ()
{
    queue<int> q;
    q.push(3);
    q.push(6);
    q.push(4);
    q.push(10);
    q.push(23);
    int n = q.size();

    reverseQueue(q);

    for (int i = 0; i < n; i++)
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    return 0;
}   