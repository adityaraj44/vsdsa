class Queue
{
    int *arr;
    int size;
    int qfront;
    int rear;

public:
    Queue()
    {
        size = 1000001;
        arr = new int[size];
        qfront = 0;
        rear = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty()
    {
        // Implement the isEmpty() function
        if (qfront == rear)
        {
            return true;
        }
        else
            return false;
    }

    void enqueue(int data)
    {
        // check if queue is full
        if (rear == size)
        {
            return;
        }
        else
        {
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue()
    {
        // front equal to rear
        if (qfront == rear)
        {
            return -1;
        }
        else
        {
            int ans = arr[qfront];
            arr[qfront] = -1;
            qfront++;
            if (qfront == rear)
            {
                qfront = 0;
                rear = 0;
            }
            return ans;
        }
    }

    int front()
    {
        // Implement the front() function
        if (qfront == rear)
            return -1;
        else
            return arr[qfront];
    }
};