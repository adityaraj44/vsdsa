// simple recursive solution
// may give tle
int minCost(int[] cost, int n)
{
    if (n < 0)
        return 0;
    if (n == 0 || n == 1)
        return cost[n];
    return cost[n] + Math.min(minCost(cost, n - 1), minCost(cost, n - 2));
}

int minCostClimbingStairs(int[] cost)
{
    int n = cost.length;
    return Math.min(minCost(cost, n - 1), minCost(cost, n - 2));
}
// top down

int solve(vector<int> &cost, int n, vector<int> &t)
{
    // base case
    if (n <= 1)
    {
        return cost[n];
    }
    if (t[n] != -1)
    {
        return t[n];
    }

    return t[n] = cost[n] + min(solve(cost, n - 1, t), solve(cost, n - 2, t));
}

int minCostClimbingStairs(vector<int> &cost)
{
    int n = cost.size();
    vector<int> t(n + 1, -1);
    int ans = min(solve(cost, n - 1, t), solve(cost, n - 2, t));
    return ans;
}

// bottom up - tabulation
int solve(vector<int> &cost)
{
    int n = cost.size();
    vector<int> t(n + 1, -1);
    t[0] = cost[0];
    t[1] = cost[1];

    for (int i = 2; i < n; i++)
    {
        t[i] = cost[i] + min(t[i - 1], t[i - 2]);
    }

    return min(t[n - 1], t[n - 2]);
}
 
int minCostClimbingStairs(vector<int> &cost)
{
    return solve(cost);
}

// space optimised
int minCostClimbingStairs(vector<int> &cost)
{
    int n = cost.size();
    int prev2 = cost[0];
    int prev1 = cost[1];
    for (int i = 2; i < n; i++)
    {
        int curr = cost[i] + min(prev1, prev2);
        prev2 = prev1;
        prev1 = curr;
    }
    return min(prev1, prev2);
}

