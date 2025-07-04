#include <iostream>
#include <vector>

using namespace std;

pair<int, int> count(vector<int> &arr)
{
    pair<int, int> ans;
    int one = 0, zero = 0;
    for (auto i : arr)
    {
        if (i == 0)
        {
            ans.first = ++zero;
        }
        else if (i == 1)
        {
            ans.second = ++one;
        }
    }

    return ans;
}

int main ()
{
    vector<int> arr = {0,0,1,0,1,1,1,0,0};

    // linear search
    pair<int, int> res = count(arr);

    cout << "ans : "  << endl;
    cout << "0 -> "<< res.first << endl;
    cout << "1 -> "<< res.second << endl;

    return 0;
}