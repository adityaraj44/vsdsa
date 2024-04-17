class Queue
{
    stack<int> input, output;

public:
    void enqueue(int x)
    {
        input.push(x);
    }

    int dequeue()
    {
        if (output.empty() && input.empty())
        {
            return -1;
        }
        else if (output.empty())
        {
            while (!input.empty())
            {
                int top = input.top();
                output.push(top);
                input.pop();
            }
            int top = output.top();
            output.pop();
            return top;
        }
        else
        {
            int top = output.top();
            output.pop();
            return top;
        }
    }
};