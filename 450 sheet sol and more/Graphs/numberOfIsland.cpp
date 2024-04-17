void bfs(int row, int col, vector<vector<int>> &visited, vector<vector<char>> &grid)
{
    visited[row][col] = 1;
    queue<pair<int, int>> q;
    q.push({row, col});
    while (!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        // traverse the neighbours in 8 directions
        for (int delrow = -1; delrow <= 1; delrow++)
        {
            for (int delcol = -1; delcol <= 1; delcol++)
            {
                int nRow = row + delrow;
                int nCol = col + delcol;
                if (nRow >= 0 && nRow < grid.size() && nCol >= 0 && nCol < grid[0].size() && grid[nRow][nCol] == '1' && !visited[nRow][nCol])
                {
                    visited[nRow][nCol] = 1;
                    q.push({nRow, nCol});
                }
            }
        }
    }
}

// Function to find the number of islands.
int numIslands(vector<vector<char>> &grid)
{
    // Code here
    int n = grid.size();
    int m = grid[0].size();
    int count = 0;
    vector<vector<int>> visited(n, vector<int>(m, 0));
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < m; col++)
        {
            if (!visited[row][col] && grid[row][col] == '1')
            {
                count++;
                bfs(row, col, visited, grid);
            }
        }
    }
    return count++;
}