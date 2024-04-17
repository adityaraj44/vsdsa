class Solution
{
public:
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, -1, 0, 1};
    void dfs(int row, int col, int n, int m, vector<vector<int>> &grid,
             vector<vector<int>> &visited)
    {
        visited[row][col] = 1;
        for (int i = 0; i < 4; i++)
        {
            int nRow = row + dr[i];
            int nCol = col + dc[i];
            if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && !visited[nRow][nCol] && grid[nRow][nCol] == 1)
            {
                dfs(nRow, nCol, n, m, grid, visited);
            }
        }
    }
    int numEnclaves(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == 0 || j == 0 || i == n - 1 || j == m - 1)
                {
                    if (grid[i][j] == 1)
                    {
                        dfs(i, j, n, m, grid, visited);
                    }
                }
            }
        }

        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!visited[i][j] && grid[i][j] != 0)
                {
                    count++;
                }
            }
        }
        return count;
    }
};