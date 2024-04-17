bool knows(vector<vector<int>> &M, int a, int b, int n)
{
    if (M[a][b] == 1)
        return true;
    else
        return false;
}

public:
// Function to find if there is a celebrity in the party or not.
int celebrity(vector<vector<int>> &M, int n)
{
    stack<int> s;

    // step 1: Pushing each element in stack
    for (int i = 0; i < n; i++)
    {
        s.push(i);
    }

    // step 2: Taking out 2 elements and compairing them for the potential celebrity
    while (s.size() > 1)
    {

        int a = s.top();
        s.pop();

        int b = s.top();
        s.pop();

        if (knows(M, a, b, n))
        { // if a knows b -> remove (a), push back (b)
            s.push(b);
        }
        else
        {
            s.push(a); //// if b knows a -> remove (b), push back (a)
        }
    }

    int ans = s.top();

    // step 3: will check the potential celebrity by rows and columns

    int zeroCount = 0;

    for (int i = 0; i < n; i++)
    {
        if (M[ans][i] == 0)
            zeroCount++;
    }
    if (zeroCount != n)
    {
        return -1;
    }

    int oneCount = 0;
    for (int i = 0; i < n; i++)
    {
        if (M[i][ans] == 1)
            oneCount++;
    }
    if (oneCount != n - 1)
    { // Except Diagonal Element
        return -1;
    }

    return ans;
}