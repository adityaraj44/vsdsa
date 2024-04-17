class Solution
{
public:
    int util(int n, int t[])
    {
        if (n <= 2)
        {
            return n;
        }
        if (t[n] != -1)
        {
            return t[n];
        }
        return t[n] = util(n - 1, t) + util(n - 2, t);
    }
    int climbStairs(int n)
    {
        int t[n + 1];
        memset(t, -1, sizeof(t));
        return util(n, t);
    }
};