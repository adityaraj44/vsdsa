char *reverse(char *S, int len)
{
    stack<char> st;
    char *rev = new char[len];
    for (int i = 0; i < len; i++)
    {
        st.push(S[i]);
    }
    int i = 0;
    while (!st.empty())
    {
        rev[i] = st.top();
        i++;
        st.pop();
    }

    return rev;
}