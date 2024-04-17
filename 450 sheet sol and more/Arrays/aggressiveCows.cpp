bool isPossible(int n, int k, vector<int> &stalls, int mid)
{
    int cowCount = 1;
    int lastPos = stalls[0];

    for (int i = 0; i < n; ++i)
    {
        if (stalls[i] - lastPos >= mid)
        {
            cowCount++;
            if (cowCount == k)
            {
                return true;
            }
            lastPos = stalls[i];
        }
    }
    return false;
}

int solve(int n, int k, vector<int> &stalls)
{
    sort(stalls.begin(), stalls.end());
    int ans = -1;
    int start = 0;

    int maxi = -1;
    for (int i = 0; i < n; ++i)
    {
        maxi = max(maxi, stalls[i]);
    }
    int end = maxi;
    int mid = start + (end - start) / 2;

    while (start <= end)
    {
        if (isPossible(n, k, stalls, mid))
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return ans;
} 