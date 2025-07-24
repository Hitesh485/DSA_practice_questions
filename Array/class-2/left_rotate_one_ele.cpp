#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<int> &arr)
{
    // code here
    for (int i = arr.size() - 1; i > 0; i--)
    {
        swap(arr[i], arr[i - 1]);
    }
}

int main()
{

    return 0;
}