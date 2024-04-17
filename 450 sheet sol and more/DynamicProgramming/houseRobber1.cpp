// recursive
class Solution
{

public:
    int rob_util(vector<int> &nums, int index)
    {
        if (index == 0)
            return nums[0];
        if (index < 0)
            return 0;

        return max(nums[index] + rob_util(nums, index - 2), rob_util(nums, index - 1));
    }
    int rob(vector<int> &nums)
    {

        // recursive approach
        int n = nums.size();
        return rob_util(nums, n - 1);
    }
};

// top down (recursive + memo)
class Solution
{

public:
    int rob_util(vector<int> &nums, int index, vector<int> &t)
    {
        if (index == 0)
            return nums[0];
        if (index < 0)
            return 0;
        if (t[index] != -1)
            return t[index];
        return t[index] = max(nums[index] + rob_util(nums, index - 2, t), rob_util(nums, index - 1, t));
    }
    int rob(vector<int> &nums)
    {

        int n = nums.size();
        vector<int> t(n, -1);
        return rob_util(nums, n - 1, t);
    }
};

// bottom up (tabulation)
class Solution
{

public:
    int rob(vector<int> &nums)
    {

        int n = nums.size();
        vector<int> t(n, 0);
        t[0] = nums[0];

        for (int i = 1; i < n; i++)
        {
            if (i <= 1)
            {
                t[i] = max(nums[i], t[i - 1]);
            }
            else
            {
                t[i] = max(nums[i] + t[i - 2], t[i - 1]);
            }
        }
        return (t[n - 1]);
    }
};

// space optimised
class Solution
{

public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        int prev1 = nums[0];
        int prev2 = 0;
        int curr;
        for (int i = 1; i < n; i++)
        {
            if (i <= 1)
            {
                curr = max(nums[i], prev1);
            }
            else
            {
                curr = max(nums[i] + prev2, prev1);
            }
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};