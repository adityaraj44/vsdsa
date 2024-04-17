int findMinimumCost(string str)
{
    if (str.length() % 2 != 0)
    {
        return -1;
    }

    stack<char> s;
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        if (ch == '{')
        {
            s.push(ch);
        }
        else
        {
            // ch is closed brace
            if (!s.empty() && s.top() == '{')
            {

                s.pop();
            }
            else
            {
                s.push(ch);
            }
        }
    }

    // stack contains invalid exp
    int a = 0;
    int b = 0;
    while (!s.empty())
    {
        if (s.top() == '{')
        {
            a++;
        }
        else
        {
            b++;
        }
        s.pop();
    }

    int ans = (a + 1) / 2 + (b + 1) / 2;

    return ans;
}