class Solution
{

public:
    int rob_util(vector<int> &arr1)
    {
        int n = arr1.size();
        int prev1 = arr1[0];
        int prev2 = 0;
        int curr;
        for (int i = 1; i < n; i++)
        {
            if (i <= 1)
            {
                curr = max(arr1[i], prev1);
            }
            else
            {
                curr = max(arr1[i] + prev2, prev1);
            }
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];
        vector<int> temp1, temp2;
        for (int i = 0; i < n; i++)
        {
            if (i != 0)
                temp1.push_back(nums[i]);
            if (i != n - 1)
                temp2.push_back(nums[i]);
        }
        return max(rob_util(temp1), rob_util(temp2));
    }
};