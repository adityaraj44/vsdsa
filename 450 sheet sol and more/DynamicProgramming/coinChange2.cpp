class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        vector<vector<int>> t(coins.size() + 1, vector<int>(amount + 1, 0));
        for (int i = 0; i < amount + 1; i++)
        {
            t[0][i] = 0;
        }
        for (int i = 0; i < coins.size() + 1; i++)
        {
            t[i][0] = 1;
        }
        for (int i = 1; i < coins.size() + 1; i++)
        {
            for (int j = 0; j < amount + 1; j++)
            {
                if (coins[i - 1] <= j)
                {
                    t[i][j] = t[i][j - coins[i - 1]] + t[i - 1][j];
                }
                else
                {
                    t[i][j] = t[i - 1][j];
                }
            }
        }
        return t[coins.size()][amount];
    }
};