vector<string> findRelativeRanks(vector<int> &score)
{
    priority_queue<pair<int, int>> maxHeap;

    int size = score.size();
    for (int i = 0; i < size; i++)
    {
        maxHeap.push({score[i], i});
    }
    vector<string> ans(size, "-1");
    int i = 0;
    while (maxHeap.size() > 0)
    {
        int index = maxHeap.top().second;
        maxHeap.pop();
        if (i == 0)
        {
            ans[index] = "Gold Medal";
        }
        else if (i == 1)
        {
            ans[index] = "Silver Medal";
        }
        else if (i == 2)
        {
            ans[index] = "Bronze Medal";
        }
        else
            ans[index] = to_string(i + 1);
        i++;
    }
    return ans;
}