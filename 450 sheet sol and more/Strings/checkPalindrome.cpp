int isPalindrome(string S)
{
    int count = 0;
    for (int i = 0; S[i] != '\0'; ++i)
    {
        count++;
    }

    int start = 0;
    int end = count - 1;
    while (start <= end)
    {
        if (S[start] == S[end])
        {
            start++;
            end--;
        }
        else
            return 0;
    }
    return 1;
}
// recursive
bool check(string s, int start, int end)
{

    if (start > end)
    {
        return 1;
    }
    if (s[start] != s[end])
    {
        return 0;
    }
    else
    {
        return check(s, start + 1, end - 1);
    }
}

int isPalindrome(string S)
{
    return check(S, 0, S.length() - 1);
}