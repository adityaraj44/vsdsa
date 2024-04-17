string replaceSpaces(string &str)
{
    string res = "";
    for (int i = 0; i < str.length(); ++i)
    {
        if (str[i] == ' ')
        {
            res += '@';
            res += '4';
            res += '0';
        }
        else
        {
            res += str[i];
        }
    }
    return res;
}