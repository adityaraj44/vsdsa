string reverseWords(string s)
{
    // code here.
    string s1 = "";
    int n = s.length();
    stack<char> st;
    for (int i = 0; i < n; i++)
    {
        char ch = s[i];
        if (s[i] != '.')
        {
            st.push(s[i]);
        }
        else
        {
            while (!st.empty())
            {
                s1 += st.top();
                st.pop();
            }
            s1 += s[i];
        }
    }
    while (!st.empty())
    {
        s1 += st.top();
        st.pop();
    }
    return s1;
}