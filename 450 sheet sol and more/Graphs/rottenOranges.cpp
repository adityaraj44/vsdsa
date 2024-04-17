int orangesRotting(vector<vector<int>> &grid)
{
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, -1, 0, 1};
    int n = grid.size();
    int m = grid[0].size();
    int maxTime = 0;
    int cntFresh = 0;
    queue<pair<int, pair<int, int>>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 2)
            {
                q.push({0, {i, j}});
            }
            if (grid[i][j] == 1)
            {
                cntFresh++;
            }
        }
    }
    int cnt = 0;
    while (!q.empty())
    {
        int row = q.front().second.first;
        int col = q.front().second.second;
        int ct = q.front().first;
        q.pop();
        maxTime = max(maxTime, ct);
        for (int i = 0; i < 4; i++)
        {
            int nRow = row + dr[i];
            int nCol = col + dc[i];
            if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m &&
                grid[nRow][nCol] == 1 && grid[nRow][nCol] != 2)
            {
                grid[nRow][nCol] = 2;
                cnt++;
                q.push({ct + 1, {nRow, nCol}});
            }
        }
    }
    if (cnt != cntFresh)
        return -1;
    return maxTime;
}