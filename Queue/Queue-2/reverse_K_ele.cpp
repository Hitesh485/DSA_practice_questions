#include <iostream>
#include <queue>
#include <stack>

using namespace std;

// using stack and new queue

void reverseKEle(queue<int> q, queue<int> &ans, stack<int> &st, int k)
{
    // iterative approach

    // push into stack k ele
    while (k--)
    {
        st.push(q.front());
        q.pop();
    }

    // insert ele into ans queue
    while (!st.empty())
    {
        int ele = st.top();
        ans.push(ele);
        st.pop();
    }

    while (!q.empty())
    {
        ans.push(q.front());
        q.pop();
    }
}

// constant space
void reverseKEle2(queue<int> &q, int k)
{
    int n = q.size();
    stack<int> st;
    int count = 0;

    while (count != k)
    {
        int temp = q.front();
        q.pop();
        st.push(temp);
        count++;
    }

    // 2. stack ele q mai wapas
    while (!st.empty())
    {
        int ele = st.top();
        st.pop();
        q.push(ele);
    }

    // 3. push n-k ele to queue front to back
    // separate n-k ele at front end push at back
    count = 0;

    while (n-k != count)
    {
        int temp = q.front();
        q.pop();
        q.push(temp);
        count++;
    }
    
}

// recursive solution
// void reverseKEleRecursive(queue<int> q, queue<int> &ans, stack<int> &st, int k)
// {
//     // base case
//     if (q.empty())
//     {
//         return;
//     }

//     st.push(q.front());
//     q.pop();
//     k--;

//     ans.push(q.front());
//     q.pop();
//     reverseKEleRecursive(q, ans, st, k);
// }

int main()
{
    int k = 4;
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    int n = q.size();

    queue<int> ans;
    stack<int> st;

    reverseKEle2(q, k);
    // reverseKEleRecursive(q, ans, st, k);


    // reverseKEle2 ->
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}