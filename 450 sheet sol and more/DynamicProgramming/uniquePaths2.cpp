// top down
class Solution
{
public:
    int solve_util(vector<vector<int>> &obstacleGrid, int row, int col,
                   vector<vector<int>> &t)
    {
        if (row == 0 && col == 0 && obstacleGrid[row][col] != 1)
        {
            return 1;
        }
        if (row >= 0 && col >= 0 && obstacleGrid[row][col] == 1)
            return 0;
        if (row < 0 || col < 0)
            return 0;
        if (t[row][col] != -1)
        {
            return t[row][col];
        }
        return t[row][col] = (solve_util(obstacleGrid, row - 1, col, t) +
                              solve_util(obstacleGrid, row, col - 1, t));
    }
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> t(m, vector<int>(n, -1));
        return solve_util(obstacleGrid, m - 1, n - 1, t);
    }
};

// tabulation
class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        dp[0][1] = 1;
        // this is to make the starting point of t array 1 ( if both dp[0][1] and
        // dp[1][0] is 1 then starting point i.e t[1][1] will be 2. so only either one of them)
        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= n; ++j)
                if (!obstacleGrid[i - 1][j - 1])
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        return dp[m][n];
    }
};