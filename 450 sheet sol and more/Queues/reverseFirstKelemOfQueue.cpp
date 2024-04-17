queue<int> reverseElements(queue<int> q, int k)
{
    // Write your code here.
    if (k == 0)
    {
        return q;
    }
    int count = 0;
    stack<int> st;
    while (count < k && !q.empty())
    {
        int elem = q.front();
        q.pop();
        st.push(elem);
        count++;
    }

    while (!st.empty())
    {
        int top = st.top();
        st.pop();
        q.push(top);
    }

    int n = q.size() - k;
    while (n--)
    {
        int elem = q.front();
        q.pop();
        q.push(elem);
    }
    return q;
}