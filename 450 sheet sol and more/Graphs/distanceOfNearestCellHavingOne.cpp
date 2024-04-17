vector<vector<int>> nearest(vector<vector<int>> grid)
{
    int n = grid.size();
    int m = grid[0].size();

    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};

    vector<vector<int>> visited(n, vector<int>(m, 0));
    vector<vector<int>> finalD(n, vector<int>(m, 0));

    queue<pair<int, pair<int, int>>> q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {
                q.push({0, {i, j}});
                visited[i][j] = 1;
            }
        }
    }

    while (!q.empty())
    {
        int dist = q.front().first;
        int row = q.front().second.first;
        int col = q.front().second.second;
        q.pop();

        finalD[row][col] = dist;

        for (int i = 0; i < 4; i++)
        {
            int nRow = row + dr[i];
            int nCol = col + dc[i];
            if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m &&
                visited[nRow][nCol] == 0)
            {
                q.push({dist + 1, {nRow, nCol}});
                visited[nRow][nCol] = 1;
            }
        }
    }

    return finalD;
}