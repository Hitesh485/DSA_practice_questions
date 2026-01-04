#include <iostream>
#include <vector>

using namespace std;

// My logic (different loop)
// bool isSafe(vector<vector<int>> &sudoku, int n, int curr_row, int curr_col, int value)


// Better logic (one loop)
bool isSafe(vector<vector<int>> &sudoku, int n, int row, int col, int value)
{
    // n will be 9.  
    for (int i = 0; i < n; i++)
    {
        // row
        if (sudoku[row][i] == value)
        {
            return false;
        }

        // col
        if (sudoku[i][col] == value)
        {
            return false;
        }

        // 3X3 matrix
        if (sudoku[3*(row/3)+(i/3)][3*(col/3)+(i%3)] == value)
        {
            return false;
        }
    }
    return true;
}



bool solve(vector<vector<int>> &sudoku, int n)
{
    // base case
    // no base case
    // ek case
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (sudoku[i][j] == 0)
            {
                for (int value = 1; value <= 9; value++)
                {
                    if (isSafe(sudoku, n, i, j, value))
                    {
                        sudoku[i][j] = value;
                        bool res = solve(sudoku, n);
                        // ya to ans milega ya no nahi milega
                        // If answer mil gya, then return true no backtracking need ->
                        if (res == true)
                        {
                            return true;
                        }
                        // answer nahi mila
                        // backtrack
                        sudoku[i][j] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int n = 9;
    vector<vector<int>> sudoku(n, vector<int>(n));
    sudoku[0] = {4, 5};
    sudoku[1] = {0, 0, 2, 0, 7, 0, 6, 3, 0};
    sudoku[2] = {0, 0, 0, 0, 0, 0, 0, 2, 8};
    sudoku[3] = {0, 0, 0, 9, 5, 0, 0, 0, 0};
    sudoku[4] = {0, 8, 6, 0, 0, 0, 2, 0, 0};
    sudoku[5] = {0, 2, 0, 6, 0, 0, 7, 5, 0};
    sudoku[6] = {0, 0, 0, 0, 0, 0, 4, 7, 6};
    sudoku[7] = {0, 7, 0, 0, 4, 5, 0, 0, 0};
    sudoku[8] = {0, 0, 8, 0, 0, 9, 0, 0, 0};

    int row = 0, col = 0;

    solve(sudoku, n);

    for (int i = 0; i < sudoku.size(); i++)
    {
        for (int j = 0; j < sudoku.size(); j++)
        {
            cout << sudoku[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}