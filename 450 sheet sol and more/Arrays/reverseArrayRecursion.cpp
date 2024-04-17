void reverseArray(int arr[], int a, int b)
{
    if (a >= b)
    {
        return;
    }

    // a temporary variable to store the value to be swapped
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;

    // recursivvely call the function with start ++ and end --
    reverseArray(arr, a + 1, b - 1);
}