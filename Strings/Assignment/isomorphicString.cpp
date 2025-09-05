#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool pairAlreadyExist(char ch)
{

}

bool isIsomorphic(string s, string t)
{
    unordered_map<char, char> mp;

    int i = 0;

    while (i < s.size())
    {
        if (!pairAlreadyExist(s[i]))
        {
            // create mapping
            mp.insert({s[i], t[i]});
        }
    }
}

int main()
{
    string s = "foo";
    string t = "bar";

    cout << isIsomorphic(s, t) << endl;

    return 0;
}