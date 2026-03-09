#include <iostream>
#include <queue>

using namespace std;

int main ()
{
    queue<int> q;

    q.push(5);
    q.push(10);
    q.push(2);
    q.push(300);

    cout << q.size() << endl;

    while (!q.empty())
    {
        cout<< q.front() << " ";
        q.pop();
    }
    cout << endl;
    return 0;
}