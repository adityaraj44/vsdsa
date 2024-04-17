string removeDuplicates(string s)
{
    string new_str;
    int i = 0;
    int flag = 0;
    while (i < s.size())
    {
        if (s[i] == s[i + 1])
        {
            while (s[i] == s[i + 1])
            {
                i++;
                flag = 1;
            }
        }
        else
            new_str += s[i];
        i++;
    }

    if (flag != 0)
        return removeDuplicates(new_str);
    return new_str;
}