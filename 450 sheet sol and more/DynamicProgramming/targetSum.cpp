int countSubsetSum(vector<int> &arr, int n, int sum)
{
    vector<vector<int>> t(n + 1, vector<int>(sum + 1, 0));
    for (int i = 0; i < sum + 1; i++)
    {
        t[0][i] = 0;
    }
    for (int i = 0; i < n + 1; i++)
    {
        t[i][0] = 1;
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (arr[i - 1] <= j)
            {
                t[i][j] = (t[i - 1][j - arr[i - 1]] + t[i - 1][j]);
            }
            else
            {
                t[i][j] = (t[i - 1][j]);
            }
        }
    }
    return t[n][sum];
}
int findTargetSumWays(vector<int> &nums, int target)
{
    target = abs(target);
    int s_arr = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        s_arr += nums[i];
    }
    if ((s_arr + target) % 2 != 0 || s_arr < target)
        return 0;
    int s1 = (target + s_arr) / 2;
    return countSubsetSum(nums, n, s1);
}