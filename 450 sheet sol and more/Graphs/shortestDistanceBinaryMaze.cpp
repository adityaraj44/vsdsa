class Solution
{
public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination)
    {
        // implementing dijkstra approach
        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> distance(n, vector<int>(m, 1e9));

        distance[source.first][source.second] = 0;
        q.push({0, {source.first, source.second}});

        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            int row = it.second.first;
            int col = it.second.second;
            int dis = it.first;
            if (row == destination.first && col == destination.second)
                return dis;

            for (int i = 0; i < 4; i++)
            {
                int n_row = row + dr[i];
                int n_col = col + dc[i];
                if (n_row < n && n_row >= 0 && n_col < m && n_col >= 0 && grid[n_row][n_col] == 1 && dis + 1 < distance[n_row][n_col])
                {
                    distance[n_row][n_col] = 1 + dis;
                    q.push({1 + dis, {n_row, n_col}});
                }
            }
        }
        return -1;
    }
};