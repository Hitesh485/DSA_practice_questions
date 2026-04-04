// 28. Find the Index of the First Occurrence in a String

#include <iostream>

using namespace std;

int strStr(string s1, string s2)
{
    return s1.find(s2);
}

// find implementation ->
int strStr2(string s1, string s2)
{
    // approach 2
    if (s1.size() < s2.size())
    {
        return -1;
    }

    for (int i = 0; i <= s1.length() - s2.length(); i++)
    {
        if (s1.substr(i, s2.length()) == s2)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    string str1 = "sadbutsad", str2 = "sad";
    // cout  << strStr(str1, str2) << endl;
    cout << strStr2(str1, str2) << endl;
    return 0;
}