void reverse(string &s, int start, int end)
{
    if (start > end)
    {
        return;
    }
    swap(s[start], s[end]);
    reverse(s, start + 1, end - 1);
}

string reverseWord(string str)
{
    int start = 0;
    int end = str.length() - 1;

    reverse(str, start, end);
    return str;
}