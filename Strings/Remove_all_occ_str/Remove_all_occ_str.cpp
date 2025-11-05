#include <iostream>
#include <string>

using namespace std;

// create find and erase function by yourself -> 

string removeOccurrences(string s, string part)
{
    int pos = s.find(part);
    while (pos != string::npos)
    {
        s.erase(pos, part.length());
        pos = s.find(part);
    }
    return s;
}

int main()
{
    string s = "daabcbaabcbc", part = "abc";
    // strings = "axxxxyyyyb", part = "xy";
    cout << removeOccurrences(s, part) << endl;
    return 0;
}