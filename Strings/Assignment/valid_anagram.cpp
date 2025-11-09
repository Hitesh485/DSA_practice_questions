#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool validAnagram(string s, string t)
{
    vector<int> freqTable(256, 0);

    for (int i = 0; i < s.size(); i++)
    {
        int ch = s[i];
        freqTable[ch]++;
    }

    for (int i = 0; i < t.size(); i++)
    {
        int ch = t[i];
        freqTable[ch]--;
    }

    for (auto iter : freqTable)
    {
        if (iter != 0) return false;
    }

    return true;
}

int main()
{
    // string s = "anagram";
    // string t = "nagaram";
    string s = "cat";
    string t = "rat";

    cout << validAnagram(s, t) << endl;

    return 0;
}