void addSolution(vector<vector<int>> &ans, vector<vector<int>> &board, int n)
{
    vector<int> temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp);
}

bool isSafe(int row, int col, vector<vector<int>> &board, int n)
{
    int x = row;
    int y = col;

    // for row
    while (y >= 0)
    {
        if (board[x][y] == 1)
        {
            return false;
        }
        y--;
    }

    // for upper diagonal
    x = row;
    y = col;
    while (x >= 0 && y >= 0)
    {
        if (board[x][y] == 1)
        {
            return false;
        }
        y--;
        x--;
    }

    // for  lower diagonal
    x = row;
    y = col;
    while (x < n && y >= 0)
    {
        if (board[x][y] == 1)
        {
            return false;
        }
        y--;
        x++;
    }
    return true;
}

void solve(int col, vector<vector<int>> &ans, vector<vector<int>> &board, int n)
{
    // base case
    if (col == n)
    {
        addSolution(ans, board, n);
        return;
    }

    // solve 1 case
    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, col, board, n))
        {
            // is safe
            board[row][col] = 1;
            solve(col + 1, ans, board, n);
            board[row][col] = 0;
        }
    }
}

vector<vector<int>> solveNQueens(int n)
{
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<int>> ans;

    /*
       here 0 is col number because we are placing queens col wise to col
       gets incremented in every recursive call
    */
    solve(0, ans, board, n);

    return ans;
}