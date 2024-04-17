class Solution
{
public:
    int solve(vector<vector<int>> &matrix, int n, int row, int col, vector<vector<int>> &t)
    {
        if (col < 0 || col >= n)
            return 1e9;
        if (row == 0)
            return matrix[0][col];
        if (t[row][col] != -1)
        {
            return t[row][col];
        }
        return t[row][col] = matrix[row][col] + min(solve(matrix, n, row - 1, col - 1, t), min(solve(matrix, n, row - 1, col, t), solve(matrix, n, row - 1, col + 1, t)));
    }
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int ans = 1e9;
        vector<vector<int>> t(n, vector<int>(n, -1));
        for (int k = 0; k < n; k++)
        {
            ans = min(ans, solve(matrix, n, n - 1, k, t));
        }
        return ans;
    }
};

// tabulation
class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> t(n, vector<int>(m, INT_MAX));
        for (int i = 0; i < m; i++)
        {
            t[0][i] = matrix[0][i];
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (j < 1)
                {
                    t[i][j] = matrix[i][j] + min(t[i - 1][j], t[i - 1][j + 1]);
                }
                else if (j == m - 1)
                {
                    t[i][j] = matrix[i][j] + min(t[i - 1][j], t[i - 1][j - 1]);
                }
                else
                {
                    t[i][j] = matrix[i][j] + min(t[i - 1][j], min(t[i - 1][j - 1], t[i - 1][j + 1]));
                }
            }
        }
        int ans = INT_MAX;
        for (int i = 0; i < m; i++)
        {
            ans = min(ans, t[n - 1][i]);
        }
        return ans;
    }
};

// optional space optimization
class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        // vector<vector<int>> t(n, vector<int>(m, 0));
        vector<int> prev(m, 0);
        for (int i = 0; i < m; i++)
        {
            prev[i] = matrix[0][i];
        }
        vector<int> curr(m, 0);
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (j < 1)
                {
                    curr[j] = matrix[i][j] + min(prev[j], prev[j + 1]);
                }
                else if (j == m - 1)
                {
                    curr[j] = matrix[i][j] + min(prev[j], prev[j - 1]);
                }
                else
                {
                    curr[j] = matrix[i][j] + min(prev[j], min(prev[j - 1], prev[j + 1]));
                }
            }
            prev = curr;
        }
        int ans = INT_MAX;
        for (int i = 0; i < m; i++)
        {
            ans = min(ans, prev[i]);
        }
        return ans;
    }
};