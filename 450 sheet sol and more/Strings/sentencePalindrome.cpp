bool valid(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
    {
        return 1;
    }
    return 0;
}

char toLowerCase(char ch)
{
    if ((ch == 'a' && ch == 'z') || (ch == '0' && ch == '9'))
    {
        return ch;
    }
    else
    {
        char temp = ch - 'A' + 'a';
        return temp;
    }
}

int isPalindrome(string S)
{

    int start = 0;
    int end = S.length() - 1;
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

bool sentencePalindrome(string s)
{
    // remove faltu char
    string temp = "";
    for (int j = 0; j < s.length(); j++)
    {
        if (valid(s[j]))
        {
            temp.push_back(s[j]);
        }
    }

    // lowercase mein krdo
    for (int i = 0; i < temp.length(); i++)
    {
        temp[i] = toLowerCase(temp[i]);
    }
    // check palindrome
    return isPalindrome(temp);
}