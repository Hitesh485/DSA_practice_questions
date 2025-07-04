#include <iostream>

using namespace std;

int main()
{
    int arr[] = {12, 3, 4, 434, 32, 257};
    int n = sizeof(arr) / sizeof(int);

    int ele = 4348;
    bool res = false;
    for (auto i : arr)
    {
        if (ele == i)
        {
            res = true;
            break;
        }
    }
    (res) ? cout << "Found " << endl : cout << "Not Found ";
    cout << endl;
    return 0;
}