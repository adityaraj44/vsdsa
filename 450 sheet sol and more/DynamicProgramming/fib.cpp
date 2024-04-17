class Solution
{
public:
    // top down approach
    // int util(int n, vector<int> &t) {
    //     if(n <= 1) {
    //         return n;
    //     }
    //     if(t[n] != -1) {
    //         return t[n];
    //     }
    //     return t[n] = util(n-1,t) + util(n-2,t);
    // }

    // bottom up
    int fib(int n)
    {
        if (n == 0)
            return 0;
        // vector<int> t(n+1, -1);
        // t[0] = 0;
        // t[1] = 1;
        // for(int i = 2; i <= n; i++) {
        //     t[i] = t[i-1] + t[i-2];
        // }
        // return t[n];
        // tabulation
        int prev1 = 1;
        int prev2 = 0;
        for (int i = 2; i <= n; i++)
        {
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};