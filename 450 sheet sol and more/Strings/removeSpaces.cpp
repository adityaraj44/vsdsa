string modify(string s)
{
    string res = "";
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] != ' ')
        {
            res += s[i];
        }
    }
    return res;
}