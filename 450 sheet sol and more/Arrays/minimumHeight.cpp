int getMinDiff(int arr[], int n, int k)
{
    sort(arr, arr + n);
    if (n == 1)
        return 0;

    int ans = arr[n - 1] - arr[0];
    int largest = arr[n - 1] - k;
    int smallest = arr[0] + k;

    int mini, maxi;

    for (int i = 1; i < n; i++)
    {

        if (arr[i] - k < 0)
            continue;
        maxi = max(arr[i - 1] + k, largest);
        mini = min(smallest, arr[i] - k);
        ans = min(ans, maxi - mini);
    }

    return ans;
}