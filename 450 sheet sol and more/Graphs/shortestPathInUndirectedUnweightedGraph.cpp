#include <bits/stdc++.h>

vector<int> shortestPath(vector<pair<int, int>> edges, int n, int m, int s, int t)
{

    // create adj list
    unordered_map<int, list<int>> adj;
    for (auto i : edges)
    {
        int u = i.first;
        int v = i.second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // visited
    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;

    queue<int> q;
    q.push(s);
    visited[s] = 1;
    parent[s] = -1;

    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        for (auto i : adj[front])
        {
            if (!visited[i])
            {
                visited[i] = 1;
                parent[i] = front;
                q.push(i);
            }
        }
    }

    // shortest path from parent map
    vector<int> output;
    int curr = t;
    output.push_back(t);
    while (curr != s)
    {
        curr = parent[curr];
        output.push_back(curr);
    }
    reverse(output.begin(), output.end());
    return output;
}
