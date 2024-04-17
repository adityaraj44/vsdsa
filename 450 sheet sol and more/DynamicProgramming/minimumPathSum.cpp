// recursion and memo
class Solution
{
public:
    int solve(vector<vector<int>> &grid, int m, int n, vector<vector<int>> &t)
    {
        if (m == 0 && n == 0)
        {
            return grid[0][0];
        }
        if (m < 0 || n < 0)
            return 1e9;
        if (t[m][n] != -1)
        {
            return t[m][n];
        }

        int up = grid[m][n] + solve(grid, m - 1, n, t);
        int left = grid[m][n] + solve(grid, m, n - 1, t);
        return t[m][n] = min(up, left);
    }
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> t(m, vector<int>(n, -1));
        return solve(grid, m - 1, n - 1, t);
    }
};

// tabulation
class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> t(m, vector<int>(n, 0));
        t[0][0] = grid[0][0];
        for (int i = 1; i < m; i++)
        {
            t[i][0] = t[i - 1][0] + grid[i][0];
        }
        for (int i = 1; i < n; i++)
        {
            t[0][i] = t[0][i - 1] + grid[0][i];
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                t[i][j] = grid[i][j] + min(t[i - 1][j], t[i][j - 1]);
            }
        }
        return t[m - 1][n - 1];
    }
};
