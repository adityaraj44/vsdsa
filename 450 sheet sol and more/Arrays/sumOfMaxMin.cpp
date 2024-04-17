int findSum(int A[], int N)
{
    // code here.

    int max = INT_MIN;
    int min = INT_MAX;
    for (int i = 0; i < N; ++i)
    {
        if (A[i] < min)
        {
            min = A[i];
        }
        if (A[i] > max)
        {
            max = A[i];
        }
    }
    return min + max;
}