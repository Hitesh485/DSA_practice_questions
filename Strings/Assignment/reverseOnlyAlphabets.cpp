#include <iostream>

using namespace std;

bool isChar(char ch)
{
    if ((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122))
    {
        return true;
    }
    return false;
}

string reverseOnlyLetters(string str)
{
    // swap
    int i = 0;
    int j = str.length()-1;

    while (i < j)
    {
        if (isChar(str[i]) && isChar(str[j]))
        {
            swap(str[i], str[j]);
            i++;
            j--;
        }
        else if (!isChar(str[i]))
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    return str;
}

int main ()
{
    
    // string str = "a-bC-dEf-ghIj";
    string str = "Test1ng-Leet=code-Q!";
    cout << reverseOnlyLetters(str) << endl;
    return 0;
}