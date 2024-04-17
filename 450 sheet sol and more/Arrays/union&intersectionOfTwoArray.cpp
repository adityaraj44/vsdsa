int NumberofElementsInIntersection(int a[], int b[], int n, int m)
{
    unordered_map<int, int> mp;
    int count = 0;
    for (int i = 0; i < n; i++)
        mp[a[i]]++;
    for (int i = 0; i < m; i++)
    {
        if (mp.find(b[i]) != mp.end() && mp[b[i]] != 0)
        {
            count++;
            mp[b[i]] = 0;
        }
    }
    return count;
}

 int doUnion(int a[], int n, int b[], int m)  {
        unordered_map<int,int> mp;
        for(int i = 0; i < n; ++i) {
            mp[a[i]]++;
        }
        
        for(int i = 0; i < m; ++i) {
            mp[b[i]]++;
        }
        return mp.size();
    }