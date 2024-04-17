class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++)
        {
            m[nums[i]]++;
        }
        priority_queue<pair<int, int>> pq;
        for (auto it : m)
        {

            pq.push({it.second, it.first});
        }
        vector<int> v;
        while (k--)
        {
            pair<int, int> num;
            num = pq.top();
            v.push_back(num.second);
            pq.pop();
        }
        return v;
    }
};