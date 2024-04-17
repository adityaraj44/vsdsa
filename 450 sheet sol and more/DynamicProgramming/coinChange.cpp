// top down - same as knapsack
#include <bits/stdc++.h>
int f(int index, int x, vector<int> &num, vector<vector<int>> &dp)
{
    if (index - 1 == 0)
    {
        if (x % num[0] == 0)
            return x / num[0];
        else
            return int(1e9);
    }
    if (dp[index][x] != -1)
        return dp[index][x];
    if (num[index - 1] <= x)
    {
        return dp[index][x] = min(1 + f(index, x - num[index - 1], num, dp), f(index - 1, x, num, dp));
    }
    return dp[index][x] = 0 + f(index - 1, x, num, dp);
}
int minimumElements(vector<int> &num, int x)
{
    int n = num.size();
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, -1));
    int ans = f(n, x, num, dp);
    if (ans >= 1e9)
        return -1;
    return ans;
}

// bottom up - tabulation
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));
        for (int k = 0; k <= amount; k++)
        {
            if (k % coins[0] == 0)
                dp[0][k] = k / coins[0];
            else
                dp[0][k] = 1e9;
        }
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < amount + 1; j++)
            {
                if (coins[i - 1] <= j)
                {
                    dp[i][j] = min(1 + dp[i][j - coins[i - 1]], dp[i - 1][j]);
                }
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        if (dp[n][amount] == 1e9)
        {
            return -1;
        }
        return dp[n][amount];
    }
};

// space optimised
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<int> prev(amount + 1, 0);
        vector<int> curr(amount + 1, 0);
        for (int k = 0; k <= amount; k++)
        {
            if (k % coins[0] == 0)
                prev[k] = k / coins[0];
            else
                prev[k] = 1e9;
        }
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < amount + 1; j++)
            {
                if (coins[i - 1] <= j)
                {
                    curr[j] = min(1 + curr[j - coins[i - 1]], prev[j]);
                }
                else
                    curr[j] = prev[j];
            }
            prev = curr;
        }
        if (curr[amount] == 1e9)
        {
            return -1;
        }
        return curr[amount];
    }
};