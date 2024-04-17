void sort012(int a[], int n)
{
    int l = 0;
    int m = 0;
    int h = n - 1;
    while (l <= m && m <= h)
    {
        if (a[m] == 0)
        {
            swap(a[m], a[l]);
            m++;
            l++;
        }
        else if (a[m] == 2)
        {
            swap(a[m], a[h]);
            h--;
        }
        else
        {
            m++;
        }
    }
}