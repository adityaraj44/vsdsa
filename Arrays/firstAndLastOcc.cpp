int firstOcc(vector<long long> &v, long long x)
{
    int s = 0;
    int e = v.size() - 1;
    int mid = s + (e - s) / 2;
    int ans = -1;
    while (s <= e)
    {
        if (v[mid] == x)
        {
            ans = mid;
            e = mid - 1;
        }
        else if (v[mid] < x)
        {
            s = mid + 1;
        }
        else if (v[mid] > x)
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

int lastOcc(vector<long long> &v, long long x)
{
    int s = 0;
    int e = v.size() - 1;
    int mid = s + (e - s) / 2;
    int ans = -1;
    while (s <= e)
    {
        if (v[mid] == x)
        {
            ans = mid;
            s = mid + 1;
        }
        else if (v[mid] < x)
        {
            s = mid + 1;
        }
        else if (v[mid] > x)
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

pair<long, long> indexes(vector<long long> v, long long x)
{
    return {firstOcc(v, x), lastOcc(v, x)};
}