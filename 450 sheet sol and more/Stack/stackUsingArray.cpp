
void MyStack ::push(int x)
{
    // check stack overflow
    if (top == 1000)
    {
        return;
    }
    else
    {
        top++;
        arr[top] = x;
    }
}

// Function to remove an item from top of the stack.
int MyStack ::pop()
{
    if (top == -1)
    {
        return -1;
    }
    else
    {
        int ans = arr[top];
        top--;
        return ans;
    }
}