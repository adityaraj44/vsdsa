#include <bits/stdc++.h>

void heapify(vector<int> &arr, int n, int i)
{
    int largest = i;
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;
    if (leftChild < n && arr[largest] < arr[leftChild])
    {
        largest = leftChild;
    }
    if (rightChild < n && arr[largest] < arr[rightChild])
    {
        largest = rightChild;
    }
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

vector<int> heapSort(vector<int> &arr, int n)
{
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i >= 0; i--)
    {

        swap(arr[i], arr[0]);

        heapify(arr, i, 0);
    }
    return arr;
}