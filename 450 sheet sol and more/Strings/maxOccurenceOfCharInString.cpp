char getMaxOccuringChar(string str)
{
    unordered_map<char, int> mp;
    for (int i = 0; i < str.length(); i++)
    {
        mp[str[i]]++;
    }
    char res;
    int max = INT_MIN;
    for (auto i : mp)
    {
        if (i.second > max)
        {
            res = i.first;
            max = i.second;
        }
        else if (i.second == max)
        {
            if (res > i.first)
            {
                res = i.first;
            }
        }
    }
    return res;
}