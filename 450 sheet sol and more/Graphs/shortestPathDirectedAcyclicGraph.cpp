#include <bits/stdc++.h>

void dfsTopo(int node, unordered_map<int, list<pair<int, int>>> &adj,
             unordered_map<int, bool> &visited, stack<int> &s)
{
    visited[node] = 1;
    for (auto i : adj[node])
    {
        if (!visited[i.first])
        {
            dfsTopo(i.first, adj, visited, s);
        }
    }
    s.push(node);
}

vector<int> shortestPathInDAG(int n, int m, vector<vector<int>> &edges)
{
    unordered_map<int, list<pair<int, int>>> adj;
    for (auto i : edges)
    {
        int u = i[0];
        pair<int, int> p = make_pair(i[1], i[2]);
        adj[u].push_back(p);
    }
    unordered_map<int, bool> visited;

    // get topo order
    stack<int> s;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfsTopo(i, adj, visited, s);
        }
    }

    vector<int> distance(n, INT_MAX);

    int src = 0;
    distance[src] = 0;
    while (!s.empty())
    {
        int top = s.top();
        s.pop();

        if (distance[top] != INT_MAX)
        {
            for (auto i : adj[top])
            {
                if (distance[top] + i.second < distance[i.first])
                {
                    distance[i.first] = distance[top] + i.second;
                }
            }
        }
    }

    for (auto &i : distance)
    {
        if (i == INT_MAX)
            i = -1;
    }

    return distance;
}
