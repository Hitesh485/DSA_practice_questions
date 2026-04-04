#include <iostream>
#include <vector>

using namespace std;

// Recursion -> O(n*k) & O(k)
void rotateClockwise1(vector<int> &arr, int k)
{
    if (k == 0)
        return;

    int n = arr.size();
    if (n == 0)
        return;

    // rotate array to right by 1 position.
    int temp = arr[n - 1]; // store the last ele and loop till n-1 to 1.

    for (int i = n - 1; i > 0; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[0] = temp;
    rotateClockwise1(arr, k - 1);
}

// O(n) & O(n) ->
void rotateClockwise2(vector<int> &arr, int k)
{
    int n = arr.size();

    // handle cases where k > n
    k = k % n;

    // temp vector
    vector<int> temp;

    for (int i = 0; i < n; i++)
    {
        if (i < k)
        {
            // arr[n+i-k] give the last index and (i<k) is for maintain the range.
            temp.push_back(arr[n + i - k]);
        }
        else
        {
            temp.push_back(arr[i-k]);
        }
    }

    // copy ele to main array
    for (int i = 0; i < n; i++)
    {
        arr[i] = temp[i];
    }
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    int k = 2;

    // rotateClockwise1(arr, k);
    rotateClockwise2(arr, k);

    for (auto iter : arr)
    {
        cout << iter << " ";
    }
    cout << endl;
    return 0;
}