// Time complexity O(nlogn)
//  S.C O(N)

void merge(int arr[], int si, int mid, int ei)
{

    int i = si;
    int j = mid + 1;
    int k = 0;
    int size = ei - si + 1;
    // create a dynamic array
    int *output = new int[size];
    while (i <= mid && j <= ei)
    {
        if (arr[i] < arr[j])
        {
            output[k++] = arr[i++];
        }
        else
        {
            output[k++] = arr[j++];
        }
    }

    while (i <= mid)
    {
        output[k++] = arr[i++];
    }

    while (j <= ei)
    {
        output[k++] = arr[j++];
    }
    int m = 0;
    // copy output array into original array
    for (int i = si; i <= ei; i++)
    {
        arr[i] = output[m];
        m++;
    }
    delete[] output;
}

void mergeSort(int arr[], int l, int r)
{
    // base case
    if (l >= r)
    {
        return;
    }

    int mid = l + (r - l) / 2;

    // mergeSort on left part
    mergeSort(arr, l, mid);

    // mergeSort on right part
    mergeSort(arr, mid + 1, r);

    // merge both parts
    merge(arr, l, mid, r);
}