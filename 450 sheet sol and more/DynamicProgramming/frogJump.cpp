#include <bits/stdc++.h>
int frogJump(int n, vector<int> &heights)
{
    vector<int> t(n, -1);
    t[0] = 0;

    for (int i = 1; i < n; i++)
    {
        if (i <= 1)
        {
            t[i] = min(t[i - 1] + abs(heights[i] - heights[i - 1]), INT_MAX);
        }
        else
        {
            t[i] = min((t[i - 1] + abs(heights[i] - heights[i - 1])), (t[i - 2] + abs(heights[i] - heights[i - 2])));
        }
    }
    return t[n - 1];
}

// sc opti
#include <bits/stdc++.h>
int frogJump(int n, vector<int> &heights)
{

    int prev2 = INT_MAX;
    int prev1 = 0;
    int curr;

    for (int i = 1; i < n; i++)
    {
        if (i <= 1)
        {
            curr = min(prev1 + abs(heights[i] - heights[i - 1]), prev2);
        }
        else
        {
            curr = min((prev1 + abs(heights[i] - heights[i - 1])), (prev2 + abs(heights[i] - heights[i - 2])));
        }
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}