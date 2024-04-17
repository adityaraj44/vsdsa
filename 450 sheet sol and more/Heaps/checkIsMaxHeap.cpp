bool isMaxHeap(int a[], int n)
{
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        if (a[2 * i + 1] > a[i])
            return false;

        if (a[2 * i + 2] > a[i])
            return false;
    }
    return true;
}