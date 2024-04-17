// using bfs
#include <bits/stdc++.h>

bool isCyclicBFS(int node, unordered_map<int, bool> &visited,
                 unordered_map<int, list<int>> &adj)
{
    queue<int> q;
    unordered_map<int, int> parent;
    parent[node] = -1;
    visited[node] = 1;
    q.push(node);

    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();

        for (auto i : adj[frontNode])
        {
            if (visited[i] == true && i != parent[frontNode])
            {
                return true;
            }
            else if (!visited[i])
            {
                q.push(i);
                visited[i] = 1;
                parent[i] = frontNode;
            }
        }
    }
    return false;
}

string cycleDetection(vector<vector<int>> &edges, int n, int m)
{
    // create adjacency list
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // visited track
    unordered_map<int, bool> visited;

    // to handle disconnected components
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            bool ans = isCyclicBFS(i, visited, adj);
            if (ans == true)
            {
                return "Yes";
            }
        }
    }
    return "No";
}

// using dfs

bool isCyclicDFS(int node, int parent, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj)
{
    visited[node] = 1;

    for (auto i : adj[node])
    {
        if (!visited[i])
        {
            bool cycleDetected = isCyclicDFS(i, node, visited, adj);
            if (cycleDetected)
            {
                return true;
            }
        }
        else if (i != parent)
        {
            // cycle present
            return true;
        }
    }
    return false;
}
string cycleDetection(vector<vector<int>> &edges, int n, int m)
{
    // create adjacency list
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // visited track
    unordered_map<int, bool> visited;

    // to handle disconnected components
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            bool ans = isCyclicDFS(i, -1, visited, adj);
            if (ans == true)
            {
                return "Yes";
            }
        }
    }
    return "No";
}
