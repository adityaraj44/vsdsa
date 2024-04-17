#include <bits/stdc++.h>
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    vector<vector<int>> t(n + 1, vector<int>(maxWeight + 1, 0));

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < maxWeight + 1; j++)
        {
            if (weight[i - 1] <= j)
            {
                // max of include and exclude
                t[i][j] = max(value[i - 1] + t[i - 1][j - weight[i - 1]], t[i - 1][j]);
            }
            else
                t[i][j] = t[i - 1][j];
        }
    }
    return t[n][maxWeight];
}

// space optimised