queue<int> rev(queue<int> q)
{
    stack<int> s;
    while (!q.empty())
    {
        s.push(q.front());
        q.pop();
    }
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
    return q;
}

// recursive
void reverse(queue<int> &q) {
    if(q.empty()) {
        return;
    }
    int data = q.front();
    q.pop();
    reverse(q);
    q.push(data);
}

queue<int> reverseQueue(queue<int> q)
{
    revese(q);
    return q;
}
