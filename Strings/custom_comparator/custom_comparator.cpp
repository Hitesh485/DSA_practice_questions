#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool cmp(char first, char second)
{
    return first > second;
}

int main ()
{   
    string str = "hitesh";
    sort(str.begin(), str.end()); // -> ehhist
    sort(str.begin(), str.end(), cmp); // -> tsihhe

    cout << str << endl;
    return 0;
}