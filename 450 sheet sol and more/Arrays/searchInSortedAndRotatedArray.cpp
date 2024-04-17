int getPivot(vector<int> vec)
{
    int s = 0;
    int e = vec.size() - 1;
    int mid = s + (e - s) / 2;

    while (s < e)
    {
        if (vec[mid] >= vec[0])
        {
            s = mid + 1;
        }
        else
        {
            e = mid;
        }
        mid = s + (e - s) / 2;
    }
    return s;
}
int binarySearch(vector<int> vec, int start, int end, int k)
{
    int mid = start + (end - start) / 2;

    while (start <= end)
    {

        if (k == vec[mid])
        {
            return mid;
        }
        if (k < vec[mid])
        {

            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }

        mid = start + (end - start) / 2;
    } 
    return -1;
}

int Search(vector<int> vec, int K)
{
    int pivot = getPivot(vec);
    if (K >= vec[pivot] && K <= vec[vec.size() - 1])
    {
        return binarySearch(vec, pivot, vec.size() - 1, K);
    }
    else
        return binarySearch(vec, 0, pivot, K);
}
