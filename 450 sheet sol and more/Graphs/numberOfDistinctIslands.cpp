int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, -1, 0, 1};
void dfs(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &visited,
         vector<pair<int, int>> &vec, int row0, int col0)
{
    visited[row][col] = 1;
    vec.push_back({row - row0, col - col0});

    for (int i = 0; i < 4; i++)
    {
        int nRow = row + dr[i];
        int nCol = col + dc[i];
        if (nRow >= 0 && nRow < grid.size() && nCol >= 0 && nCol < grid[0].size() && !visited[nRow][nCol] && grid[nRow][nCol] == 1)
        {
            dfs(nRow, nCol, grid, visited, vec, row0, col0);
        }
    }
}
int countDistinctIslands(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> visited(n, vector<int>(m, 0));
    set<vector<pair<int, int>>> st;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j] && grid[i][j] == 1)
            {
                vector<pair<int, int>> vec;
                dfs(i, j, grid, visited, vec, i, j);
                st.insert(vec);
            }
        }
    }
    return st.size();
}