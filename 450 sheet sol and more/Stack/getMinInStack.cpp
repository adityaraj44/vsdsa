class SpecialStack
{
public:
    stack<int> s;
    int mini;
    void push(int data)
    {
        if (s.empty())
        {
            s.push(data);
            mini = data;
        }
        else
        {
            if (data < mini)
            {
                // create a mask for mini value that comes before data
                int val = 2 * data - mini;
                s.push(val);
                mini = data;
            }
            else
            {
                s.push(data);
            }
        }
    }

    void pop()
    {
        if (s.empty())
        {
            return;
        }
        int curr = s.top();
        s.pop();
        if (curr > mini)
        {
            return;
        }
        else
        {
            // obtain previous mini which was before
            int val = 2 * mini - curr;
            mini = val;
        }
    }

    int top()
    {
        if (s.empty())
        {
            return -1;
        }
        int curr = s.top();
        if (curr < mini)
        {
            return mini;
        }
        else
            return curr;
    }

    int getMin()
    {
        if (s.empty())
        {
            return -1;
        }
        else
            return mini;
    }
};