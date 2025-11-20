#include <iostream>
#include <string>

// include exclude method ->

// subsequence => with include powerset - 2^n
using namespace std;

void subSequence(string &str, int i, string &ans)
{
    if (i > str.size()-1)
    {
        cout << ans << endl;
        return;
    }
    
    // include
    ans.push_back(str[i]);
    subSequence(str, i+1, ans);
    ans.pop_back();
    
    // exclude
    subSequence(str, i+1, ans);
}

int main ()
{
    string str = "abc";
    string ans = "";
    int i = 0;
    subSequence(str, i, ans);
    return 0;
}