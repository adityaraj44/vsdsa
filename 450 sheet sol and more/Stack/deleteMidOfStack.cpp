void solve(stack<int> &s, int size, int count)
{
    // base case
    if (count == size / 2)
    {
        s.pop();
        return;
    }

    int num = s.top();
    s.pop();

    // resursive call
    solve(s, size, count + 1);

    // push remaning num
    s.push(num);
}

// Function to delete middle element of a stack.
void deleteMid(stack<int> &s, int sizeOfStack)
{
    int count = 0;
    solve(s, sizeOfStack, count);
}