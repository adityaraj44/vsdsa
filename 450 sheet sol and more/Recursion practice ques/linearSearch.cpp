int solve(int arr[], int N, int X, int count)
{
    if (N == 0)
    {
        return -1;
    }

    if (arr[0] == X)
    {
        return count;
    }

    return solve(arr + 1, N - 1, X, count + 1);
}

int search(int arr[], int N, int X)
{
    return solve(arr, N, X, 0);
}