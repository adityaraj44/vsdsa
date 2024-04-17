bool arraySortedOrNot(int arr[], int n)
{
    // base case
    if (n == 0 || n == 1)
    {
        return true;
    }

    if (arr[0] > arr[1])
    {
        return false;
    }

    return arraySortedOrNot(arr + 1, n - 1);
}