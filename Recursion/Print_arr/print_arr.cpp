#include <iostream>

using namespace std;

void print(int arr[], int n)
{
    if (n <= 0)
    {
        return;
    }
    print(arr, n-1);
    cout << arr[n-1] << " ";
}

int main ()
{
    int arr[] = {10,20,30,40};
    int n = sizeof(arr)/sizeof(int);
    print(arr, n);
    return 0;
}