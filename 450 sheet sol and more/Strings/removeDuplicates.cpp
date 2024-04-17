string removeDuplicates(string str)
{
    string ans = "";
    unordered_map<char, bool> mp;
    int i = 0;

    while (i < str.size())
    {
        if (mp[str[i]] == false)
        {
            ans += str[i];
            mp[str[i]] = true;
        }
        else
        {

            i++;
        }
    }

    return ans;
}