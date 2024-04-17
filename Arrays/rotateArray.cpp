
void reverse(int arr[], int a, int b)
{
    while (a < b)
    {
        int temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
        a++;
        b--;
    }
}

void rotate(int arr[], int d, int n)
{

    d = d % n;

    // reverse first d
    reverse(arr, 0, d - 1);
    // reverse d - n
    reverse(arr, d, n - 1);
    // reverse all
    reverse(arr, 0, n - 1);
}