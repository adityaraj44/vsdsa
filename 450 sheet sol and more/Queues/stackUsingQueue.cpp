class MyStack
{
public:
    queue<int> q1;
    queue<int> q2;
    MyStack() {}

    void push(int x)
    {
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }

        q1.push(x);

        while (!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
    }

    int pop()
    {
        if (q1.empty())
        {
            return -1;
        }
        else
        {
            int val = q1.front();
            q1.pop();
            return val;
        }
    }

    int top()
    {
        if (q1.empty())
        {
            return -1;
        }
        else
        {
            int val = q1.front();

            return val;
        }
    }

    bool empty()
    {
        if (q1.empty())
        {
            return true;
        }
        else
            return false;
    }
};