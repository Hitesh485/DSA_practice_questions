#include <iostream>
#include <string>

// using recursion sol in assignment section

using namespace std;

void subString(string &str)
{
    for (int i = 0; i < str.size(); i++)
    {
        string res = "";
        for (int j = i; j < str.size(); j++)
        {
            res += str[j];
            cout << res  << endl;
        }
        cout << endl;
    }
}

int main ()
{
    string str = "Hunny";
    subString(str);
    return 0;
}