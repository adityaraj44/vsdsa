void bubbleSort(int arr[], int n)
{
    bool swapped = false;
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
        {
            break;
        }
    }
}

// HEre is array is already sorted then O(N)
/*
Time complexity O(N^2)
Space O(1)
*/

// recursive
void sortArray(int *arr, int n)
{
    if (n == 0 || n == 1)
    {
        return;
    }

    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
        }
    }
    sortArray(arr, n - 1);
}