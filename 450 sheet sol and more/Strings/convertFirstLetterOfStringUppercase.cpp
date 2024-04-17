string convertString(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (i == 0 && str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = str[i] - 'a' + 'A';
        }
        if (str[i] == ' ')
        {
            if (str[i + 1] >= 'a' && str[i + 1] <= 'z')
            {
                str[i + 1] = str[i + 1] - 'a' + 'A';
            }
        }
    }
    return str;
}