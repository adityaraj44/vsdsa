class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        int n = numRows;
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++)
        {
            ans.push_back({});
            ans[i].push_back(1);
        }

        for (int row = 1; row < n; row++)
        {
            for (int col = 1; col <= row; col++)
            {
                if (row == col)
                {
                    // if last col of the row
                    ans[row].push_back(1);
                }
                else
                {
                    ans[row].push_back(ans[row - 1][col - 1] + ans[row - 1][col]);
                }
            }
        }
        return ans;
    }
};