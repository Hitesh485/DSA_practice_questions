#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void printBoard(vector<vector<int>> &board, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j  = 0; j < n; j ++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(vector<vector<int>> &board, int row, int col, int n, unordered_map<int, bool> &checkQueen )
{
    int i = row, j = col;

    auto iter = checkQueen.find(row);
    if (iter == checkQueen.end())
    {
        return false;
    }

    // if (checkQueen[row] == 1)
    // {
    //     return false;
    // }

    // // left diagonal
    // while (j >= 0)
    // {
    //     if (board[i][j] == 1)
    //     {
    //         return false;
    //     }
    //     j--;
    // }

    // // upper left diagonal
    // i = row;
    // j = col;
    // while (i >= 0 && j >= 0)
    // {
    //     if (board[i][j] == 1)
    //     {
    //         return false;
    //     }
    //     i--;
    //     j--;
    // }

    // // lower left diagonal
    // i = row;
    // j = col;
    // while (i < n && j >= 0)
    // {
    //     if (board[i][j] == 1)
    //     {
    //         return false;
    //     }
    //     i++;
    //     j--;
    // }
    return true;
}

void solve(vector<vector<int>> &board, int col, int n, unordered_map<int, bool> &checkQueen)
{
    if (col >= n)
    {
        printBoard(board, n);
        return;
    }

    for (int row = 0; row < n; row++)
    {
        if(isSafe(board, row, col, n, checkQueen))
        {
            // board[row][col] = 1;
            // improvement
            checkQueen.insert({row, true});
            solve(board, col+1, n, checkQueen);
            // backtracking
            // board[row][col] = 0;
            checkQueen.erase(row);
        }
    } 
}

int main ()
{
    int n = 4;
    vector<vector<int>> board(n, vector<int>(n,0));
    int col = 0;
    unordered_map<int, bool> checkQueen;

    solve(board, col, n, checkQueen);
    for (auto iter : checkQueen)
    {
        cout << iter.first << endl;
    }
    return 0;
}