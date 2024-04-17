
void heapify(vector<int> &arr, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[largest] < arr[left])
    {
        largest = left;
    }
    if (right < n && arr[largest] < arr[right])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

vector<int> mergeHeap(int n, int m, vector<int> &arr1, vector<int> &arr2)
{
    vector<int> arr;
    for (auto i : arr1)
    {
        arr.push_back(i);
    }
    for (auto i : arr2)
    {
        arr.push_back(i);
    }
    int s = arr.size();
    for (int i = (s / 2) - 1; i >= 0; i--)
    {
        heapify(arr, s, i);
    }
    return arr;
}