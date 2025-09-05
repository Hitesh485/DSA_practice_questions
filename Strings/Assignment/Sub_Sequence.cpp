#include <iostream>
#include <string> 
#include <vector>

using namespace std;

void subseq (string str, int i, string res)
{
    // rec 
    // base case
    if (i >= str.size())
    {
        cout << res << endl;
        return;
    }

    /*
     exclude is at top becaues if include at first we need to pop_back() from string because we first change in output string then same string pass further
     to exlude fun call.
        // exclude
        subseq(str, i+1, res);

        // include
        res += str[i];
        subseq(str, i+1, res);
    */
    
    // include
    res.push_back(str[i]);
    subseq(str, i+1, res);
    res.pop_back();


    // exclude
    subseq(str, i+1, res);

}

int main ()
{       
    string str = "abc";
    string res = "";
    subseq(str, 0, res);
    return 0;
}