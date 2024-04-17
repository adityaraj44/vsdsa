#include <bits/stdc++.h>

void topoSort(int node, vector<bool> &visited, unordered_map<int, list<int>> &adj,
              stack<int> &s)
{
    visited[node] = 1;
    for (auto i : adj[node])
    {
        if (!visited[i])
        {
            topoSort(i, visited, adj, s);
        }
    }

    s.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
    unordered_map<int, list<int>> adj;
    vector<bool> visited(v);

    for (int i = 0; i < e; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }

    stack<int> s;
    // call dfs topological sortutil for all components
    for (int i = 0; i < v; i++)
    {

        if (!visited[i])
        {
            topoSort(i, visited, adj, s);
        }
    }

    vector<int> ans;
    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}