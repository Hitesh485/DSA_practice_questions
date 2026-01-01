#include <iostream>
#include <vector>

using namespace std;

void permutation(string &str, int i )
{
    
    if (i >= str.size())
    {
        cout << str << endl;
        return;
    }

    for (int j = i; j < str.size(); j++)
    {
        swap(str[i], str[j]);
        permutation(str, i+1);\
        // backtracking -> refer notes for understand concept of backtracking.
        swap(str[i], str[j]);
    } 
}

int main ()
{
    string str = "abc";
    int i = 0;
    permutation(str, i);

    return 0;
}