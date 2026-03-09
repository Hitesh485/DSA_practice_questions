#include <iostream>
#include <stack>

using namespace std;

class Solution
{
public:
    void validParanthesis(stack<char> &st, string &s)
    {
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '{')
                st.push('{');
            else
            {
                if (!st.empty() && st.top() == '{')
                {
                    st.pop();
                }
                else
                {
                    st.push('}');
                }
            }
        }
    }

    int countMinReversals(string s)
    {
        // code here
        // if s size is odd then return -1;
        if (s.size() & 1)
            return -1;

        stack<char> st;
        validParanthesis(st, s);

        int count = 0;
        while (!st.empty())
        {
            // case 1. same char '(('
            char ch1 = st.top();
            st.pop();
            char ch2 = st.top();
            st.pop();
            if (ch1 == ch2)
                count += 1;
            else
                count += 2;
        }
        return count;
    }
}; 

int main()
{

    return 0;
}