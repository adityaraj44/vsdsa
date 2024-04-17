bool isPossible(int arr[], int N, int M, long long mid)
{
    int painters = 1;
    long long boardsPainted = 0;

    for (int i = 0; i < N; i++)
    {
        if (boardsPainted + arr[i] <= mid)
        {
            boardsPainted += arr[i];
        }
        else
        {
            painters++;
            if (painters > M || arr[i] > mid)
            {
                return false;
            }
            boardsPainted = arr[i];
        }
    }
    return true;
}

// Function to find minimum number of time.

long long minTime(int arr[], int n, int k)
{
    // code here
    // return minimum time

    long long start = 0;
    long long sum = 0;
    for (int i = 0; i < n; ++i)
    {
        sum += arr[i];
    }
    long long end = sum;
    long long ans = -1;
    long long mid = start + (end - start) / 2;
    while (start <= end)
    {
        if (isPossible(arr, n, k, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }
    return ans;
}