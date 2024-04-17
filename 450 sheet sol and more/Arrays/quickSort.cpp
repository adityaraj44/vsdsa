// Time complexity O(nlogn)
//  S.C O(N)
void quickSort(int arr[], int low, int high)
{
    // base case
    if (low >= high)
    {
        return;
    }

    int p = partition(arr, low, high);
    quickSort(arr, low, p - 1);
    quickSort(arr, p + 1, high);
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int count = 0;
    for (int i = low + 1; i <= high; i++)
    {
        if (arr[i] <= pivot)
        {
            count++;
        }
    }
    // place pivot at right pos
    int pivotIndex = low + count;
    swap(arr[pivotIndex], arr[low]);

    // left and right part
    int i = low, j = high;
    while (i < pivotIndex && j > pivotIndex)
    {
        if (arr[i] <= pivot)
        {
            i++;
        }
        else if (arr[j] > pivot)
        {
            j--;
        }
        else
        {
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}