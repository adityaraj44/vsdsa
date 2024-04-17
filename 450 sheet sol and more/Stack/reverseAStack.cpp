void insertAtBottom(stack<int> &st, int x)
{
    if (st.empty())
    {
        st.push(x);
        return;
    }

    int num = st.top();
    st.pop();

    insertAtBottom(st, x);

    st.push(num);
}

void Reverse(stack<int> &St)
{
    if (St.empty())
    {
        return;
    }

    int num = St.top();
    St.pop();

    Reverse(St);

    insertAtBottom(St, num);
}