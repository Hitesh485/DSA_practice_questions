#include <iostream>
#include <string>
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string> strs)
{
    string ans;
    int i = 0;

    while (true) // to exit this loop the curr_ch should be 0;
    {
        char curr_ch = 0;
        for (auto str : strs)
        {
            // check out of bound 
            if (i >= str.size())
            {
                curr_ch = 0;
                break;
            }

            // begin
            if (curr_ch == 0)
            {
                curr_ch = str[i];
            }
            else if (curr_ch != str[i])
            {
                // we got the and and exit both loop by curr_ch = 0
                curr_ch = 0;
                break;
            }
        }
        if (curr_ch == 0)
        {
            // exit while loop
            break; 
        }
        ans.push_back(curr_ch);
        i++;
    }
    return ans;
}

int main ()
{
    vector<string> strs = {"flower", "flow", "flight"};

    cout << longestCommonPrefix(strs) << endl;
    return 0;
}