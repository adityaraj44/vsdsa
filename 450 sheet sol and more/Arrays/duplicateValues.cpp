int findDuplicate(vector<int> &nums)
{
    unordered_map<int, int> mp;
    for (auto i : nums)
    {
        mp[i]++;
    }
    int res;
    int max = INT_MIN;
    for (auto i : mp)
    {
        if (i.second > max)
        {
            res = i.first;
            max = i.second;
        }
    }
    return res;
}