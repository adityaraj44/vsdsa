vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
{
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, -1, 0, 1};
    queue<pair<int, int>> q;
    q.push({sr, sc});
    int ini = image[sr][sc];
    int n = image.size();
    int m = image[0].size();
    image[sr][sc] = newColor;
    while (!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nRow = row + dr[i];
            int nCol = col + dc[i];
            if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && image[nRow][nCol] == ini && image[nRow][nCol] != newColor)
            {
                q.push({nRow, nCol});
                image[nRow][nCol] = newColor;
            }
        }
    }
    return image;
}