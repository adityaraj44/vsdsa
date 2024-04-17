#include <bits/stdc++.h>

vector<int> bellmonFord(int n, int m, int src, vector<vector<int>> &edges)
{
    vector<int> dist(n + 1, 1e8);
    dist[src] = 0;

    // n-1 times
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];

            if (dist[u] != INT_MAX && ((dist[u] + w) < dist[v]))
            {
                dist[v] = dist[u] + w;
            }
        }
    }

    // check for negative cycle
    bool flag = 0;
    for (int j = 0; j < m; j++)
    {
        int u = edges[j][0];
        int v = edges[j][1];
        int w = edges[j][2];

        if (dist[u] != 1e8 && ((dist[u] + w) < dist[v]))
        {
            flag = 1;
        }
    }

    if (flag == 0)
        return dist;
}