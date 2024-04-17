int search(int arr[], int start, int end, int target)
{

    if (start > end)
    {
        return -1;
    }
    int mid = start + (end - start) / 2;
    if (arr[mid] == target)
    {
        return mid;
    }

    else if (arr[mid] < target)
    {
        return search(arr, mid + 1, end, target);
    }
    else
    {
        return search(arr, start, mid - 1, target);
    }
}

int binarysearch(int arr[], int n, int k)
{
    int start = 0;
    int end = n - 1;

    int ans = search(arr, start, end, k);
    return ans;
}