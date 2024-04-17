int length(string str)
{
    int count = 0;
    for (int i = 0; str[i] != '\0'; ++i)
    {
        count++;
    }
    return count;
}

string reverseWord(string str)
{
    int count = length(str);
    int start = 0;
    int end = count - 1;

    while (start < end)
    {
        swap(str[start++], str[end--]);
    }
    return str;
}