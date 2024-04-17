#include <bits/stdc++.h>

bool isSafe(int row, int col, vector<vector<int>> &board, int val, int n)
{
    for (int i = 0; i < n; i++)
    {
        // row check
        if (board[row][i] == val)
        {
            return false;
        }

        // col check
        if (board[i][col] == val)
        {
            return false;
        }

        // 3*3 check
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val)
        {
            return false;
        }
    }
    return true;
}

bool solve(vector<vector<int>> &board)
{
    int n = board[0].size();
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (board[row][col] == 0)
            {
                for (int val = 1; val <= 9; val++)
                {
                    if (isSafe(row, col, board, val, n))
                    {
                        board[row][col] = val;

                        bool nextSolution = solve(board);
                        if (nextSolution)
                        {
                            return true;
                        }
                        else
                        {
                            board[row][col] = 0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solveSudoku(vector<vector<int>> &sudoku)
{
    solve(sudoku);
}