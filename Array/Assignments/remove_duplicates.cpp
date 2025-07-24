#include <iostream>
#include <vector>

using namespace std;

void removeDuplicates(vector<int> &arr)
{
    // without using any data structures
    
}

int main()
{
    vector<int> arr = {12, 34, 45, 12, 34, 65};

    removeDuplicates(arr);

    for (auto it : arr)
    {
        cout<< it << ", ";
    }
    cout << endl;

    return 0;
}