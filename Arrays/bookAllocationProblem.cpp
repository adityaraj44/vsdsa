bool isPossible(int arr[], int N, int M, int mid)
{
    int studentCount = 1;
    int pageSum = 0;

    for (int i = 0; i < N; i++)
    {
        if (pageSum + arr[i] <= mid)
        {
            pageSum += arr[i];
        }
        else
        {
            studentCount++;
            if (studentCount > M || arr[i] > mid)
            {
                return false;
            }
            pageSum = arr[i];
        }
    }
    return true;
}

int findPages(int A[], int N, int M)
{
    if (M > N)
        return -1;
    int start = 0;
    int sum = 0;
    for (int i = 0; i < N; ++i)
    {
        sum += A[i];
    }
    int end = sum;
    int ans = -1;
    int mid = start + (end - start) / 2;
    while (start <= end)
    {
        if (isPossible(A, N, M, mid))
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
