class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> m;
        vector<int> v;
        for (int i = 0; i < nums.size(); i++)
        {
            auto it = m.find(nums[i]);
            if (it != m.end())
            {
                v.push_back(it->second);
                v.push_back(i);
                return v;
            }
            m.insert({target - nums[i], i});
        }
        return v;
    }
};