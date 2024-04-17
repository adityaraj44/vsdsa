int mod = 1e9 + 7;

private:
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
                t[i][j] = (t[i - 1][j - arr[i - 1]] + t[i - 1][j]) % mod;
            }
            else
            {
                t[i][j] = (t[i - 1][j]);
            }
        }
    }
    return t[n][sum];
}

public:
int countPartitions(int n, int d, vector<int> &arr)
{

    int s_arr = 0;
    for (int i = 0; i < n; i++)
    {
        s_arr += arr[i];
    }
    if ((s_arr + d) % 2 != 0 || s_arr < d)
        return 0;
    int s1 = (d + s_arr) / 2;
    return countSubsetSum(arr, n, s1);
}