#include <vector>

int solve(vector<int> &price, int n, int index, vector<vector<int>> &t)
{

    if (index == 0)
        return n * price[0];
    if (t[index][n] != -1)
        return t[index][n];
    int notTake = solve(price, n, index - 1, t);
    int take = INT_MIN;
    int rodLen = index + 1;
    if (rodLen <= n)
    {
        take = price[index] + solve(price, n - rodLen, index, t);
    }

    return t[index][n] = max(take, notTake);
}

int cutRod(vector<int> &price, int n)
{
    vector<vector<int>> t(n, vector<int>(n + 1, -1));
    return solve(price, n, n - 1, t);
}
