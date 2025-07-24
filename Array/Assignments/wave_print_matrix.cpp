#include <iostream>
#include <vector>

using namespace std;

void wavePrint(vector<vector<int>> &arr)
{

    int rowSize = arr[0].size();
    int colSize = arr.size();


    int i = 0;
    for (int col = 0; col < rowSize; col++)
    {
        int row = i;
        // check odd
        if (!((row + 1) % 2) == 0) // or !(row & 1) -> odd
        {
            for (row = 0; row < colSize; row++)
            {
                cout << arr[row][col] << " ";
            }
        }
        else
        {
            for (row = colSize - 1; row >= 0; row--)
            {
                cout << arr[row][col] << " ";
            }
        }
        i++;
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> arr = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

    wavePrint(arr);
    return 0;
}