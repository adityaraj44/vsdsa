// recursive and memo
class Solution
{
public:
    int solve_util(int m, int n, vector<vector<int>> &t)
    {
        if (m == 0 && n == 0)
        {
            return 1;
        }
        if (m < 0 || n < 0)
            return 0;
        if (t[m][n] != -1)
        {
            return t[m][n];
        }
        int top = solve_util(m - 1, n, t);
        int left = solve_util(m, n - 1, t);
        return t[m][n] = top + left;
    }
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> t(m, vector<int>(n, -1));
        return solve_util(m - 1, n - 1, t);
    }
};
// tabulation bottom up

class Solution
{
public:
    int uniquePaths(int m, int n)
    {

        vector<vector<int>> t(m, vector<int>(n, 0));
        // base case
        for (int i = 0; i < m; i++)
        {
            t[i][0] = 1;
        }
        for (int i = 0; i < n; i++)
        {
            t[0][i] = 1;
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                t[i][j] = t[i - 1][j] + t[i][j - 1];
            }
        }
        return t[m - 1][n - 1];
    }
};

// space optimization
class Solution
{
public:
    int uniquePaths(int m, int n)
    {

        vector<int> prev(n, 1);

        for (int i = 1; i < m; i++)
        {
            vector<int> curr(n, 1);

            for (int j = 1; j < n; j++)
            {
                curr[j] = prev[j] + curr[j - 1];
            }
            prev = curr;
        }
        return prev[n - 1];
    }
};