bool subsetSum(int arr[], int n, vector<vector<int>> &t, int target)
{

    for (int j = 0; j < target + 1; j++)
    {
        t[0][j] = 0;
    }
    for (int i = 0; i < n + 1; i++)
    {
        t[i][0] = 1;
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 0; j < target + 1; j++)
        {
            if (arr[i - 1] <= j)
            {
                t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j];
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    return t[n][target];
}

int minDifference(int arr[], int n)
{

    int range = 0;
    for (int i = 0; i < n; i++)
    {
        range += arr[i];
    }
    vector<vector<int>> t(n + 1, vector<int>(range + 1, 0));
    subsetSum(arr, n, t, range);
    int mn = INT_MAX;
    for (int i = 0; i <= (range) / 2; i++)
    {
        if (t[n][i] == 1)
        {
            mn = min(mn, abs((range - i) - i));
        }
    }
    return mn;
}