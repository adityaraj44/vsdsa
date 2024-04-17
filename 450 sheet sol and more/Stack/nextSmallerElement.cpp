/*
    Here first element of stack is given -1 because we are traversing the array from end and end element's next smaller is -1;

    Check is top of stack is smaller than the curr array element. If it is then ans[i] = s.top() else pop the stack unless a smaller element appears at the top.
*/

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i];
        while (s.top() != -1 && s.top() >= curr)
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(curr);
    }
    return ans;
}