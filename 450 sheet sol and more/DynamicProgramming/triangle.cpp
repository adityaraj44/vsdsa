// recursive memo
class Solution
{
public:
    int solve(int i, int j, vector<vector<int>> &triangle, int n, vector<vector<int>> &t)
    {
        if (i == n - 1)
            return triangle[i][j];
        if (i < 0 || j < 0)
            return 0;
        if (t[i][j] != -1)
        {
            return t[i][j];
        }
        int b = triangle[i][j] + solve(i + 1, j, triangle, n, t);
        int b_r = triangle[i][j] + solve(i + 1, j + 1, triangle, n, t);
        return t[i][j] = min(b, b_r);
    }
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        vector<vector<int>> t(n, vector<int>(n, -1));
        return solve(0, 0, triangle, n, t);
    }
};

// tabulation
class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        vector<vector<int>> t(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            t[n - 1][i] = triangle[n - 1][i];
        }
        // already done for the last row
        for (int i = n - 2; i >= 0; i--)
        {
            // here i tells the number of elements in its row so j = i
            for (int j = i; j >= 0; j--)
            {
                t[i][j] = triangle[i][j] + min(t[i + 1][j], t[i + 1][j + 1]);
            }
        }
        return t[0][0];
    }
};

// space optimisaiton
class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        vector<int> front(n, 0);
        for (int i = 0; i < n; i++)
        {
            front[i] = triangle[n - 1][i];
        }
        // already done for the last row
        for (int i = n - 2; i >= 0; i--)
        {
            vector<int> curr(n, 0);
            // here i tells the number of elements in its row so j = i
            for (int j = i; j >= 0; j--)
            {
                curr[j] = triangle[i][j] + min(front[j], front[j + 1]);
            }
            front = curr;
        }
        return front[0];
    }
};