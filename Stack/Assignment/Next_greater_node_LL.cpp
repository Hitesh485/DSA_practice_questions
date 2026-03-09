// Leetcode - 1019

#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    vector<int> nextLargerNodes(ListNode *head)
    {
        vector<int> ll;

        ListNode *temp = head;
        while (temp != NULL)
        {
            ll.push_back(temp->val);
            temp = temp->next;
        }

        vector<int> ans(ll.size(), 0);

        stack<int> st;

        for (int i = 0; i < ll.size(); i++)
        {
            while (!st.empty() && ll[i] > ll[st.top()])
            {
                int indexInStack = st.top();
                st.pop();
                ans[indexInStack] = ll[i];
            }
            st.push(i);
        }
        return ans;
    }
};

int main()
{

    return 0;
}