// using queue
vector<int> rearrangeQueue(queue<int> &q)
{
    // using queue
    vector<int> ans;
    queue<int> newQ;
    int size = q.size();
    int i = 0;
    while (i < size / 2)
    {
        int front = q.front();
        q.pop();
        newQ.push(front);
        i++;
    }

    while (!newQ.empty())
    {
        int front = newQ.front();
        newQ.pop();
        q.push(front);
        ans.push_back(front);
        front = q.front();
        q.pop();
        q.push(front);
        ans.push_back(front);
    }

    return ans;
}

// using stack
vector<int> rearrangeQueue(queue<int> &q)
{
    // using queue
    vector<int> ans;
    stack<int> st;
    int size = q.size();
    int i = 0;

    while (i < size / 2)
    {
        st.push(q.front());
        q.pop();
        i++;
    }

    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }

    i = 0;
    while (i < size / 2)
    {
        q.push(q.front());
        q.pop();
        i++;
    }

    i = 0;
    while (i < size / 2)
    {
        st.push(q.front());
        q.pop();
        i++;
    }

    while (!st.empty())
    {
        q.push(st.top());
        ans.push_back(st.top());
        st.pop();
        q.push(q.front());
        ans.push_back(q.front());
        q.pop();
    }

    return ans;
}